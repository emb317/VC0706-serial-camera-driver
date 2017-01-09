/*""FILE COMMENT""*************************************************************
* System Name	: Interrupt program for RX62Nx
* File Name		: Interrupt_IIC.c
* Version		: 1.11
* Contents		: Interrupt handlers for all IIC channels
* Customer		: 
* Model			: 
* Order			: 
* CPU			: RX
* Compiler		: RXC
* OS			: Nothing
* Programmer	: 
* Note			: 
*******************************************************************************
* Copyright, 2014. Renesas Electronics Corporation and Renesas Solutions Corp.
*******************************************************************************
* History		: 2014.07.16
*				: Ver 1.11
*				: CS release
*""FILE COMMENT END""*********************************************************/

#include "r_pdl_iic.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/* For DMAC support */
#define DMCNT_ADDRESS(a) ((volatile uint8_t __evenaccess *)&DMAC0.DMCNT + ((0x40u * a) / sizeof( uint8_t)) )
/* For DTC support*/
#define ICRXI_DTCER_ADDRESS(a) ( (volatile uint8_t __evenaccess *)&ICU.DTCER[DTCE_RIIC0_ICRXI0] + ((4 * a) / sizeof(uint8_t)) )
#define ICTXI_DTCER_ADDRESS(a) ( (volatile uint8_t __evenaccess *)&ICU.DTCER[DTCE_RIIC0_ICTXI0] + ((4 * a) / sizeof(uint8_t)) )
/*ICU IR Flags*/
#define	ICTXI_ADDRESS(a) ( (volatile uint8_t __evenaccess *)&ICU.IR[IR_RIIC0_ICTXI0] + ((4 * a) / sizeof(uint8_t)) )
#define	ICTEI_ADDRESS(a) ( (volatile uint8_t __evenaccess *)&ICU.IR[IR_RIIC0_ICTEI0] + ((4 * a) / sizeof(uint8_t)) )
/*ICU Priority level*/
#define	IPR_RX_ADDRESS(a) ( (volatile uint8_t __evenaccess *)&ICU.IPR[IPR_RIIC0_ICRXI0] + ((4 * a) / sizeof(uint8_t)) )

/* External functions */
extern void rpdl_IIC_Store_detected_address(const uint8_t);
extern void rpdl_IIC_DisableIEN(const uint8_t);
extern void rpdl_IIC_ModifyTx_IER(const uint8_t channel, const uint8_t value);

/*Non channel specific interrupt handlers.*/
static void Interrupt_IIC_ICEEI_Common(uint8_t channel,
								volatile __evenaccess struct st_riic* pIIC_IO);
static void Interrupt_IIC_ICRXI_Common(uint8_t channel,
								volatile __evenaccess struct st_riic* pIIC_IO);
static void Interrupt_IIC_ICTXI_Common(uint8_t channel,
								volatile __evenaccess struct st_riic* pIIC_IO);
static void Interrupt_IIC_ICTEI_Common(uint8_t channel,
								volatile __evenaccess struct st_riic* pIIC_IO);
								
/*""FUNC COMMENT""*************************************************************
* Module outline: IICn event interrupt processing
*------------------------------------------------------------------------------
* Declaration	: void InterruptIIC_ICEEIn(void)
*------------------------------------------------------------------------------
* Function		: 
*------------------------------------------------------------------------------
* Argument		: Nothing
*------------------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------------------
* Output		: 
*------------------------------------------------------------------------------
* Use function	: 
*------------------------------------------------------------------------------
* Notes			: 
*------------------------------------------------------------------------------
* History		: 2014.07.16
*				: Ver 1.11
*				: CS release
*""FUNC COMMENT END""*********************************************************/

#if FAST_INTC_VECTOR == VECT_RIIC0_ICEEI0
#pragma interrupt Interrupt_IIC_ICEEI0(vect=VECT_RIIC0_ICEEI0, fint)
#else
#pragma interrupt Interrupt_IIC_ICEEI0(vect=VECT_RIIC0_ICEEI0)
#endif
void Interrupt_IIC_ICEEI0(void)
{
	Interrupt_IIC_ICEEI_Common(0, (volatile __evenaccess struct st_riic*)&RIIC0);
}


