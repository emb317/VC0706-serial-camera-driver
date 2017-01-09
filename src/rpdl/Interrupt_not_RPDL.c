/*""FILE COMMENT""*************************************************************
* System Name	: Interrupt program for RX62Nxx
* File Name		: Interrupt_not_RPDL.c
* Version		: 1.11
* Contents		: Interrupt handlers for peripherals outside the scope
*				: of RPDL
* Customer		: 
* Model		 	:
* Order		 	:
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

#include "r_pdl_common_defs_RX62Nxx.h"
#include "r_pdl_user_definitions.h"

/* Remove the // comment mark if an RPDL interrupt file is not included 
   in the build but an interrupt vector table entry is still required. */
//#define RPDL_ADC_10_not_used
//#define RPDL_ADC_12_not_used
//#define RPDL_BSC_not_used
//#define RPDL_CMT_not_used
//#define RPDL_DMAC_not_used
//#define RPDL_EXDMAC_not_used
//#define RPDL_IIC_not_used
//#define RPDL_MTU2_not_used
//#define RPDL_POE_not_used
//#define RPDL_RTC_not_used
//#define RPDL_SCI_not_used
//#define RPDL_SPI_not_used
//#define RPDL_TMR_not_used
//#define RPDL_WDT_not_used

#ifdef RPDL_ADC_10_not_used
#pragma interrupt Interrupt_ADC0(vect=VECT_AD0_ADI0)
void Interrupt_ADC0(void){}
#pragma interrupt Interrupt_ADC1(vect=VECT_AD1_ADI1)
void Interrupt_ADC1(void){}
#endif

#ifdef RPDL_ADC_12_not_used
#pragma interrupt Interrupt_ADC_12_0(vect=VECT_S12AD_ADI)
void Interrupt_ADC_12_0(void){}
#endif

#ifdef RPDL_BSC_not_used
#pragma interrupt Interrupt_BSC(vect=VECT_BSC_BUSERR)
void Interrupt_BSC(void){}
#endif

#ifdef RPDL_CMT_not_used
#pragma interrupt Interrupt_CMT0(vect=VECT_CMT0_CMI0)
void Interrupt_CMT0(void){}
#pragma interrupt Interrupt_CMT1(vect=VECT_CMT1_CMI1)
void Interrupt_CMT1(void){}
#pragma interrupt Interrupt_CMT2(vect=VECT_CMT2_CMI2)
void Interrupt_CMT2(void){}
#pragma interrupt Interrupt_CMT3(vect=VECT_CMT3_CMI3)
void Interrupt_CMT3(void){}
#endif

#ifdef RPDL_DMAC_not_used
#pragma interrupt Interrupt_DMAC0(vect=VECT_DMAC_DMAC0I)
void Interrupt_DMAC0(void){}
#pragma interrupt Interrupt_DMAC1(vect=VECT_DMAC_DMAC1I)
void Interrupt_DMAC1(void){}
#pragma interrupt Interrupt_DMAC2(vect=VECT_DMAC_DMAC2I)
void Interrupt_DMAC2(void){}
#pragma interrupt Interrupt_DMAC3(vect=VECT_DMAC_DMAC3I)
void Interrupt_DMAC3(void){}
#endif

#ifdef RPDL_EXDMAC_not_used
#pragma interrupt Interrupt_EXDMAC0(vect=VECT_EXDMAC_EXDMAC0I)
void Interrupt_EXDMAC0(void){}
#pragma interrupt Interrupt_EXDMAC1(vect=VECT_EXDMAC_EXDMAC1I)
void Interrupt_EXDMAC1(void){}
#endif

