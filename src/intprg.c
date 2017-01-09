/************************************************************************
*
* Device     : RX/RX600/RX621,RX62N
*
* File Name  : intprg.c
*
* Abstract   : Interrupt Program.
*
* History    : 1.00  (2010-03-05)  [Hardware Manual Revision : 0.50]
*            : 1.03  (2012-06-18)  [Hardware Manual Revision : 1.30]
*            : 1.10  (2013-02-18)  [Hardware Manual Revision : 1.30]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2013 (2010,2012) Renesas Electronics Corporation. and
* Renesas Solutions Corporation. All rights reserved.
*
*********************************************************************/

#include <machine.h>
#include "vect.h"
#pragma section IntPRG

// Exception(Supervisor Instruction)
void Excep_SuperVisorInst(void){/* brk(); */}

// Exception(Access Instruction)
void Excep_AccessInst(void){/* brk(); */}

// Exception(Undefined Instruction)
// void Excep_UndefinedInst(void){/* brk(); */}

// Exception(Floating Point)
// void Excep_FloatingPoint(void){/* brk(); */}

// NMI
void NonMaskableInterrupt(void){/* brk(); */}

// Dummy
// void Dummy(void){/* brk(); */}

// BRK
void Excep_BRK(void){ wait(); }

// BSC BUSERR
void Excep_BSC_BUSERR(void){ }

// FCU FIFERR
void Excep_FCU_FIFERR(void){ }

// FCU FRDYI
void Excep_FCU_FRDYI(void){ }

// ICU SWINT
void Excep_ICU_SWINT(void){ }

// CMT0 CMI0
void Excep_CMT0_CMI0(void){ }

// CMT1 CMI1
void Excep_CMT1_CMI1(void){ }

// CMT2 CMI2
void Excep_CMT2_CMI2(void){ }

// CMT3 CMI3
void Excep_CMT3_CMI3(void){ }

// ETHER EINT
void Excep_ETHER_EINT(void){ }

// USB0 D0FIFO0
void Excep_USB0_D0FIFO0(void){ }

// USB0 D1FIFO0
void Excep_USB0_D1FIFO0(void){ }

// USB0 USBI0
void Excep_USB0_USBI0(void){ }

// USB1 D0FIFO1
void Excep_USB1_D0FIFO1(void){ }

// USB1 D1FIFO1
void Excep_USB1_D1FIFO1(void){ }

// USB1 USBI1
void Excep_USB1_USBI1(void){ }

// RSPI0 SPEI0
void Excep_RSPI0_SPEI0(void){ }

// RSPI0 SPRI0
void Excep_RSPI0_SPRI0(void){ }

// RSPI0 SPTI0
void Excep_RSPI0_SPTI0(void){ }

// RSPI0 SPII0
void Excep_RSPI0_SPII0(void){ }

// RSPI1 SPEI1
void Excep_RSPI1_SPEI1(void){ }

// RSPI1 SPRI1
void Excep_RSPI1_SPRI1(void){ }

// RSPI1 SPTI1
void Excep_RSPI1_SPTI1(void){ }

// RSPI1 SPII1
void Excep_RSPI1_SPII1(void){ }

// CAN0 ERS0
void Excep_CAN0_ERS0(void){ }

// CAN0 RXF0
void Excep_CAN0_RXF0(void){ }

// CAN0 TXF0
void Excep_CAN0_TXF0(void){ }

// CAN0 RXM0
void Excep_CAN0_RXM0(void){ }

// CAN0 TXM0
void Excep_CAN0_TXM0(void){ }

// RTC PRD
void Excep_RTC_PRD(void){ }

// RTC CUP
void Excep_RTC_CUP(void){ }

// ICU IRQ0
void Excep_ICU_IRQ0(void){ }

// ICU IRQ1
void Excep_ICU_IRQ1(void){ }

// ICU IRQ2
void Excep_ICU_IRQ2(void){ }

// ICU IRQ3
void Excep_ICU_IRQ3(void){ }

// ICU IRQ4
void Excep_ICU_IRQ4(void){ }

// ICU IRQ5
void Excep_ICU_IRQ5(void){ }

// ICU IRQ6
void Excep_ICU_IRQ6(void){ }

// ICU IRQ7
void Excep_ICU_IRQ7(void){ }

// ICU IRQ8
void Excep_ICU_IRQ8(void){ }

// ICU IRQ9
void Excep_ICU_IRQ9(void){ }

// ICU IRQ10
void Excep_ICU_IRQ10(void){ }

// ICU IRQ11
void Excep_ICU_IRQ11(void){ }

// ICU IRQ12
void Excep_ICU_IRQ12(void){ }

// ICU IRQ13
void Excep_ICU_IRQ13(void){ }

// ICU IRQ14
void Excep_ICU_IRQ14(void){ }

// ICU IRQ15
void Excep_ICU_IRQ15(void){ }