#if FAST_INTC_VECTOR == VECT_RIIC1_ICEEI1
#pragma interrupt Interrupt_IIC_ICEEI1(vect=VECT_RIIC1_ICEEI1, fint)
#else
#pragma interrupt Interrupt_IIC_ICEEI1(vect=VECT_RIIC1_ICEEI1)
#endif
void Interrupt_IIC_ICEEI1(void)
{
#ifdef DEVICE_PACKAGE_LQFP_100
	/* This channel is not available on the 100-pin package */
	nop();
#else
	Interrupt_IIC_ICEEI_Common(1, (volatile __evenaccess struct st_riic*)&RIIC1);
#endif
}


/*ICEEI interrupt handler, not channel specific.*/
void Interrupt_IIC_ICEEI_Common(uint8_t channel,
								volatile __evenaccess struct st_riic* pIIC_IO)
{
	uint8_t valid_flags;
	volatile uint8_t unwanted_byte;
	
	/*If the time out function is in use this will reset the counter (TMOCNT = 0)*/
	rpdl_IIC_Reset_TimeOut_Counter(channel);
	/* Read the status register */
	valid_flags = pIIC_IO->ICSR2.BYTE;

	/* Remove any that are not enabled */
	valid_flags &= pIIC_IO->ICIER.BYTE;

	/* Remove the transmit and receive flags */
	valid_flags &= 0x1Fu;

	/* Start or Repeated Start detected? 
	NOTE: If both start and stop are set then it is because 
	a start has happened following the stop.
	In this case deal with the stop first.*/
	if ((valid_flags & (BIT_2 | BIT_3)) == BIT_2)
	{
		
		/*If in master mode?*/
		if(pIIC_IO->ICCR2.BIT.MST == 1)
		{	 
			/* Clear the Stop flag */
			pIIC_IO->ICSR2.BIT.STOP = 0;

			/* Enable Stop detection */
			pIIC_IO->ICIER.BIT.SPIE = 1;

			/* Decide what to send */
			switch (rpdl_IIC_next_state[channel])
			{
				case IIC_MASTER_SEND_SLAVE_ADDRESS_7:
					
					/*The Tx IR flag is set when the start is generated
					so clear it here so will only get TXI interrupt
					when ready to send first data byte.*/
					/*Clear the TX IR flag*/
					*ICTXI_ADDRESS(channel) = 0x0u;
					
					/* Send the slave address */
					pIIC_IO->ICDRT = rpdl_IIC_slave_address_lower[channel];

					/* Transmit mode? */
					if ((rpdl_IIC_slave_address_lower[channel] & BIT_0) == 0)
					{
						rpdl_IIC_current_state[channel] = IIC_MASTER_SEND_DATA;
					}
					else
					{
						rpdl_IIC_current_state[channel] = IIC_MASTER_START_READ;
					}
					break;
				case IIC_MASTER_SEND_SLAVE_ADDRESS_10a:
					rpdl_IIC_current_state[channel] = IIC_MASTER_SEND_SLAVE_ADDRESS_10b;

					/*Clear the TX IR flag (see note above)*/
					*ICTXI_ADDRESS(channel) = 0x0u;
					
					/* Transmit mode? */
					if ((rpdl_IIC_slave_address_upper[channel] & BIT_0) == 0)
					{
						/* Send the first part of the slave address */
						pIIC_IO->ICDRT = rpdl_IIC_slave_address_upper[channel];
					}
					else
					{
						rpdl_IIC_next_state[channel] = IIC_MASTER_SEND_SLAVE_ADDRESS_10d;
						
						/* Send the first part of the slave address with write flag */
						pIIC_IO->ICDRT = (uint8_t)(rpdl_IIC_slave_address_upper[channel] & 0xFE);
					}
					break;
				case IIC_MASTER_SEND_SLAVE_ADDRESS_10d:
					rpdl_IIC_current_state[channel] = IIC_MASTER_START_READ;
					
					/* Send the first part of the slave address with read flag */
					pIIC_IO->ICDRT = rpdl_IIC_slave_address_upper[channel];
					
					/* Enable receive interrupt request generation */
					pIIC_IO->ICIER.BIT.RIE = 1;
					break;
				default:
					break;
			}
			
			/* Clear the flag */
			pIIC_IO->ICSR2.BIT.START = 0;
		}
		else
		{
			/*Slave Mode (start or repeat start)*/
			/*In slave mode we only turn on start detection when a transfer has
			started so this must be a repeat start.
			Hence treat it initially as a stop to end the previous transfer.*/
			
			/*Exception. If using a Tx trigger then start detection is
			enabled before generating the initial start.
			In this case ignore the start.
			NOTE. All start conditions on the bus, not just ones for our slave,
			will be detected, so want to ignore them too.*/
			if( (rpdl_IIC_tx_transfer_method[channel] == IIC_TRANSFER_DMAC) ||
				(rpdl_IIC_tx_transfer_method[channel] == IIC_TRANSFER_DTC))
			{
				/*If no address match has been set yet then assume this must be a start
				not a re-start.
				Assumption: In the case of a start this interrupt is serviced
				before the address match is detected.*/
				if(0 == pIIC_IO->ICSR1.BYTE)
				{			
					/* Clear the flag */
					pIIC_IO->ICSR2.BIT.START = 0;
					return;
				}
			}
				
			/* Ensure ACK / NACK decisions are enabled (RDRFS = 1)
			(This stops the master sending us data when we are not ready, so
			do this as soon as possible within this interrupt handler.)*/
			pIIC_IO->ICMR3.BIT.RDRFS = 1;
			
			/*If a DMAC was set then disable (DTE = 0):*/
			if(rpdl_IIC_tx_transfer_method[channel] == IIC_TRANSFER_DMAC)
			{
				*DMCNT_ADDRESS(rpdl_IIC_tx_dmac_channel[channel]) = 0;
				/*Clear flag now that DMAC has been stopped.*/
				rpdl_IIC_tx_transfer_method[channel] = IIC_TRANSFER_CPU;
			}
			else if(rpdl_IIC_tx_transfer_method[channel] == IIC_TRANSFER_DTC)
			{
				/* Disable DTC activation */
				*ICTXI_DTCER_ADDRESS(channel) = 0x00u;
				/*Clear flag now that DTC has been stopped.*/
				rpdl_IIC_tx_transfer_method[channel] = IIC_TRANSFER_CPU;
			}
			if(rpdl_IIC_rx_transfer_method[channel] == IIC_TRANSFER_DMAC)
			{
				*DMCNT_ADDRESS(rpdl_IIC_rx_dmac_channel[channel]) = 0;	
				/*Clear flag now that DMAC has been stopped.*/
				rpdl_IIC_rx_transfer_method[channel] = IIC_TRANSFER_CPU;	
			}
			else if(rpdl_IIC_rx_transfer_method[channel] == IIC_TRANSFER_DTC)
			{
				/* Disable DTC activation */
				*ICRXI_DTCER_ADDRESS(channel) = 0x00u;
				/*Clear flag now that DTC has been stopped.*/
				rpdl_IIC_rx_transfer_method[channel] = IIC_TRANSFER_CPU;
			}
		
			/*Disable interrupts until we have set up new R_IIC_SlaveMonitor*/
			rpdl_IIC_DisableIEN(channel);
			
			/* Is waiting for read flag from master in 10 bits mode? */
			if (rpdl_IIC_current_state[0] == IIC_SLAVE_READ_DATA)
			{
				/* Enable ICTXI interrupt so that read flag can be detected */
				rpdl_IIC_ModifyTx_IER(channel, 1);
			}

			/* Call the callback function */
			if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
			{
				rpdl_IIC_callback_func[channel]();
			}

		}
	}
	/* NACK detected? */
	else if ((valid_flags & BIT_4) != 0x0u)
	{		 
		/* Disable NACK interrupt request generation */
		pIIC_IO->ICIER.BIT.NAKIE = 0;

		/* Failed transmission of data? */
		if (rpdl_IIC_current_state[channel] == IIC_MASTER_SEND_DATA)
		{
			/* Decrement the counter */
			rpdl_IIC_tx_counter[channel]--;

			/* Call the callback function */
			if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
			{
				rpdl_IIC_callback_func[channel]();
			}
		}
		/* NACK received from the master? */
		else
		{		
			/* Do a dummy read to release SCL */
			unwanted_byte = pIIC_IO->ICDRR;
			
			if (rpdl_IIC_current_state[channel] == IIC_SLAVE_SEND_DATA)
			{
				/*In slave transmit mode we will get one more Tx Interrupt
				than the number of bytes read by the master.
				This is because will get an interrupt after each byte written.
				Hence the last byte written to the data register (ICDRT) will
				not have actually been transmitted, so decrement the count.*/
				rpdl_IIC_tx_counter[channel]--;
			}	
		}
	}
	else
	{	 
		/*Stop detected (presume)*/
		
		/*NOTE: rpdl_IIC_tx_transfer_method and rpdl_IIC_rx_transfer_method 
		are only used in slave mode so the following conditions will
		only be true in slave mode.*/
		
		/*If a DMAC was set then disable (DTE = 0):*/
		if(rpdl_IIC_tx_transfer_method[channel] == IIC_TRANSFER_DMAC)
		{
			*DMCNT_ADDRESS(rpdl_IIC_tx_dmac_channel[channel]) = 0;
			
			/*Clear flag now that DMAC has been stopped.*/
			rpdl_IIC_tx_transfer_method[channel] = IIC_TRANSFER_CPU;
		}
		else if(rpdl_IIC_tx_transfer_method[channel] == IIC_TRANSFER_DTC)
		{
			/* Disable DTC activation */
			*ICTXI_DTCER_ADDRESS(channel) = 0x00u;
			
			/*Clear flag now that DTC has been stopped.*/
			rpdl_IIC_tx_transfer_method[channel] = IIC_TRANSFER_CPU;
		}
		if(rpdl_IIC_rx_transfer_method[channel] == IIC_TRANSFER_DMAC)
		{
			*DMCNT_ADDRESS(rpdl_IIC_rx_dmac_channel[channel]) = 0;	
			/* Ensure ACK / NACK decisions are enabled (RDRFS = 1)
			(As required in normal slave mode)*/
			pIIC_IO->ICMR3.BIT.RDRFS = 1;
			/*Clear flag now that DMAC has been stopped.*/
			rpdl_IIC_rx_transfer_method[channel] = IIC_TRANSFER_CPU;
		}
		else if(rpdl_IIC_rx_transfer_method[channel] == IIC_TRANSFER_DTC)
		{
			/* Disable DTC activation */
			*ICRXI_DTCER_ADDRESS(channel) = 0x00u;
			/* Ensure ACK / NACK decisions are enabled (RDRFS = 1)
			(As required in normal slave mode)*/
			pIIC_IO->ICMR3.BIT.RDRFS = 1;
			
			/*Clear flag now that DTC has been stopped.*/
			rpdl_IIC_rx_transfer_method[channel] = IIC_TRANSFER_CPU;
		}
			
		/*In slave mode:
		To allow for continuous monitoring.
		If disable ICIER then can miss interrupts but if just disable IEN
		then when IEN is re-enabled then will get any interrupts missed.
		NOTE: Becuase the MST bit is cleared when stop is detected can't
		use it to detect master/slave mode here. Hence treat both in the same way.*/
		rpdl_IIC_DisableIEN(channel);
		
		/*NOTE: If using DMAC/DTC for a slave transmission then this stop
		may be for another device on the bus. In this case the user will
		detect that no transfer has taken place and continue
		monitoring (R_IIC_SlaveMonitor).*/
			
		/* Call the callback function */
		if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
		{
			rpdl_IIC_callback_func[channel]();
		}
	}
}