#ifdef RPDL_IIC_not_used
#pragma interrupt Interrupt_IIC_ICEEI0(vect=VECT_RIIC0_ICEEI0)
void Interrupt_IIC_ICEEI0(void){}
#pragma interrupt Interrupt_IIC_ICEEI1(vect=VECT_RIIC1_ICEEI1)
void Interrupt_IIC_ICEEI1(void){}
#pragma interrupt Interrupt_IIC_ICRXI0(vect=VECT_RIIC0_ICRXI0)
void Interrupt_IIC_ICRXI0(void){}
#pragma interrupt Interrupt_IIC_ICRXI1(vect=VECT_RIIC1_ICRXI1)
void Interrupt_IIC_ICRXI1(void){}
#pragma interrupt Interrupt_IIC_ICTXI0(vect=VECT_RIIC0_ICTXI0)
void Interrupt_IIC_ICTXI0(void){}
#pragma interrupt Interrupt_IIC_ICTXI1(vect=VECT_RIIC1_ICTXI1)
void Interrupt_IIC_ICTXI1(void){}
#pragma interrupt Interrupt_IIC_ICTEI0(vect=VECT_RIIC0_ICTEI0)
void Interrupt_IIC_ICTEI0(void){}
#pragma interrupt Interrupt_IIC_ICTEI1(vect=VECT_RIIC1_ICTEI1)
void Interrupt_IIC_ICTEI1(void){}
#endif