// USB USBR0
void Excep_USB_USBR0(void){ }

// USB USBR1
void Excep_USB_USBR1(void){ }

// RTC ALM
void Excep_RTC_ALM(void){ }

// WDT WOVI
void Excep_WDT_WOVI(void){ }

// AD0 ADI0
void Excep_AD0_ADI0(void){ }

// AD1 ADI1
void Excep_AD1_ADI1(void){ }

// S12AD ADI
void Excep_S12AD_ADI(void){ }

// MTU0 TGIA0
void Excep_MTU0_TGIA0(void){ }

// MTU0 TGIB0
void Excep_MTU0_TGIB0(void){ }

// MTU0 TGIC0
void Excep_MTU0_TGIC0(void){ }

// MTU0 TGID0
void Excep_MTU0_TGID0(void){ }

// MTU0 TCIV0
void Excep_MTU0_TCIV0(void){ }

// MTU0 TGIE0
void Excep_MTU0_TGIE0(void){ }

// MTU0 TGIF0
void Excep_MTU0_TGIF0(void){ }

// MTU1 TGIA1
void Excep_MTU1_TGIA1(void){ }

// MTU1 TGIB1
void Excep_MTU1_TGIB1(void){ }

// MTU1 TCIV1
void Excep_MTU1_TCIV1(void){ }

// MTU1 TCIU1
void Excep_MTU1_TCIU1(void){ }

// MTU2 TGIA2
void Excep_MTU2_TGIA2(void){ }

// MTU2 TGIB2
void Excep_MTU2_TGIB2(void){ }

// MTU2 TCIV2
void Excep_MTU2_TCIV2(void){ }

// MTU2 TCIU2
void Excep_MTU2_TCIU2(void){ }

// MTU3 TGIA3
void Excep_MTU3_TGIA3(void){ }

// MTU3 TGIB3
void Excep_MTU3_TGIB3(void){ }

// MTU3 TGIC3
void Excep_MTU3_TGIC3(void){ }

// MTU3 TGID3
void Excep_MTU3_TGID3(void){ }

// MTU3 TCIV3
void Excep_MTU3_TCIV3(void){ }

// MTU4 TGIA4
void Excep_MTU4_TGIA4(void){ }

// MTU4 TGIB4
void Excep_MTU4_TGIB4(void){ }

// MTU4 TGIC4
void Excep_MTU4_TGIC4(void){ }

// MTU4 TGID4
void Excep_MTU4_TGID4(void){ }

// MTU4 TCIV4
void Excep_MTU4_TCIV4(void){ }

// MTU5 TGIU5
void Excep_MTU5_TGIU5(void){ }

// MTU5 TGIV5
void Excep_MTU5_TGIV5(void){ }

// MTU5 TGIW5
void Excep_MTU5_TGIW5(void){ }

// MTU6 TGIA6
void Excep_MTU6_TGIA6(void){ }

// MTU6 TGIB6
void Excep_MTU6_TGIB6(void){ }

// MTU6 TGIC6
void Excep_MTU6_TGIC6(void){ }

// MTU6 TGID6
void Excep_MTU6_TGID6(void){ }

// MTU6 TCIV6
void Excep_MTU6_TCIV6(void){ }

// MTU6 TGIE6
void Excep_MTU6_TGIE6(void){ }

// MTU6 TGIF6
void Excep_MTU6_TGIF6(void){ }

// MTU7 TGIA7
void Excep_MTU7_TGIA7(void){ }

// MTU7 TGIB7
void Excep_MTU7_TGIB7(void){ }

// MTU7 TCIV7
void Excep_MTU7_TCIV7(void){ }

// MTU7 TCIU7
void Excep_MTU7_TCIU7(void){ }

// MTU8 TGIA8
void Excep_MTU8_TGIA8(void){ }

// MTU8 TGIB8
void Excep_MTU8_TGIB8(void){ }

// MTU8 TCIV8
void Excep_MTU8_TCIV8(void){ }

// MTU8 TCIU8
void Excep_MTU8_TCIU8(void){ }

// MTU9 TGIA9
void Excep_MTU9_TGIA9(void){ }

// MTU9 TGIB9
void Excep_MTU9_TGIB9(void){ }

// MTU9 TGIC9
void Excep_MTU9_TGIC9(void){ }

// MTU9 TGID9
void Excep_MTU9_TGID9(void){ }

// MTU9 TCIV9
void Excep_MTU9_TCIV9(void){ }

// MTU10 TGIA10
void Excep_MTU10_TGIA10(void){ }

// MTU10 TGIB10
void Excep_MTU10_TGIB10(void){ }

// MTU10 TGIC10
void Excep_MTU10_TGIC10(void){ }

// MTU10 TGID10
void Excep_MTU10_TGID10(void){ }

// MTU10 TCIV10
void Excep_MTU10_TCIV10(void){ }

// MTU11 TGIU11
void Excep_MTU11_TGIU11(void){ }