/*""FUNC COMMENT""*************************************************************
* Module outline: IICn receive data interrupt processing
*------------------------------------------------------------------------------
* Declaration	: void Interrupt_IIC_ICRXIn(void)
*------------------------------------------------------------------------------
* Function		: 
*------------------------------------------------------------------------------
* Argument		: Nothing
*------------------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------------------
* Output		: ICDRR, ICIER
*------------------------------------------------------------------------------
* Use function	: 
*------------------------------------------------------------------------------
* Notes			: 
*------------------------------------------------------------------------------
* History		: 2014.07.16
*				: Ver 1.11
*				: CS release
*""FUNC COMMENT END""*********************************************************/
#if FAST_INTC_VECTOR == VECT_RIIC0_ICRXI0
#pragma interrupt Interrupt_IIC_ICRXI0(vect=VECT_RIIC0_ICRXI0, fint)
#else
#pragma interrupt Interrupt_IIC_ICRXI0(vect=VECT_RIIC0_ICRXI0)
#endif
void Interrupt_IIC_ICRXI0(void)
{
	Interrupt_IIC_ICRXI_Common(0, (volatile __evenaccess struct st_riic*)&RIIC0);
}


#if FAST_INTC_VECTOR == VECT_RIIC1_ICRXI1
#pragma interrupt Interrupt_IIC_ICRXI1(vect=VECT_RIIC1_ICRXI1, fint)
#else
#pragma interrupt Interrupt_IIC_ICRXI1(vect=VECT_RIIC1_ICRXI1)
#endif
void Interrupt_IIC_ICRXI1(void)
{
#ifdef DEVICE_PACKAGE_LQFP_100
	/* This channel is not available on the 100-pin package */
	nop();
#else
	Interrupt_IIC_ICRXI_Common(1, (volatile __evenaccess struct st_riic*)&RIIC1);
#endif
}