#ifdef RPDL_MTU2_not_used
#pragma interrupt Interrupt_MTU0_TGIA0(vect=VECT_MTU0_TGIA0)
void Interrupt_MTU0_TGIA0(void){}
#pragma interrupt Interrupt_MTU1_TGIA1(vect=VECT_MTU1_TGIA1)
void Interrupt_MTU1_TGIA1(void){}
#pragma interrupt Interrupt_MTU2_TGIA2(vect=VECT_MTU2_TGIA2)
void Interrupt_MTU2_TGIA2(void){}
#pragma interrupt Interrupt_MTU3_TGIA3(vect=VECT_MTU3_TGIA3)
void Interrupt_MTU3_TGIA3(void){}
#pragma interrupt Interrupt_MTU4_TGIA4(vect=VECT_MTU4_TGIA4)
void Interrupt_MTU4_TGIA4(void){}
#pragma interrupt Interrupt_MTU6_TGIA6(vect=VECT_MTU6_TGIA6)
void Interrupt_MTU6_TGIA6(void){}
#pragma interrupt Interrupt_MTU7_TGIA7(vect=VECT_MTU7_TGIA7)
void Interrupt_MTU7_TGIA7(void){}
#pragma interrupt Interrupt_MTU8_TGIA8(vect=VECT_MTU8_TGIA8)
void Interrupt_MTU8_TGIA8(void){}
#pragma interrupt Interrupt_MTU9_TGIA9(vect=VECT_MTU9_TGIA9)
void Interrupt_MTU9_TGIA9(void){}
#pragma interrupt Interrupt_MTU10_TGIA10(vect=VECT_MTU10_TGIA10)
void Interrupt_MTU10_TGIA10(void){}
#pragma interrupt Interrupt_MTU0_TGIB0(vect=VECT_MTU0_TGIB0)
void Interrupt_MTU0_TGIB0(void){}
#pragma interrupt Interrupt_MTU1_TGIB1(vect=VECT_MTU1_TGIB1)
void Interrupt_MTU1_TGIB1(void){}
#pragma interrupt Interrupt_MTU2_TGIB2(vect=VECT_MTU2_TGIB2)
void Interrupt_MTU2_TGIB2(void){}
#pragma interrupt Interrupt_MTU3_TGIB3(vect=VECT_MTU3_TGIB3)
void Interrupt_MTU3_TGIB3(void){}
#pragma interrupt Interrupt_MTU4_TGIB4(vect=VECT_MTU4_TGIB4)
void Interrupt_MTU4_TGIB4(void){}
#pragma interrupt Interrupt_MTU6_TGIB6(vect=VECT_MTU6_TGIB6)
void Interrupt_MTU6_TGIB6(void){}
#pragma interrupt Interrupt_MTU7_TGIB7(vect=VECT_MTU7_TGIB7)
void Interrupt_MTU7_TGIB7(void){}
#pragma interrupt Interrupt_MTU8_TGIB8(vect=VECT_MTU8_TGIB8)
void Interrupt_MTU8_TGIB8(void){}
#pragma interrupt Interrupt_MTU9_TGIB9(vect=VECT_MTU9_TGIB9)
void Interrupt_MTU9_TGIB9(void){}
#pragma interrupt Interrupt_MTU10_TGIB10(vect=VECT_MTU10_TGIB10)
void Interrupt_MTU10_TGIB10(void){}
#pragma interrupt Interrupt_MTU0_TGIC0(vect=VECT_MTU0_TGIC0)
void Interrupt_MTU0_TGIC0(void){}
#pragma interrupt Interrupt_MTU3_TGIC3(vect=VECT_MTU3_TGIC3)
void Interrupt_MTU3_TGIC3(void){}
#pragma interrupt Interrupt_MTU4_TGIC4(vect=VECT_MTU4_TGIC4)
void Interrupt_MTU4_TGIC4(void){}
#pragma interrupt Interrupt_MTU6_TGIC6(vect=VECT_MTU6_TGIC6)
void Interrupt_MTU6_TGIC6(void){}
#pragma interrupt Interrupt_MTU9_TGIC9(vect=VECT_MTU9_TGIC9)
void Interrupt_MTU9_TGIC9(void){}
#pragma interrupt Interrupt_MTU10_TGIC10(vect=VECT_MTU10_TGIC10)
void Interrupt_MTU10_TGIC10(void){}
#pragma interrupt Interrupt_MTU0_TGID0(vect=VECT_MTU0_TGID0)
void Interrupt_MTU0_TGID0(void){}
#pragma interrupt Interrupt_MTU3_TGID3(vect=VECT_MTU3_TGID3)
void Interrupt_MTU3_TGID3(void){}
#pragma interrupt Interrupt_MTU4_TGID4(vect=VECT_MTU4_TGID4)
void Interrupt_MTU4_TGID4(void){}
#pragma interrupt Interrupt_MTU6_TGID6(vect=VECT_MTU6_TGID6)
void Interrupt_MTU6_TGID6(void){}
#pragma interrupt Interrupt_MTU9_TGID9(vect=VECT_MTU9_TGID9)
void Interrupt_MTU9_TGID9(void){}
#pragma interrupt Interrupt_MTU10_TGID10(vect=VECT_MTU10_TGID10)
void Interrupt_MTU10_TGID10(void){}
#pragma interrupt Interrupt_MTU0_TGIE0(vect=VECT_MTU0_TGIE0)
void Interrupt_MTU0_TGIE0(void){}
#pragma interrupt Interrupt_MTU6_TGIE6(vect=VECT_MTU6_TGIE6)
void Interrupt_MTU6_TGIE6(void){}
#pragma interrupt Interrupt_MTU0_TGIF0(vect=VECT_MTU0_TGIF0)
void Interrupt_MTU0_TGIF0(void){}
#pragma interrupt Interrupt_MTU6_TGIF6(vect=VECT_MTU6_TGIF6)
void Interrupt_MTU6_TGIF6(void){}
#pragma interrupt Interrupt_MTU0_TCIV0(vect=VECT_MTU0_TCIV0)
void Interrupt_MTU0_TCIV0(void){}
#pragma interrupt Interrupt_MTU1_TCIV1(vect=VECT_MTU1_TCIV1)
void Interrupt_MTU1_TCIV1(void){}
#pragma interrupt Interrupt_MTU2_TCIV2(vect=VECT_MTU2_TCIV2)
void Interrupt_MTU2_TCIV2(void){}
#pragma interrupt Interrupt_MTU3_TCIV3(vect=VECT_MTU3_TCIV3)
void Interrupt_MTU3_TCIV3(void){}
#pragma interrupt Interrupt_MTU4_TCIV4(vect=VECT_MTU4_TCIV4)
void Interrupt_MTU4_TCIV4(void){}
#pragma interrupt Interrupt_MTU6_TCIV6(vect=VECT_MTU6_TCIV6)
void Interrupt_MTU6_TCIV6(void){}
#pragma interrupt Interrupt_MTU7_TCIV7(vect=VECT_MTU7_TCIV7)
void Interrupt_MTU7_TCIV7(void){}
#pragma interrupt Interrupt_MTU8_TCIV8(vect=VECT_MTU8_TCIV8)
void Interrupt_MTU8_TCIV8(void){}
#pragma interrupt Interrupt_MTU9_TCIV9(vect=VECT_MTU9_TCIV9)
void Interrupt_MTU9_TCIV9(void){}
#pragma interrupt Interrupt_MTU10_TCIV10(vect=VECT_MTU10_TCIV10)
void Interrupt_MTU10_TCIV10(void){}
#pragma interrupt Interrupt_MTU1_TCIU1(vect=VECT_MTU1_TCIU1)
void Interrupt_MTU1_TCIU1(void){}
#pragma interrupt Interrupt_MTU2_TCIU2(vect=VECT_MTU2_TCIU2)
void Interrupt_MTU2_TCIU2(void){}
#pragma interrupt Interrupt_MTU7_TCIU7(vect=VECT_MTU7_TCIU7)
void Interrupt_MTU7_TCIU7(void){}
#pragma interrupt Interrupt_MTU8_TCIU8(vect=VECT_MTU8_TCIU8)
void Interrupt_MTU8_TCIU8(void){}
#pragma interrupt Interrupt_MTU5_TGIU5(vect=VECT_MTU5_TGIU5)
void Interrupt_MTU5_TGIU5(void){}
#pragma interrupt Interrupt_MTU11_TGIU11(vect=VECT_MTU11_TGIU11)
void Interrupt_MTU11_TGIU11(void){}
#pragma interrupt Interrupt_MTU5_TGIV5(vect=VECT_MTU5_TGIV5)
void Interrupt_MTU5_TGIV5(void){}
#pragma interrupt Interrupt_MTU11_TGIV11(vect=VECT_MTU11_TGIV11)
void Interrupt_MTU11_TGIV11(void){}
#pragma interrupt Interrupt_MTU5_TGIW5(vect=VECT_MTU5_TGIW5)
void Interrupt_MTU5_TGIW5(void){}
#pragma interrupt Interrupt_MTU11_TGIW11(vect=VECT_MTU11_TGIW11)
void Interrupt_MTU11_TGIW11(void){}
#endif

