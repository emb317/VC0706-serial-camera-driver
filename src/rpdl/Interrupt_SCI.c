/*""FILE COMMENT""*************************************************************
* System Name	: Interrupt program for RX62Nxx
* File Name		: Interrupt_SCI.c
* Version		: 1.11
* Contents		: Interrupt handlers for all SCI channels
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

#include "r_pdl_sci.h"
#include "r_pdl_definitions.h"
#include "r_pdl_user_definitions.h"

/* This file uses some SCI utility functions */
extern bool rpdl_SCI_SetTxPinGeneralIO(const uint8_t channel,
									   const bool bGeneralIO);
extern void rpdl_SCI_ModifyTx_IER(const uint8_t, const uint8_t);
extern void rpdl_SCI_ModifyTxEnd_IER(const uint8_t, const uint8_t);

/*""FUNC COMMENT""*************************************************************
* Module outline: SCIn receive data error interrupt processing
*------------------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_ERIn(void)
*------------------------------------------------------------------------------
* Function		: 
*------------------------------------------------------------------------------
* Argument		: Nothing
*------------------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------------------
* Output		: SSR for that SCI channel
*------------------------------------------------------------------------------
* Use function	: rpdl_SCI_RX_Error_callback_func
*------------------------------------------------------------------------------
* Notes			: 
*------------------------------------------------------------------------------
* History		: 2014.07.16
*				: Ver 1.11
*				: CS release
*""FUNC COMMENT END""*********************************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_ERI0
#pragma interrupt Interrupt_SCI0_ERI0(vect=VECT_SCI0_ERI0, fint)
#else
#pragma interrupt Interrupt_SCI0_ERI0(vect=VECT_SCI0_ERI0)
#endif
void Interrupt_SCI0_ERI0(void)
{
	/* Will the user handle the errors? */
	if (sci_global[0].RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		sci_global[0].RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI0.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |\
						 (SCI0.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_ERI1
#pragma interrupt Interrupt_SCI1_ERI1(vect=VECT_SCI1_ERI1, fint)
#else
#pragma interrupt Interrupt_SCI1_ERI1(vect=VECT_SCI1_ERI1)
#endif
void Interrupt_SCI1_ERI1(void)
{
	/* Will the user handle the errors? */
	if (sci_global[1].RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		sci_global[1].RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI1.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |\
						 (SCI1.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI2_ERI2
#pragma interrupt Interrupt_SCI2_ERI2(vect=VECT_SCI2_ERI2, fint)
#else
#pragma interrupt Interrupt_SCI2_ERI2(vect=VECT_SCI2_ERI2)
#endif
void Interrupt_SCI2_ERI2(void)
{
	/* Will the user handle the errors? */
	if (sci_global[2].RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		sci_global[2].RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI2.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |\
						 (SCI2.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI3_ERI3
#pragma interrupt Interrupt_SCI3_ERI3(vect=VECT_SCI3_ERI3, fint)
#else
#pragma interrupt Interrupt_SCI3_ERI3(vect=VECT_SCI3_ERI3)
#endif
void Interrupt_SCI3_ERI3(void)
{
	/* Will the user handle the errors? */
	if (sci_global[3].RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		sci_global[3].RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI3.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |\
						 (SCI3.SSR.BYTE & (uint8_t)BIT_0));
	}
}


#if FAST_INTC_VECTOR == VECT_SCI5_ERI5
#pragma interrupt Interrupt_SCI5_ERI5(vect=VECT_SCI5_ERI5, fint)
#else
#pragma interrupt Interrupt_SCI5_ERI5(vect=VECT_SCI5_ERI5)
#endif
void Interrupt_SCI5_ERI5(void)
{
	/* Will the user handle the errors? */
	if (sci_global[5].RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		sci_global[5].RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI5.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |\
						 (SCI5.SSR.BYTE & (uint8_t)BIT_0));
	}
}

#if FAST_INTC_VECTOR == VECT_SCI6_ERI6
#pragma interrupt Interrupt_SCI6_ERI6(vect=VECT_SCI6_ERI6, fint)
#else
#pragma interrupt Interrupt_SCI6_ERI6(vect=VECT_SCI6_ERI6)
#endif
void Interrupt_SCI6_ERI6(void)
{
	/* Will the user handle the errors? */
	if (sci_global[6].RX_Error_callback_func != PDL_NO_FUNC)
	{
		/* Call the error handler */
		sci_global[6].RX_Error_callback_func();
	}
	else
	{
		/* Clear the SSR error flags;
		Preserve MPBT(b0) and write 1 to reserved bits (b6 and b7)*/
		SCI6.SSR.BYTE = (uint8_t)((BIT_7 | BIT_6) |\
						 (SCI6.SSR.BYTE & (uint8_t)BIT_0));
	}
}

/*""FUNC COMMENT""*************************************************************
* Module outline: SCIn receive data interrupt processing
*------------------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_RXIn(void)
*------------------------------------------------------------------------------
* Function		: 
*------------------------------------------------------------------------------
* Argument		: Nothing
*------------------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------------------
* Output		: 
*------------------------------------------------------------------------------
* Use function	: rpdl_SCI_RX_End_callback_func
*------------------------------------------------------------------------------
* Notes			: 
*------------------------------------------------------------------------------
* History		: 2014.07.16
*				: Ver 1.11
*				: CS release
*""FUNC COMMENT END""*********************************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_RXI0
#pragma interrupt Interrupt_SCI0_RXI0(vect=VECT_SCI0_RXI0, fint)
#else
#pragma interrupt Interrupt_SCI0_RXI0(vect=VECT_SCI0_RXI0)
#endif
void Interrupt_SCI0_RXI0(void)
{
	/* Ok to process the data? */
	if (sci_global[0].rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (sci_global[0].MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI0.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI0.RDR;

				/* ID matching ? */
				if (id != sci_global[0].MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI0.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					sci_global[0].MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (sci_global[0].RX_End_callback_func != PDL_NO_FUNC)
					{
						sci_global[0].RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
		
		/* Read and store the character */
		*sci_global[0].rx_string_pointer = SCI0.RDR;

		/* Increment the character counter */
		sci_global[0].rx_counter++;

		/* More characters expected? */
		if (sci_global[0].rx_counter < sci_global[0].rx_threshold)
		{
			/* Move to the next location in the buffer */
			sci_global[0].rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.*/
			/* If continuous receive mode is selected,  data will be stored to the top of receive buffer 
			after callback function is triggerred. */
			if (sci_global[0].rx_continuous == true)
			{
				sci_global[0].rx_string_pointer = sci_global[0].rx_string_start;
				sci_global[0].rx_counter = 0;
			}
			/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0 && SCR.TEIE==0)
			then also clear TE*/
			if((SCI0.SMR.BIT.CM == 1) &&
			   ((SCI0.SCR.BYTE & (BIT_5 | BIT_2 | BIT_7)) == BIT_5))
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* In continous receive mode, do not disable receive interrupt */
				if (sci_global[0].rx_continuous == false)
				{
					/* Disable interrupt request generation, and try to disable reception */
					SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
				}
			}

			/* Async MP mode ? */
			if (((SCI0.SMR.BIT.MP) != 0) &&
				(sci_global[0].MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI0.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (sci_global[0].RX_End_callback_func != PDL_NO_FUNC)
			{
				sci_global[0].RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[0].RX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[0].RX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_RXI1
#pragma interrupt Interrupt_SCI1_RXI1(vect=VECT_SCI1_RXI1, fint)
#else
#pragma interrupt Interrupt_SCI1_RXI1(vect=VECT_SCI1_RXI1)
#endif
void Interrupt_SCI1_RXI1(void)
{
	/* Ok to process the data? */
	if (sci_global[1].rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (sci_global[1].MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI1.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI1.RDR;

				/* ID matching ? */
				if (id != sci_global[1].MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI1.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					sci_global[1].MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (sci_global[1].RX_End_callback_func != PDL_NO_FUNC)
					{
						sci_global[1].RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
		
		/* Read and store the character */
		*sci_global[1].rx_string_pointer = SCI1.RDR;

		/* Increment the character counter */
		sci_global[1].rx_counter++;

		/* More characters expected? */
		if (sci_global[1].rx_counter < sci_global[1].rx_threshold)
		{
			/* Move to the next location in the buffer */
			sci_global[1].rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.*/
			/* If continuous receive mode is selected,  data will be stored to the top of receive buffer 
			after callback function is triggerred. */
			if (sci_global[1].rx_continuous == true)
			{
				sci_global[1].rx_string_pointer = sci_global[1].rx_string_start;
				sci_global[1].rx_counter = 0;
			}
			/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0 && SCR.TEIE==0)
			then also clear TE*/
			if((SCI1.SMR.BIT.CM == 1) &&
			   ((SCI1.SCR.BYTE & (BIT_5 | BIT_2 | BIT_7)) == BIT_5))
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* In continous receive mode, do not disable receive interrupt */
				if (sci_global[1].rx_continuous == false)
				{
					/* Disable interrupt request generation, and try to disable reception */
					SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
				}
			}

			/* Async MP mode ? */
			if (((SCI1.SMR.BIT.MP) != 0) &&
				(sci_global[1].MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI1.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (sci_global[1].RX_End_callback_func != PDL_NO_FUNC)
			{
				sci_global[1].RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[1].RX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[1].RX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI2_RXI2
#pragma interrupt Interrupt_SCI2_RXI2(vect=VECT_SCI2_RXI2, fint)
#else
#pragma interrupt Interrupt_SCI2_RXI2(vect=VECT_SCI2_RXI2)
#endif
void Interrupt_SCI2_RXI2(void)
{
	/* Ok to process the data? */
	if (sci_global[2].rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (sci_global[2].MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI2.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI2.RDR;

				/* ID matching ? */
				if (id != sci_global[2].MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI2.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI2.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					sci_global[2].MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (sci_global[2].RX_End_callback_func != PDL_NO_FUNC)
					{
						sci_global[2].RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
		
		/* Read and store the character */
		*sci_global[2].rx_string_pointer = SCI2.RDR;

		/* Increment the character counter */
		sci_global[2].rx_counter++;

		/* More characters expected? */
		if (sci_global[2].rx_counter < sci_global[2].rx_threshold)
		{
			/* Move to the next location in the buffer */
			sci_global[2].rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.*/
			/* If continuous receive mode is selected,  data will be stored to the top of receive buffer 
			after callback function is triggerred. */
			if (sci_global[2].rx_continuous == true)
			{
				sci_global[2].rx_string_pointer = sci_global[2].rx_string_start;
				sci_global[2].rx_counter = 0;
			}
			/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0 && SCR.TEIE==0)
			then also clear TE*/
			if((SCI2.SMR.BIT.CM == 1) &&
			   ((SCI2.SCR.BYTE & (BIT_5 | BIT_2 | BIT_7)) == BIT_5))
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI2.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* In continous receive mode, do not disable receive interrupt */
				if (sci_global[2].rx_continuous == false)
				{
					/* Disable interrupt request generation, and try to disable reception */
					SCI2.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
				}
			}

			/* Async MP mode ? */
			if (((SCI2.SMR.BIT.MP) != 0) &&
				(sci_global[2].MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI2.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (sci_global[2].RX_End_callback_func != PDL_NO_FUNC)
			{
				sci_global[2].RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[2].RX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[2].RX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI3_RXI3
#pragma interrupt Interrupt_SCI3_RXI3(vect=VECT_SCI3_RXI3, fint)
#else
#pragma interrupt Interrupt_SCI3_RXI3(vect=VECT_SCI3_RXI3)
#endif
void Interrupt_SCI3_RXI3(void)
{
	/* Ok to process the data? */
	if (sci_global[3].rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (sci_global[3].MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI3.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI3.RDR;

				/* ID matching ? */
				if (id != sci_global[3].MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI3.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI3.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					sci_global[3].MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (sci_global[3].RX_End_callback_func != PDL_NO_FUNC)
					{
						sci_global[3].RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
		
		/* Read and store the character */
		*sci_global[3].rx_string_pointer = SCI3.RDR;

		/* Increment the character counter */
		sci_global[3].rx_counter++;

		/* More characters expected? */
		if (sci_global[3].rx_counter < sci_global[3].rx_threshold)
		{
			/* Move to the next location in the buffer */
			sci_global[3].rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.*/
			/* If continuous receive mode is selected,  data will be stored to the top of receive buffer 
			after callback function is triggerred. */
			if (sci_global[3].rx_continuous == true)
			{
				sci_global[3].rx_string_pointer = sci_global[3].rx_string_start;
				sci_global[3].rx_counter = 0;
			}
			/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0 && SCR.TEIE==0)
			then also clear TE*/
			if((SCI3.SMR.BIT.CM == 1) &&
			   ((SCI3.SCR.BYTE & (BIT_5 | BIT_2 | BIT_7)) == BIT_5))
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI3.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* In continous receive mode, do not disable receive interrupt */
				if (sci_global[3].rx_continuous == false)
				{
					/* Disable interrupt request generation, and try to disable reception */
					SCI3.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
				}
			}

			/* Async MP mode ? */
			if (((SCI3.SMR.BIT.MP) != 0) &&
				(sci_global[3].MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI3.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (sci_global[3].RX_End_callback_func != PDL_NO_FUNC)
			{
				sci_global[3].RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[3].RX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[3].RX_End_callback_func();
		}
	}
}


#if FAST_INTC_VECTOR == VECT_SCI5_RXI5
#pragma interrupt Interrupt_SCI5_RXI5(vect=VECT_SCI5_RXI5, fint)
#else
#pragma interrupt Interrupt_SCI5_RXI5(vect=VECT_SCI5_RXI5)
#endif
void Interrupt_SCI5_RXI5(void)
{
	/* Ok to process the data? */
	if (sci_global[5].rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (sci_global[5].MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI5.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI5.RDR;

				/* ID matching ? */
				if (id != sci_global[5].MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI5.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					sci_global[5].MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (sci_global[5].RX_End_callback_func != PDL_NO_FUNC)
					{
						sci_global[5].RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
				
		/* Read and store the character */
		*sci_global[5].rx_string_pointer = SCI5.RDR;

		/* Increment the character counter */
		sci_global[5].rx_counter++;

		/* More characters expected? */
		if (sci_global[5].rx_counter < sci_global[5].rx_threshold)
		{
			/* Move to the next location in the buffer */
			sci_global[5].rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.*/
			/* If continuous receive mode is selected,  data will be stored to the top of receive buffer 
			after callback function is triggerred. */
			if (sci_global[5].rx_continuous == true)
			{
				sci_global[5].rx_string_pointer = sci_global[5].rx_string_start;
				sci_global[5].rx_counter = 0;
			}
			/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0 && SCR.TEIE==0)
			then also clear TE*/
			if((SCI5.SMR.BIT.CM == 1) &&
			   ((SCI5.SCR.BYTE & (BIT_5 | BIT_2 | BIT_7)) == BIT_5))
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* In continous receive mode, do not disable receive interrupt */
				if (sci_global[5].rx_continuous == false)
				{
					/* Disable interrupt request generation, and try to disable reception */
					SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
				}
			}

			/* Async MP mode ? */
			if (((SCI5.SMR.BIT.MP) != 0) &&
				(sci_global[5].MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI5.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (sci_global[5].RX_End_callback_func != PDL_NO_FUNC)
			{
				sci_global[5].RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[5].RX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[5].RX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI6_RXI6
#pragma interrupt Interrupt_SCI6_RXI6(vect=VECT_SCI6_RXI6, fint)
#else
#pragma interrupt Interrupt_SCI6_RXI6(vect=VECT_SCI6_RXI6)
#endif
void Interrupt_SCI6_RXI6(void)
{
	/* Ok to process the data? */
	if (sci_global[6].rx_using_irq == true)
	{
		/* check if ID reception in Multiprocessor mode */
		if (sci_global[6].MP.MP_mode == RPDL_MP_MODE_EXPECTING_ID)
		{
			/* check if ID cycle ? */
			if (SCI6.SSR.BIT.MPB == 1)
			{
				uint8_t id;
				
				/* Read the ID */
				id = SCI6.RDR;

				/* ID matching ? */
				if (id != sci_global[6].MP.MP_rx_stationID)
				{
					/* ID does not match */
					/* MPIE = 1 */
					SCI6.SCR.BIT.MPIE = 1;
				}
				else
				{
					/* ID matches */
					/* Disable interrupt request generation, and try to disable reception */
					SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
					
					/*Set flag back from RPDL_MP_MODE_EXPECTING_ID to RPDL_MP_MODE_ENABLED*/
					sci_global[6].MP.MP_mode = RPDL_MP_MODE_ENABLED;

					/* Notify the user */
					if (sci_global[6].RX_End_callback_func != PDL_NO_FUNC)
					{
						sci_global[6].RX_End_callback_func();
					}					
				}	
				
				/* Exit ISR */
				return;	
			}
		}
				
		/* Read and store the character */
		*sci_global[6].rx_string_pointer = SCI6.RDR;

		/* Increment the character counter */
		sci_global[6].rx_counter++;

		/* More characters expected? */
		if (sci_global[6].rx_counter < sci_global[6].rx_threshold)
		{
			/* Move to the next location in the buffer */
			sci_global[6].rx_string_pointer++;
		}
		else
		{
			/*Rx has finished.*/
			/* If continuous receive mode is selected,  data will be stored to the top of receive buffer 
			after callback function is triggerred. */
			if (sci_global[6].rx_continuous == true)
			{
				sci_global[6].rx_string_pointer = sci_global[6].rx_string_start;
				sci_global[6].rx_counter = 0;
			}
			
			/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
			Hence if TE bit is enabled but Tx is not pending (SCR.TIE==0 && SCR.TEIE==0)
			then also clear TE.*/
			if((SCI6.SMR.BIT.CM == 1) &&
			   ((SCI6.SCR.BYTE & (BIT_5 | BIT_2 | BIT_7)) == BIT_5))
			{
				/*Tx has finished, so disable TE,TIE,TEIE as well as RE and RIE*/
				SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
				 							INV_BIT_6 & INV_BIT_4);	
			}
			else
			{
				/* In continous receive mode, do not disable receive interrupt */
				if (sci_global[6].rx_continuous == false)
				{
					/* Disable interrupt request generation, and try to disable reception */
					SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_6 & INV_BIT_4);
				}
			}

			/* Async MP mode ? */
			if (((SCI6.SMR.BIT.MP) != 0) &&
				(sci_global[6].MP.MP_mode != RPDL_MP_MODE_DISABLED))
			{
				/* Set MPIE = 1 (multiprocessor mode reception) */
				SCI6.SCR.BIT.MPIE = 1;		
			}

			/* Notify the user */
			if (sci_global[6].RX_End_callback_func != PDL_NO_FUNC)
			{
				sci_global[6].RX_End_callback_func();
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[6].RX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[6].RX_End_callback_func();
		}
	}
}

/*""FUNC COMMENT""*************************************************************
* Module outline: SCIn transmit data interrupt processing
*------------------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_TXIn(void)
*------------------------------------------------------------------------------
* Function		: 
*------------------------------------------------------------------------------
* Argument		: Nothing
*------------------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------------------
* Output		: TDR for that SCI channel
*------------------------------------------------------------------------------
* Use function	: 
*------------------------------------------------------------------------------
* Notes			: 
*------------------------------------------------------------------------------
* History		: 2014.07.16
*				: Ver 1.11
*				: CS release
*""FUNC COMMENT END""*********************************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_TXI0
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0, fint)
#else
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0)
#endif
void Interrupt_SCI0_TXI0(void)
{
	/* Ok to process the string? */
	if (sci_global[0].tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((sci_global[0].tx_threshold == 0) && (*sci_global[0].tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(sci_global[0].tx_counter < sci_global[0].tx_threshold)
		)
		{
			/* Send the character */
			SCI0.TDR = *sci_global[0].tx_string_pointer;

			/* Perform a dummy read */
			if (SCI0.SSR.BIT.TEND == 1)
			{
				nop();
			}

			/* Increment the pointer */
			sci_global[0].tx_string_pointer++;

			/* Increment the counter */
			sci_global[0].tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if (((sci_global[0].tx_threshold == 0) &&
				(*sci_global[0].tx_string_pointer == NULL)) ||
				(sci_global[0].tx_counter == sci_global[0].tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if (SCI0.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI0.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(0, 0);
					
					/*Enable Transmit End Interrupt */
					SCI0.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(0, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI0.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI0.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (sci_global[0].TX_End_callback_func != PDL_NO_FUNC)
				{
					sci_global[0].TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[0].TX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[0].TX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_TXI1
#pragma interrupt Interrupt_SCI1_TXI1(vect=VECT_SCI1_TXI1, fint)
#else
#pragma interrupt Interrupt_SCI1_TXI1(vect=VECT_SCI1_TXI1)
#endif
void Interrupt_SCI1_TXI1(void)
{
	/* Ok to process the string? */
	if (sci_global[1].tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((sci_global[1].tx_threshold == 0) && (*sci_global[1].tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(sci_global[1].tx_counter < sci_global[1].tx_threshold)
		)
		{
			/* Send the character */
			SCI1.TDR = *sci_global[1].tx_string_pointer;

			/* Perform a dummy read */
			if (SCI1.SSR.BIT.TEND == 1)
			{
				nop();
			}

			/* Increment the pointer */
			sci_global[1].tx_string_pointer++;

			/* Increment the counter */
			sci_global[1].tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if (((sci_global[1].tx_threshold == 0) &&
				(*sci_global[1].tx_string_pointer == NULL)) ||
				(sci_global[1].tx_counter == sci_global[1].tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if (SCI1.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI1.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(1, 0);
					
					/*Enable Transmit End Interrupt */
					SCI1.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(1, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI1.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI1.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (sci_global[1].TX_End_callback_func != PDL_NO_FUNC)
				{
					sci_global[1].TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[1].TX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[1].TX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI2_TXI2
#pragma interrupt Interrupt_SCI2_TXI2(vect=VECT_SCI2_TXI2, fint)
#else
#pragma interrupt Interrupt_SCI2_TXI2(vect=VECT_SCI2_TXI2)
#endif
void Interrupt_SCI2_TXI2(void)
{
	/* Ok to process the string? */
	if (sci_global[2].tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((sci_global[2].tx_threshold == 0) && (*sci_global[2].tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(sci_global[2].tx_counter < sci_global[2].tx_threshold)
		)
		{
			/* Send the character */
			SCI2.TDR = *sci_global[2].tx_string_pointer;

			/* Perform a dummy read */
			if (SCI2.SSR.BIT.TEND == 1)
			{
				nop();
			}

			/* Increment the pointer */
			sci_global[2].tx_string_pointer++;

			/* Increment the counter */
			sci_global[2].tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if (((sci_global[2].tx_threshold == 0) &&
				(*sci_global[2].tx_string_pointer == NULL)) ||
				(sci_global[2].tx_counter == sci_global[2].tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if (SCI2.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI2.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(2, 0);
					
					/*Enable Transmit End Interrupt */
					SCI2.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(2, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI2.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI2.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI2.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (sci_global[2].TX_End_callback_func != PDL_NO_FUNC)
				{
					sci_global[2].TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[2].TX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[2].TX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI3_TXI3
#pragma interrupt Interrupt_SCI3_TXI3(vect=VECT_SCI3_TXI3, fint)
#else
#pragma interrupt Interrupt_SCI3_TXI3(vect=VECT_SCI3_TXI3)
#endif
void Interrupt_SCI3_TXI3(void)
{
	/* Ok to process the string? */
	if (sci_global[3].tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((sci_global[3].tx_threshold == 0) && (*sci_global[3].tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(sci_global[3].tx_counter < sci_global[3].tx_threshold)
		)
		{
			/* Send the character */
			SCI3.TDR = *sci_global[3].tx_string_pointer;

			/* Perform a dummy read */
			if (SCI3.SSR.BIT.TEND == 1)
			{
				nop();
			}

			/* Increment the pointer */
			sci_global[3].tx_string_pointer++;

			/* Increment the counter */
			sci_global[3].tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if (((sci_global[3].tx_threshold == 0) &&
				(*sci_global[3].tx_string_pointer == NULL)) ||
				(sci_global[3].tx_counter == sci_global[3].tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if (SCI3.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI3.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(3, 0);
					
					/*Enable Transmit End Interrupt */
					SCI3.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(3, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI3.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI3.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI3.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (sci_global[3].TX_End_callback_func != PDL_NO_FUNC)
				{
					sci_global[3].TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[3].TX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[3].TX_End_callback_func();
		}
	}
}


#if FAST_INTC_VECTOR == VECT_SCI5_TXI5
#pragma interrupt Interrupt_SCI5_TXI5(vect=VECT_SCI5_TXI5, fint)
#else
#pragma interrupt Interrupt_SCI5_TXI5(vect=VECT_SCI5_TXI5)
#endif
void Interrupt_SCI5_TXI5(void)
{
	/* Ok to process the string? */
	if (sci_global[5].tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((sci_global[5].tx_threshold == 0) && (*sci_global[5].tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(sci_global[5].tx_counter < sci_global[5].tx_threshold)
		)
		{
			/* Send the character */
			SCI5.TDR = *sci_global[5].tx_string_pointer;

			/* Perform a dummy read */
			if (SCI5.SSR.BIT.TEND == 1)
			{
				nop();
			}

			/* Increment the pointer */
			sci_global[5].tx_string_pointer++;

			/* Increment the counter */
			sci_global[5].tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if (((sci_global[5].tx_threshold == 0) &&
				(*sci_global[5].tx_string_pointer == NULL)) ||
				(sci_global[5].tx_counter == sci_global[5].tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if (SCI5.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI5.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(5, 0);
					
					/*Enable Transmit End Interrupt */
					SCI5.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(5, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI5.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI5.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (sci_global[5].TX_End_callback_func != PDL_NO_FUNC)
				{
					sci_global[5].TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[5].TX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[5].TX_End_callback_func();
		}
	}
}

#if FAST_INTC_VECTOR == VECT_SCI6_TXI6
#pragma interrupt Interrupt_SCI6_TXI6(vect=VECT_SCI6_TXI6, fint)
#else
#pragma interrupt Interrupt_SCI6_TXI6(vect=VECT_SCI6_TXI6)
#endif
void Interrupt_SCI6_TXI6(void)
{
	/* Ok to process the string? */
	if (sci_global[6].tx_using_irq == true)
	{
		/* Another character to be sent? */
		if (
		/* Sending a string and next character is not a Null? */
		((sci_global[6].tx_threshold == 0) && (*sci_global[6].tx_string_pointer != NULL))
		||
		/* Not reached the byte total? */
		(sci_global[6].tx_counter < sci_global[6].tx_threshold)
		)
		{
			/* Send the character */
			SCI6.TDR = *sci_global[6].tx_string_pointer;

			/* Perform a dummy read */
			if (SCI6.SSR.BIT.TEND == 1)
			{
				nop();
			}

			/* Increment the pointer */
			sci_global[6].tx_string_pointer++;

			/* Increment the counter */
			sci_global[6].tx_counter++;
			
			/*If have just written last byte out (end of string or count reached)*/
			if (((sci_global[6].tx_threshold == 0) &&
				(*sci_global[6].tx_string_pointer == NULL)) ||
				(sci_global[6].tx_counter == sci_global[6].tx_threshold))
			{
				/*Unless in smart card mode then disable this interrupt
				and enable the Transmit End Interrupt*/
				if (SCI6.SCMR.BIT.SMIF == 0)
				{
					/* Disable TXI interrupt request generation */
					SCI6.SCR.BIT.TIE = 0;
					rpdl_SCI_ModifyTx_IER(6, 0);
					
					/*Enable Transmit End Interrupt */
					SCI6.SCR.BIT.TEIE = 1;
					rpdl_SCI_ModifyTxEnd_IER(6, 1);
				}
			}
		}
		else
		{
			/* Disable interrupt request generation */
			SCI6.SCR.BIT.TIE = 0;

			/* Smart card mode? */
			if (SCI6.SCMR.BIT.SMIF == 1)
			{
				/* Disable transmission and interrupt request generation */
				SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5);

				/* Call the callback function */
				if (sci_global[6].TX_End_callback_func != PDL_NO_FUNC)
				{
					sci_global[6].TX_End_callback_func();
				}
			}
		}
	}
	/* Either the DMAC or DTC has passed on the interrupt */ 
	else
	{
		/* Call the callback function */
		if (sci_global[6].TX_End_callback_func != PDL_NO_FUNC)
		{
			sci_global[6].TX_End_callback_func();
		}
	}
}

/*""FUNC COMMENT""*************************************************************
* Module outline: SCIn transmit end interrupt processing
*------------------------------------------------------------------------------
* Declaration	: void Interrupt_SCIn_TEIn(void)
*------------------------------------------------------------------------------
* Function		: 
*------------------------------------------------------------------------------
* Argument		: Nothing
*------------------------------------------------------------------------------
* Return value	: Nothing
*------------------------------------------------------------------------------
* Output		: SCR for that channel
*------------------------------------------------------------------------------
* Use function	: rpdl_SCI_TX_End_callback_func()
*------------------------------------------------------------------------------
* Notes			: 
*------------------------------------------------------------------------------
* History		: 2014.07.16
*				: Ver 1.11
*				: CS release
*""FUNC COMMENT END""*********************************************************/

#if FAST_INTC_VECTOR == VECT_SCI0_TEI0
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0, fint)
#else
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0)
#endif
void Interrupt_SCI0_TEI0(void)
{
	/* If the channel is operating in synchronous mode, transmit only and
	   with an an external clock, the TXD pin may need to be held active
	   for longer (up to half a bit period) to avoid violating the data hold
	   time for the receiving device.  If a delay is required then for example
	   use rpdl_wait_time (X / (double)sci_global[channel].baud_rate)
	   here, where X = the portion of a bit period required.
	   So rpdl_wait_time(0.5 / (double)sci_global[0].baud_rate);
	   creates a delay of half a bit period.
	   The function call is omitted by default to avoid an unnecessary delay. */

	/*Tx has finished.*/
	
	/*If in async mode (SMIF == 0 and CM == 0): To allow control of the
	Tx pin when idle, configure it as a general IO pin.
	NOTE: This must be done before disabling SCR.TE as when TE is cleared the
	pin becomes Hi-z.*/
	if ( (SCI0.SMR.BIT.CM == 0) && (SCI0.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(0, true);
	}

	/* If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if ((SCI0.SMR.BIT.CM == 1) &&
	   ((SCI0.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI0.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}
	
	/* Call the callback function */
	if (sci_global[0].TX_End_callback_func != PDL_NO_FUNC)
	{
		sci_global[0].TX_End_callback_func();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI1_TEI1
#pragma interrupt Interrupt_SCI1_TEI1(vect=VECT_SCI1_TEI1, fint)
#else
#pragma interrupt Interrupt_SCI1_TEI1(vect=VECT_SCI1_TEI1)
#endif
void Interrupt_SCI1_TEI1(void)
{
	/* If the channel is operating in synchronous mode, transmit only and
	   with an an external clock, the TXD pin may need to be held active
	   for longer (up to half a bit period) to avoid violating the data hold
	   time for the receiving device.  If a delay is required then for example
	   use rpdl_wait_time (X / (double)sci_global[channel].baud_rate)
	   here, where X = the portion of a bit period required.
	   So rpdl_wait_time(0.5 / (double)sci_global[1].baud_rate);
	   creates a delay of half a bit period.
	   The function call is omitted by default to avoid an unnecessary delay. */

	/*Tx has finished.*/
	
	/*If in async mode (SMIF == 0 and CM == 0): To allow control of the
	Tx pin when idle, configure it as a general IO pin.
	NOTE: This must be done before disabling SCR.TE as when TE is cleared the
	pin becomes Hi-z.*/
	if ( (SCI1.SMR.BIT.CM == 0) && (SCI1.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(1, true);
	}
	
	/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if ((SCI1.SMR.BIT.CM == 1) &&
	   ((SCI1.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI1.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}

	/* Call the callback function */
	if (sci_global[1].TX_End_callback_func != PDL_NO_FUNC)
	{
		sci_global[1].TX_End_callback_func();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI2_TEI2
#pragma interrupt Interrupt_SCI2_TEI2(vect=VECT_SCI2_TEI2, fint)
#else
#pragma interrupt Interrupt_SCI2_TEI2(vect=VECT_SCI2_TEI2)
#endif
void Interrupt_SCI2_TEI2(void)
{
	/* If the channel is operating in synchronous mode, transmit only and
	   with an an external clock, the TXD pin may need to be held active
	   for longer (up to half a bit period) to avoid violating the data hold
	   time for the receiving device.  If a delay is required then for example
	   use rpdl_wait_time (X / (double)sci_global[channel].baud_rate)
	   here, where X = the portion of a bit period required.
	   So rpdl_wait_time(0.5 / (double)sci_global[2].baud_rate);
	   creates a delay of half a bit period.
	   The function call is omitted by default to avoid an unnecessary delay. */

	/*Tx has finished.*/
	
	/*If in async mode (SMIF == 0 and CM == 0): To allow control of the
	Tx pin when idle, configure it as a general IO pin.
	NOTE: This must be done before disabling SCR.TE as when TE is cleared the
	pin becomes Hi-z.*/
	if ( (SCI2.SMR.BIT.CM == 0) && (SCI2.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(2, true);
	}

	/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if ((SCI2.SMR.BIT.CM == 1) &&
	   ((SCI2.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI2.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI2.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}
	
	/* Call the callback function */
	if (sci_global[2].TX_End_callback_func != PDL_NO_FUNC)
	{
		sci_global[2].TX_End_callback_func();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI3_TEI3
#pragma interrupt Interrupt_SCI3_TEI3(vect=VECT_SCI3_TEI3, fint)
#else
#pragma interrupt Interrupt_SCI3_TEI3(vect=VECT_SCI3_TEI3)
#endif
void Interrupt_SCI3_TEI3(void)
{
	/* If the channel is operating in synchronous mode, transmit only and
	   with an an external clock, the TXD pin may need to be held active
	   for longer (up to half a bit period) to avoid violating the data hold
	   time for the receiving device.  If a delay is required then for example
	   use rpdl_wait_time (X / (double)sci_global[channel].baud_rate)
	   here, where X = the portion of a bit period required.
	   So rpdl_wait_time(0.5 / (double)sci_global[3].baud_rate);
	   creates a delay of half a bit period.
	   The function call is omitted by default to avoid an unnecessary delay. */

	/*Tx has finished.*/
	
	/*If in async mode (SMIF == 0 and CM == 0): To allow control of the
	Tx pin when idle, configure it as a general IO pin.
	NOTE: This must be done before disabling SCR.TE as when TE is cleared the
	pin becomes Hi-z.*/
	if ( (SCI3.SMR.BIT.CM == 0) && (SCI3.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(3, true);
	}

	/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if ((SCI3.SMR.BIT.CM == 1) &&
	   ((SCI3.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI3.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI3.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}

	/* Call the callback function */
	if (sci_global[3].TX_End_callback_func != PDL_NO_FUNC)
	{
		sci_global[3].TX_End_callback_func();
	}
}


#if FAST_INTC_VECTOR == VECT_SCI5_TEI5
#pragma interrupt Interrupt_SCI5_TEI5(vect=VECT_SCI5_TEI5, fint)
#else
#pragma interrupt Interrupt_SCI5_TEI5(vect=VECT_SCI5_TEI5)
#endif
void Interrupt_SCI5_TEI5(void)
{
	/* If the channel is operating in synchronous mode, transmit only and
	   with an an external clock, the TXD pin may need to be held active
	   for longer (up to half a bit period) to avoid violating the data hold
	   time for the receiving device.  If a delay is required then for example
	   use rpdl_wait_time (X / (double)sci_global[channel].baud_rate)
	   here, where X = the portion of a bit period required.
	   So rpdl_wait_time(0.5 / (double)sci_global[5].baud_rate);
	   creates a delay of half a bit period.
	   The function call is omitted by default to avoid an unnecessary delay. */

	/*Tx has finished.*/
	
	/*If in async mode (SMIF == 0 and CM == 0): To allow control of the
	Tx pin when idle, configure it as a general IO pin.
	NOTE: This must be done before disabling SCR.TE as when TE is cleared the
	pin becomes Hi-z.*/
	if ( (SCI5.SMR.BIT.CM == 0) && (SCI5.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(5, true);
	}

	/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if ((SCI5.SMR.BIT.CM == 1) &&
	   ((SCI5.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI5.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}

	/* Call the callback function */
	if (sci_global[5].TX_End_callback_func != PDL_NO_FUNC)
	{
		sci_global[5].TX_End_callback_func();
	}
}

#if FAST_INTC_VECTOR == VECT_SCI6_TEI6
#pragma interrupt Interrupt_SCI6_TEI6(vect=VECT_SCI6_TEI6, fint)
#else
#pragma interrupt Interrupt_SCI6_TEI6(vect=VECT_SCI6_TEI6)
#endif
void Interrupt_SCI6_TEI6(void)
{
	/* If the channel is operating in synchronous mode, transmit only and
	   with an an external clock, the TXD pin may need to be held active
	   for longer (up to half a bit period) to avoid violating the data hold
	   time for the receiving device.  If a delay is required then for example
	   use rpdl_wait_time (X / (double)sci_global[channel].baud_rate)
	   here, where X = the portion of a bit period required.
	   So rpdl_wait_time(0.5 / (double)sci_global[6].baud_rate);
	   creates a delay of half a bit period.
	   The function call is omitted by default to avoid an unnecessary delay. */

	/*Tx has finished.*/

	/*If in async mode (SMIF == 0 and CM == 0): To allow control of the
	Tx pin when idle, configure it as a general IO pin.
	NOTE: This must be done before disabling SCR.TE as when TE is cleared the
	pin becomes Hi-z.*/
	if ( (SCI6.SMR.BIT.CM == 0) && (SCI6.SCMR.BIT.SMIF == 0) )
	{
		rpdl_SCI_SetTxPinGeneralIO(6, true);
	}
	
	/*If in sync mode (SMR.CM==1) then can't clear SCR.TE and SCR.RE independantly.
	Hence if RE bit is enabled but Rx is not pending (SCR.RIE==0) also clear RE*/
	if ((SCI6.SMR.BIT.CM == 1) &&
	   ((SCI6.SCR.BYTE & (BIT_4 | BIT_6)) == BIT_4))
		
	{
		/*Rx has finished, so disable RE,RIE as well as TE,TIE,TEIE*/
		SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2 &
		 							INV_BIT_6 & INV_BIT_4);	
	}
	else
	{
		/* Disable interrupt request generation, and try to disable transmission */
		SCI6.SCR.BYTE &= (uint8_t)(INV_BIT_7 & INV_BIT_5 & INV_BIT_2);
	}

	/* Call the callback function */
	if (sci_global[6].TX_End_callback_func != PDL_NO_FUNC)
	{
		sci_global[6].TX_End_callback_func();
	}
}
/* End of file */