/*ICRXI interrupt handler, not channel specific.*/
static void Interrupt_IIC_ICRXI_Common(uint8_t channel,
								volatile __evenaccess struct st_riic* pIIC_IO)
{
	volatile uint8_t unwanted_byte;

	/*If the time out function is in use this will reset the counter (TMOCNT = 0)*/
	rpdl_IIC_Reset_TimeOut_Counter(channel);
	switch (rpdl_IIC_current_state[channel])
	{
		case IIC_MASTER_START_READ:
			/* Only one byte to be read? */
			if (rpdl_IIC_rx_threshold[channel] == 1)
			{
				/* Prepare to signal a NACK to the slave (ACKBT = 1) */
				pIIC_IO->ICMR3.BIT.ACKBT = 1;
			}
			rpdl_IIC_current_state[channel] = IIC_MASTER_READ_DATA;

			/* Do a dummy read */
			unwanted_byte = pIIC_IO->ICDRR;
			break;
		case IIC_MASTER_READ_DATA:
			/* Is the last byte about to be read from the slave? */
			if (rpdl_IIC_rx_counter[channel] == (rpdl_IIC_rx_threshold[channel] - 2))
			{
				/* Prepare to signal a NACK to the slave (ACKBT = 1) */
				pIIC_IO->ICMR3.BIT.ACKBT = 1;
			}
			/* All data read from the slave? */
			else if (rpdl_IIC_rx_counter[channel] == (rpdl_IIC_rx_threshold[channel] - 1))
			{
				rpdl_IIC_current_state[channel] = IIC_MASTER_WAIT_FOR_STOP;

				/* Enable Stop detection */
				pIIC_IO->ICIER.BIT.SPIE = 1;

				/* Issue a stop condition */
				pIIC_IO->ICCR2.BIT.SP = 1;
			}

			/* Store the data byte */
			*rpdl_IIC_rx_data_pointer[channel] = pIIC_IO->ICDRR;

			/* Increment the pointer */
			rpdl_IIC_rx_data_pointer[channel]++;

			/* Increment the counter */
			rpdl_IIC_rx_counter[channel]++;
			break;
		case IIC_SLAVE_MONITOR:
			/* Note the detected address */
			rpdl_IIC_Store_detected_address(channel);
			
			/* Clear the Stop flag */
			pIIC_IO->ICSR2.BIT.STOP = 0;
			/* Enable Stop detection */
			pIIC_IO->ICIER.BIT.SPIE = 1;

			/* Clear the Start flag */
			pIIC_IO->ICSR2.BIT.START = 0;
			/* Enable Start detection (in case a Repeated Start arrives) */
			pIIC_IO->ICIER.BIT.STIE = 1;

			/* Will interrupts be used for the transfers? */
			if (rpdl_IIC_rx_transfer_method[channel] == IIC_TRANSFER_CPU)
			{
				rpdl_IIC_current_state[channel] = IIC_SLAVE_READ_DATA;
			}
			else
			{
				/* Disable ACK / NACK decisions (RDRFS = 0) */
				pIIC_IO->ICMR3.BIT.RDRFS = 0;
				/* Select DMAC or DTC transfers */
				if (rpdl_IIC_rx_transfer_method[channel] == IIC_TRANSFER_DTC)
				{
					/*DTC*/
					/* Disable DTC Tx activation */
					*ICTXI_DTCER_ADDRESS(channel) = 0x00u;
			
					/* Enable DTC Rx activation */
					*ICRXI_DTCER_ADDRESS(channel) = 0x1u;
				}
				else	
				{
					/* DMAC */
					/* Set DTE = 0 for the Tx DMAC */
					*DMCNT_ADDRESS(rpdl_IIC_tx_dmac_channel[channel]) = 0x00u;
				
					/* Set DTE = 1  for the Rx DMAC */
					*DMCNT_ADDRESS(rpdl_IIC_rx_dmac_channel[channel]) = 0x01u;	
				}
				/* Prevent further RX-based interrupts */
				*IPR_RX_ADDRESS(channel) = 0;
				rpdl_IIC_current_state[channel] = IIC_EXIT_LOOP;
			}

			/* Do a dummy read */
			unwanted_byte = pIIC_IO->ICDRR;
			break;
		case IIC_SLAVE_READ_DATA:
			/* All data received? */
			if (rpdl_IIC_rx_counter[channel] == rpdl_IIC_rx_threshold[channel])
			{
				/* Do a dummy read */
				unwanted_byte = pIIC_IO->ICDRR;

				/* Signal a NACK to the master */
				pIIC_IO->ICMR3.BIT.ACKBT = 1;
			}
			else
			{
				/* Store the data byte */
				*rpdl_IIC_rx_data_pointer[channel] = pIIC_IO->ICDRR;

				/* Increment the pointer */
				rpdl_IIC_rx_data_pointer[channel]++;

				/* Increment the counter */
				rpdl_IIC_rx_counter[channel]++;

				/* Signal an ACK to the master */
				pIIC_IO->ICMR3.BIT.ACKBT = 0;
			}
			break;
		case IIC_SLAVE_SEND_DATA:
			/* Call the callback function */
			if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
			{
				rpdl_IIC_callback_func[channel]();
			}
			break;
		case IIC_EXIT_LOOP:
			/* This will occur if the DMAC/DTC has passed the interrupt on */
			/* Call the callback function */
			if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
			{
				rpdl_IIC_callback_func[channel]();
			}
			break;
		default:
			/* Call the callback function */
			if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
			{
				rpdl_IIC_callback_func[channel]();
			}
			break;
	}
}