#ifdef RPDL_POE_not_used
#pragma interrupt Interrupt_OEI1(vect=VECT_POE_OEI1)
void Interrupt_OEI1(void){}
#pragma interrupt Interrupt_OEI2(vect=VECT_POE_OEI2)
void Interrupt_OEI2(void){}
#pragma interrupt Interrupt_OEI3(vect=VECT_POE_OEI3)
void Interrupt_OEI3(void){}
#pragma interrupt Interrupt_OEI4(vect=VECT_POE_OEI4)
void Interrupt_OEI4(void){}
#endif

#ifdef RPDL_RTC_not_used
#pragma interrupt Interrupt_RTC_PRD(vect=VECT_RTC_PRD)
void Interrupt_RTC_PRD(void){}
#pragma interrupt Interrupt_RTC_ALM(vect=VECT_RTC_ALM)
void Interrupt_RTC_ALM(void){}
#pragma interrupt Interrupt_RTC_CUP(vect=VECT_RTC_CUP)
void Interrupt_RTC_CUP(void){}
#endif

#ifdef RPDL_SCI_not_used
#pragma interrupt Interrupt_SCI0_ERI0(vect=VECT_SCI0_ERI0)
void Interrupt_SCI0_ERI0(void){}
#pragma interrupt Interrupt_SCI1_ERI1(vect=VECT_SCI1_ERI1)
void Interrupt_SCI1_ERI1(void){}
#pragma interrupt Interrupt_SCI2_ERI2(vect=VECT_SCI2_ERI2)
void Interrupt_SCI2_ERI2(void){}
#pragma interrupt Interrupt_SCI3_ERI3(vect=VECT_SCI3_ERI3)
void Interrupt_SCI3_ERI3(void){}
#pragma interrupt Interrupt_SCI5_ERI5(vect=VECT_SCI5_ERI5)
void Interrupt_SCI5_ERI5(void){}
#pragma interrupt Interrupt_SCI6_ERI6(vect=VECT_SCI6_ERI6)
void Interrupt_SCI6_ERI6(void){}
#pragma interrupt Interrupt_SCI0_RXI0(vect=VECT_SCI0_RXI0)
void Interrupt_SCI0_RXI0(void){}
#pragma interrupt Interrupt_SCI1_RXI1(vect=VECT_SCI1_RXI1)
void Interrupt_SCI1_RXI1(void){}
#pragma interrupt Interrupt_SCI2_RXI2(vect=VECT_SCI2_RXI2)
void Interrupt_SCI2_RXI2(void){}
#pragma interrupt Interrupt_SCI3_RXI3(vect=VECT_SCI3_RXI3)
void Interrupt_SCI3_RXI3(void){}
#pragma interrupt Interrupt_SCI5_RXI5(vect=VECT_SCI5_RXI5)
void Interrupt_SCI5_RXI5(void){}
#pragma interrupt Interrupt_SCI6_RXI6(vect=VECT_SCI6_RXI6)
void Interrupt_SCI6_RXI6(void){}
#pragma interrupt Interrupt_SCI0_TXI0(vect=VECT_SCI0_TXI0)
void Interrupt_SCI0_TXI0(void){}
#pragma interrupt Interrupt_SCI1_TXI1(vect=VECT_SCI1_TXI1)
void Interrupt_SCI1_TXI1(void){}
#pragma interrupt Interrupt_SCI2_TXI2(vect=VECT_SCI2_TXI2)
void Interrupt_SCI2_TXI2(void){}
#pragma interrupt Interrupt_SCI3_TXI3(vect=VECT_SCI3_TXI3)
void Interrupt_SCI3_TXI3(void){}
#pragma interrupt Interrupt_SCI5_TXI5(vect=VECT_SCI5_TXI5)
void Interrupt_SCI5_TXI5(void){}
#pragma interrupt Interrupt_SCI6_TXI6(vect=VECT_SCI6_TXI6)
void Interrupt_SCI6_TXI6(void){}
#pragma interrupt Interrupt_SCI0_TEI0(vect=VECT_SCI0_TEI0)
void Interrupt_SCI0_TEI0(void){}
#pragma interrupt Interrupt_SCI1_TEI1(vect=VECT_SCI1_TEI1)
void Interrupt_SCI1_TEI1(void){}
#pragma interrupt Interrupt_SCI2_TEI2(vect=VECT_SCI2_TEI2)
void Interrupt_SCI2_TEI2(void){}
#pragma interrupt Interrupt_SCI3_TEI3(vect=VECT_SCI3_TEI3)
void Interrupt_SCI3_TEI3(void){}
#pragma interrupt Interrupt_SCI5_TEI5(vect=VECT_SCI5_TEI5)
void Interrupt_SCI5_TEI5(void){}
#pragma interrupt Interrupt_SCI6_TEI6(vect=VECT_SCI6_TEI6)
void Interrupt_SCI6_TEI6(void){}
#endif