// MTU11 TGIV11
void Excep_MTU11_TGIV11(void){ }

// MTU11 TGIW11
void Excep_MTU11_TGIW11(void){ }

// POE OEI1
void Excep_POE_OEI1(void){ }

// POE OEI2
void Excep_POE_OEI2(void){ }

// POE OEI3
void Excep_POE_OEI3(void){ }

// POE OEI4
void Excep_POE_OEI4(void){ }

// TMR0 CMIA0
void Excep_TMR0_CMIA0(void){ }

// TMR0 CMIB0
void Excep_TMR0_CMIB0(void){ }

// TMR0 OVI0
void Excep_TMR0_OVI0(void){ }

// TMR1 CMIA1
void Excep_TMR1_CMIA1(void){ }

// TMR1 CMIB1
void Excep_TMR1_CMIB1(void){ }

// TMR1 OVI1
void Excep_TMR1_OVI1(void){ }

// TMR2 CMIA2
void Excep_TMR2_CMIA2(void){ }

// TMR2 CMIB2
void Excep_TMR2_CMIB2(void){ }

// TMR2 OVI2
void Excep_TMR2_OVI2(void){ }

// TMR3 CMIA3
void Excep_TMR3_CMIA3(void){ }

// TMR3 CMIB3
void Excep_TMR3_CMIB3(void){ }

// TMR3 OVI3
void Excep_TMR3_OVI3(void){ }

// DMAC DMAC0I
void Excep_DMAC_DMAC0I(void){ }

// DMAC DMAC1I
void Excep_DMAC_DMAC1I(void){ }

// DMAC DMAC2I
void Excep_DMAC_DMAC2I(void){ }

// DMAC DMAC3I
void Excep_DMAC_DMAC3I(void){ }

// EXDMAC EXDMAC0I
void Excep_EXDMAC_EXDMAC0I(void){ }

// EXDMAC EXDMAC1I
void Excep_EXDMAC_EXDMAC1I(void){ }

#ifndef SELECT_SCI0
// SCI0 ERI0
void Excep_SCI0_ERI0(void){ }

// SCI0 RXI0
void Excep_SCI0_RXI0(void){ }

// SCI0 TXI0
void Excep_SCI0_TXI0(void){ }

// SCI0 TEI0
void Excep_SCI0_TEI0(void){ }
#endif

#ifndef SELECT_SCI1
// SCI1 ERI1
void Excep_SCI1_ERI1(void){ }

// SCI1 RXI1
void Excep_SCI1_RXI1(void){ }

// SCI1 TXI1
void Excep_SCI1_TXI1(void){ }

// SCI1 TEI1
void Excep_SCI1_TEI1(void){ }
#endif

#ifndef SELECT_SCI2
// SCI2 ERI2
void Excep_SCI2_ERI2(void){ }

// SCI2 RXI2
void Excep_SCI2_RXI2(void){ }

// SCI2 TXI2
void Excep_SCI2_TXI2(void){ }

// SCI2 TEI2
void Excep_SCI2_TEI2(void){ }
#endif

#ifndef SELECT_SCI3
// SCI3 ERI3
void Excep_SCI3_ERI3(void){ }

// SCI3 RXI3
void Excep_SCI3_RXI3(void){ }

// SCI3 TXI3
void Excep_SCI3_TXI3(void){ }

// SCI3 TEI3
void Excep_SCI3_TEI3(void){ }
#endif

#ifndef SELECT_SCI5
// SCI5 ERI5
void Excep_SCI5_ERI5(void){ }

// SCI5 RXI5
void Excep_SCI5_RXI5(void){ }

// SCI5 TXI5
void Excep_SCI5_TXI5(void){ }

// SCI5 TEI5
void Excep_SCI5_TEI5(void){ }
#endif

#ifndef SELECT_SCI6
// SCI6 ERI6
void Excep_SCI6_ERI6(void){ }

// SCI6 RXI6
void Excep_SCI6_RXI6(void){ }

// SCI6 TXI6
void Excep_SCI6_TXI6(void){ }

// SCI6 TEI6
void Excep_SCI6_TEI6(void){ }
#endif

// RIIC0 ICEEI0
void Excep_RIIC0_ICEEI0(void){ }

// RIIC0 ICRXI0
void Excep_RIIC0_ICRXI0(void){ }

// RIIC0 ICTXI0
void Excep_RIIC0_ICTXI0(void){ }

// RIIC0 ICTEI0
void Excep_RIIC0_ICTEI0(void){ }

// RIIC1 ICEEI1
void Excep_RIIC1_ICEEI1(void){ }

// RIIC1 ICRXI1
void Excep_RIIC1_ICRXI1(void){ }

// RIIC1 ICTXI1
void Excep_RIIC1_ICTXI1(void){ }

// RIIC1 ICTEI1
void Excep_RIIC1_ICTEI1(void){ }