/*""FUNC COMMENT""*************************************************************
* Module outline: IICn transmit data interrupt processing
*------------------------------------------------------------------------------
* Declaration	: void Interrupt_IIC_ICTXIn(void)
*------------------------------------------------------------------------------
* Function		: 
*------------------------------------------------------------------------------
* Argument		: Nothing
*------------------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------------------
* Output		: ICDRT, ICIER
*------------------------------------------------------------------------------
* Use function	: 
*------------------------------------------------------------------------------
* Notes			: 
*------------------------------------------------------------------------------
* History		: 2014.07.16
*				: Ver 1.11
*				: CS release
*""FUNC COMMENT END""*********************************************************/
#if FAST_INTC_VECTOR == VECT_RIIC0_ICTXI0
#pragma interrupt Interrupt_IIC_ICTXI0(vect=VECT_RIIC0_ICTXI0, fint)
#else
#pragma interrupt Interrupt_IIC_ICTXI0(vect=VECT_RIIC0_ICTXI0)
#endif
void Interrupt_IIC_ICTXI0(void)
{
	Interrupt_IIC_ICTXI_Common(0, (volatile __evenaccess struct st_riic*)&RIIC0);
}


#if FAST_INTC_VECTOR == VECT_RIIC1_ICTXI1
#pragma interrupt Interrupt_IIC_ICTXI1(vect=VECT_RIIC1_ICTXI1, fint)
#else
#pragma interrupt Interrupt_IIC_ICTXI1(vect=VECT_RIIC1_ICTXI1)
#endif
void Interrupt_IIC_ICTXI1(void)
{
#ifdef DEVICE_PACKAGE_LQFP_100
	/* This channel is not available on the 100-pin package */
	nop();
#else
	Interrupt_IIC_ICTXI_Common(1, (volatile __evenaccess struct st_riic*)&RIIC1);
#endif
}