#ifdef RPDL_SPI_not_used
#pragma interrupt Interrupt_RSPI0_SPEI0(vect=VECT_RSPI0_SPEI0)
void Interrupt_RSPI0_SPEI0(void){}
#pragma interrupt Interrupt_RSPI1_SPEI1(vect=VECT_RSPI1_SPEI1)
void Interrupt_RSPI1_SPEI1(void){}
#pragma interrupt Interrupt_RSPI0_SPRI0(vect=VECT_RSPI0_SPRI0)
void Interrupt_RSPI0_SPRI0(void){}
#pragma interrupt Interrupt_RSPI1_SPRI1(vect=VECT_RSPI1_SPRI1)
void Interrupt_RSPI1_SPRI1(void){}
#pragma interrupt Interrupt_RSPI0_SPTI0(vect=VECT_RSPI0_SPTI0)
void Interrupt_RSPI0_SPTI0(void){}
#pragma interrupt Interrupt_RSPI1_SPTI1(vect=VECT_RSPI1_SPTI1)
void Interrupt_RSPI1_SPTI1(void){}
#pragma interrupt Interrupt_RSPI0_SPII0(vect=VECT_RSPI0_SPII0)
void Interrupt_RSPI0_SPII0(void){}
#pragma interrupt Interrupt_RSPI1_SPII1(vect=VECT_RSPI1_SPII1)
void Interrupt_RSPI1_SPII1(void){}
#endif