/*ICTXI interrupt handler, not channel specific.*/
static void Interrupt_IIC_ICTXI_Common(uint8_t channel,
								volatile __evenaccess struct st_riic* pIIC_IO)
{										 
	/*If the time out function is in use this will reset the counter (TMOCNT = 0)*/
	rpdl_IIC_Reset_TimeOut_Counter(channel);
	switch (rpdl_IIC_current_state[channel])
	{
		case IIC_MASTER_SEND_SLAVE_ADDRESS_10b:
			/* Transmit mode? */
			if ((rpdl_IIC_slave_address_upper[channel] & BIT_0) == 0)
			{
				rpdl_IIC_current_state[channel] = IIC_MASTER_SEND_DATA;
			}
			/* Receive mode */
			else
			{
				rpdl_IIC_current_state[channel] = IIC_MASTER_SEND_SLAVE_ADDRESS_10c;

				/* Disable Transmit data empty interrupt generation */
				pIIC_IO->ICIER.BIT.TIE = 0;
			}

			/* Enable Transmit End interrupt generation */
			pIIC_IO->ICIER.BIT.TEIE = 1;
			
			pIIC_IO->ICDRT = rpdl_IIC_slave_address_lower[channel];
			break;
		case IIC_MASTER_SEND_DATA:
			/* All data sent? */
			if (rpdl_IIC_tx_counter[channel] == rpdl_IIC_tx_threshold[channel])
			{
				rpdl_IIC_current_state[channel] = IIC_MASTER_WAIT_FOR_TX_COMPLETE;

				/* Disable ICTXI interrupt request generation */
				pIIC_IO->ICIER.BIT.TIE = 0;

				/* Ensure the ICTEI IR flag is clear */
				*ICTEI_ADDRESS(channel) = 0;

				/* Enable Transmit End interrupt generation */
				pIIC_IO->ICIER.BIT.TEIE = 1;
			}
			else
			{
				/* Load the data to be sent */
				pIIC_IO->ICDRT = *rpdl_IIC_tx_data_pointer[channel];

				/* Increment the pointer */
				rpdl_IIC_tx_data_pointer[channel]++;

				/* Increment the counter */
				rpdl_IIC_tx_counter[channel]++;
			}
			break;
		case IIC_SLAVE_MONITOR:
			/* Note the detected address */
			rpdl_IIC_Store_detected_address(channel);

			/* Clear the Stop flag */
			pIIC_IO->ICSR2.BIT.STOP = 0;
			/* Enable Stop detection */
			pIIC_IO->ICIER.BIT.SPIE = 1;

			/* Clear the Start flag */
			pIIC_IO->ICSR2.BIT.START = 0;
			/* Enable Start detection (in case a Repeated Start arrives) */
			pIIC_IO->ICIER.BIT.STIE = 1;

			/* Call the callback function */
			if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
			{
				/*The user can then send data by calling R_SCI_SlaveSend.*/
				rpdl_IIC_callback_func[channel]();
			}
			break;
		case IIC_SLAVE_SEND_DATA:
			/* All data sent? */
			if(rpdl_IIC_tx_data_pointer[channel] == 
				rpdl_IIC_tx_data_start[channel] + rpdl_IIC_tx_threshold[channel])
			{
				/* Loop back to the start */
				rpdl_IIC_tx_data_pointer[channel] = rpdl_IIC_tx_data_start[channel];
			}
			
			/*Clear the TX IR flag (see note above)*/
			*ICTXI_ADDRESS(channel) = 0x0u;
			
			/* Load the data to be sent */
			pIIC_IO->ICDRT = *rpdl_IIC_tx_data_pointer[channel];

			/* Increment the pointer */
			rpdl_IIC_tx_data_pointer[channel]++;

			/* Increment the counter */
			rpdl_IIC_tx_counter[channel]++;
			break;
		case IIC_SLAVE_READ_DATA:
			/* Call the callback function */
			if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
			{
				rpdl_IIC_callback_func[channel]();
			}
			break;
		case IIC_EXIT_LOOP:
			/* This will occur if the DMAC/DTC has passed interrupt on. */
			/* Call the callback function */
			if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
			{
				rpdl_IIC_callback_func[channel]();
			}
			break;
		default:
			/* Call the callback function */
			if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
			{
				rpdl_IIC_callback_func[channel]();
			}
			break;
	}
}


/*""FUNC COMMENT""*************************************************************
* Module outline: IICn transmit end interrupt processing
*------------------------------------------------------------------------------
* Declaration	: void InterruptIIC_ICTEIn(void)
*------------------------------------------------------------------------------
* Function		: 
*------------------------------------------------------------------------------
* Argument		: Nothing
*------------------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------------------
* Output		: ICIER, ICSR2
*------------------------------------------------------------------------------
* Use function	: 
*------------------------------------------------------------------------------
* Notes			: 
*------------------------------------------------------------------------------
* History		: 2014.07.16
*				: Ver 1.11
*				: CS release
*""FUNC COMMENT END""*********************************************************/

#if FAST_INTC_VECTOR == VECT_RIIC0_ICTEI0
#pragma interrupt Interrupt_IIC_ICTEI0(vect=VECT_RIIC0_ICTEI0, fint)
#else
#pragma interrupt Interrupt_IIC_ICTEI0(vect=VECT_RIIC0_ICTEI0)
#endif
void Interrupt_IIC_ICTEI0(void)
{
	Interrupt_IIC_ICTEI_Common(0, (volatile __evenaccess struct st_riic*)&RIIC0);
}



#if FAST_INTC_VECTOR == VECT_RIIC1_ICTEI1
#pragma interrupt Interrupt_IIC_ICTEI1(vect=VECT_RIIC1_ICTEI1, fint)
#else
#pragma interrupt Interrupt_IIC_ICTEI1(vect=VECT_RIIC1_ICTEI1)
#endif
void Interrupt_IIC_ICTEI1(void)
{
#ifdef DEVICE_PACKAGE_LQFP_100
	/* This channel is not available on the 100-pin package */
	nop();
#else
	Interrupt_IIC_ICTEI_Common(1, (volatile __evenaccess struct st_riic*)&RIIC1);
#endif
}