#ifdef RPDL_TMR_not_used
#pragma interrupt Interrupt_TMR0_CMA(vect=VECT_TMR0_CMIA0)
void Interrupt_TMR0_CMA(void){}
#pragma interrupt Interrupt_TMR0_CMB(vect=VECT_TMR0_CMIB0)
void Interrupt_TMR0_CMB(void){}
#pragma interrupt Interrupt_TMR0_OV(vect=VECT_TMR0_OVI0)
void Interrupt_TMR0_OV(void){}
#pragma interrupt Interrupt_TMR1_CMA(vect=VECT_TMR1_CMIA1)
void Interrupt_TMR1_CMA(void){}
#pragma interrupt Interrupt_TMR1_CMB(vect=VECT_TMR1_CMIB1)
void Interrupt_TMR1_CMB(void){}
#pragma interrupt Interrupt_TMR1_OV(vect=VECT_TMR1_OVI1)
void Interrupt_TMR1_OV(void){}
#pragma interrupt Interrupt_TMR2_CMA(vect=VECT_TMR2_CMIA2)
void Interrupt_TMR2_CMA(void){}
#pragma interrupt Interrupt_TMR2_CMB(vect=VECT_TMR2_CMIB2)
void Interrupt_TMR2_CMB(void){}
#pragma interrupt Interrupt_TMR2_OV(vect=VECT_TMR2_OVI2)
void Interrupt_TMR2_OV(void){}
#pragma interrupt Interrupt_TMR3_CMA(vect=VECT_TMR3_CMIA3)
void Interrupt_TMR3_CMA(void){}
#pragma interrupt Interrupt_TMR3_CMB(vect=VECT_TMR3_CMIB3)
void Interrupt_TMR3_CMB(void){}
#pragma interrupt Interrupt_TMR3_OV(vect=VECT_TMR3_OVI3)
void Interrupt_TMR3_OV(void){}
#endif

#ifdef RPDL_WDT_not_used
#pragma interrupt Interrupt_WDT(vect=VECT_WDT_WOVI)
void Interrupt_WDT(void){}
#endif

/* Interrupt handlers for peripherals that are not supported
   by RPDL but which may use the Fast Interrupt feature. */