/*ICTEI interrupt handler, not channel specific.*/
static void Interrupt_IIC_ICTEI_Common(uint8_t channel,
								volatile __evenaccess struct st_riic* pIIC_IO)
{								
	/*If the time out function is in use this will reset the counter (TMOCNT = 0)*/
	rpdl_IIC_Reset_TimeOut_Counter(channel);
	/* Disable Transmit End interrupt request generation */
	pIIC_IO->ICIER.BIT.TEIE = 0;
	/* Clear the flag */
	pIIC_IO->ICSR2.BIT.TEND = 0;

	if (rpdl_IIC_current_state[channel] == IIC_MASTER_SEND_SLAVE_ADDRESS_10c)
	{
		/* Issue the Repeated Start condition */
		pIIC_IO->ICCR2.BYTE |= (uint8_t)BIT_2;
	}
	else
	{
		/* Stop condition required? */
		if (rpdl_IIC_stop[channel] == true)
		{
			rpdl_IIC_current_state[channel] = IIC_MASTER_WAIT_FOR_STOP;
	
			/* Enable Stop detection */
			pIIC_IO->ICIER.BIT.SPIE = 1;
	
			/* Issue a stop condition */
			pIIC_IO->ICCR2.BIT.SP = 1;
		}
		else
		{
			/* Disable all interrupt request generation */
			pIIC_IO->ICIER.BYTE = 0x00u;
	
			/* Call the callback function */
			if (rpdl_IIC_callback_func[channel] != PDL_NO_FUNC)
			{
				rpdl_IIC_callback_func[channel]();
			}
		}
	}
}
/* End of file */