#if FAST_INTC_VECTOR == VECT_FCU_FIFERR
#pragma interrupt Interrupt_FIFERR(vect=VECT_FCU_FIFERR, fint)
#else
#pragma interrupt Interrupt_FIFERR(vect=VECT_FCU_FIFERR)
#endif
void Interrupt_FIFERR(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_FCU_FRDYI
#pragma interrupt Interrupt_FRDYI(vect=VECT_FCU_FRDYI, fint)
#else
#pragma interrupt Interrupt_FRDYI(vect=VECT_FCU_FRDYI)
#endif
void Interrupt_FRDYI(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_ETHER_EINT
#pragma interrupt Interrupt_EINT(vect=VECT_ETHER_EINT, fint)
#else
#pragma interrupt Interrupt_EINT(vect=VECT_ETHER_EINT)
#endif
void Interrupt_EINT(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_USB0_D0FIFO0
#pragma interrupt Interrupt_D0FIFO0(vect=VECT_USB0_D0FIFO0, fint)
#else
#pragma interrupt Interrupt_D0FIFO0(vect=VECT_USB0_D0FIFO0)
#endif
void Interrupt_D0FIFO0(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_USB0_D1FIFO0
#pragma interrupt Interrupt_D1FIFO0(vect=VECT_USB0_D1FIFO0, fint)
#else
#pragma interrupt Interrupt_D1FIFO0(vect=VECT_USB0_D1FIFO0)
#endif
void Interrupt_D1FIFO0(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_USB0_USBI0
#pragma interrupt Interrupt_USBI0(vect=VECT_USB0_USBI0, fint)
#else
#pragma interrupt Interrupt_USBI0(vect=VECT_USB0_USBI0)
#endif
void Interrupt_USBI0(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_USB_USBR0
#pragma interrupt Interrupt_USBR0(vect=VECT_USB_USBR0, fint)
#else
#pragma interrupt Interrupt_USBR0(vect=VECT_USB_USBR0)
#endif
void Interrupt_USBR0(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_USB1_D0FIFO1
#pragma interrupt Interrupt_D0FIFO1(vect=VECT_USB1_D0FIFO1, fint)
#else
#pragma interrupt Interrupt_D0FIFO1(vect=VECT_USB1_D0FIFO1)
#endif
void Interrupt_D0FIFO1(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_USB1_D1FIFO1
#pragma interrupt Interrupt_D1FIFO1(vect=VECT_USB1_D1FIFO1, fint)
#else
#pragma interrupt Interrupt_D1FIFO1(vect=VECT_USB1_D1FIFO1)
#endif
void Interrupt_D1FIFO1(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_USB1_USBI1
#pragma interrupt Interrupt_USBI1(vect=VECT_USB1_USBI1, fint)
#else
#pragma interrupt Interrupt_USBI1(vect=VECT_USB1_USBI1)
#endif
void Interrupt_USBI1(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_USB_USBR1
#pragma interrupt Interrupt_USBR1(vect=VECT_USB_USBR1, fint)
#else
#pragma interrupt Interrupt_USBR1(vect=VECT_USB_USBR1)
#endif
void Interrupt_USBR1(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_CAN0_ERS0
#pragma interrupt Interrupt_ERS0(vect=VECT_CAN0_ERS0, fint)
#else
#pragma interrupt Interrupt_ERS0(vect=VECT_CAN0_ERS0)
#endif
void Interrupt_ERS0(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_CAN0_RXF0
#pragma interrupt Interrupt_RXF0(vect=VECT_CAN0_RXF0, fint)
#else
#pragma interrupt Interrupt_RXF0(vect=VECT_CAN0_RXF0)
#endif
void Interrupt_RXF0(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_CAN0_TXF0
#pragma interrupt Interrupt_TXF0(vect=VECT_CAN0_TXF0, fint)
#else
#pragma interrupt Interrupt_TXF0(vect=VECT_CAN0_TXF0)
#endif
void Interrupt_TXF0(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_CAN0_RXM0
#pragma interrupt Interrupt_RXM0(vect=VECT_CAN0_RXM0, fint)
#else
#pragma interrupt Interrupt_RXM0(vect=VECT_CAN0_RXM0)
#endif
void Interrupt_RXM0(void)
{
	/* The user can put their own code here */
}

#if FAST_INTC_VECTOR == VECT_CAN0_TXM0
#pragma interrupt Interrupt_TXM0(vect=VECT_CAN0_TXM0, fint)
#else
#pragma interrupt Interrupt_TXM0(vect=VECT_CAN0_TXM0)
#endif
void Interrupt_TXM0(void)
{
	/* The user can put their own code here */
}

/* End of file */
