/************************************************************************
*
* Device     : RX/RX600/RX621,RX62N
*
* File Name  : vect.h
*
* Abstract   : Definition of Vector.
*
* History    : 1.00  (2010-03-05) [Hardware Manual Revision : 0.50]
*            : 1.01  (2010-03-15) [Hardware Manual Revision : 0.50]
*            : 1.02  (2011-06-20) [Hardware Manual Revision : 1.0]
*            : 1.02  (2011-06-20) [Hardware Manual Revision : 1.0]
*            : 1.03  (2012-06-12) [Hardware Manual Revision : 1.30]
*            : 1.10  (2013-02-18) [Hardware Manual Revision : 1.30]
*            : 1.10a (2013-06-18) [Hardware Manual Revision : 1.30]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2013 (2010-2012) Renesas Electronics Corporation and
* Renesas Solutions Corp.  All rights reserved.
*
************************************************************************/

// Exception(Supervisor Instruction)
#pragma interrupt (Excep_SuperVisorInst)
void Excep_SuperVisorInst(void);

// Exception(Access Instruction)
#pragma interrupt (Excep_AccessInst)
void Excep_AccessInst(void);

// Exception(Undefined Instruction)
#pragma interrupt (Excep_UndefinedInst)
void Excep_UndefinedInst(void);

// Exception(Floating Point)
#pragma interrupt (Excep_FloatingPoint)
void Excep_FloatingPoint(void);

// NMI
#pragma interrupt (NonMaskableInterrupt)
void NonMaskableInterrupt(void);

// Dummy
#pragma interrupt (Dummy)
void Dummy(void);

// BRK
#pragma interrupt (Excep_BRK(vect=0))
void Excep_BRK(void);

// vector  1 reserved
// vector  2 reserved
// vector  3 reserved
// vector  4 reserved
// vector  5 reserved
// vector  6 reserved
// vector  7 reserved
// vector  8 reserved
// vector  9 reserved
// vector 10 reserved
// vector 11 reserved
// vector 12 reserved
// vector 13 reserved
// vector 14 reserved
// vector 15 reserved

// BSC BUSERR
#pragma interrupt (Excep_BSC_BUSERR(vect=16))
void Excep_BSC_BUSERR(void);

// FCU FIFERR
#pragma interrupt (Excep_FCU_FIFERR(vect=21))
void Excep_FCU_FIFERR(void);

// FCU FRDYI
#pragma interrupt (Excep_FCU_FRDYI(vect=23))
void Excep_FCU_FRDYI(void);

// ICU SWINT
#pragma interrupt (Excep_ICU_SWINT(vect=27))
void Excep_ICU_SWINT(void);

// CMT0 CMI0
#pragma interrupt (Excep_CMT0_CMI0(vect=28))
void Excep_CMT0_CMI0(void);

// CMT1 CMI1
#pragma interrupt (Excep_CMT1_CMI1(vect=29))
void Excep_CMT1_CMI1(void);

// CMT2 CMI2
#pragma interrupt (Excep_CMT2_CMI2(vect=30))
void Excep_CMT2_CMI2(void);

// CMT3 CMI3
#pragma interrupt (Excep_CMT3_CMI3(vect=31))
void Excep_CMT3_CMI3(void);

// ETHER EINT
#pragma interrupt (Excep_ETHER_EINT(vect=32))
void Excep_ETHER_EINT(void);

// USB0 D0FIFO0
#pragma interrupt (Excep_USB0_D0FIFO0(vect=36))
void Excep_USB0_D0FIFO0(void);

// USB0 D1FIFO0
#pragma interrupt (Excep_USB0_D1FIFO0(vect=37))
void Excep_USB0_D1FIFO0(void);

// USB0 USBI0
#pragma interrupt (Excep_USB0_USBI0(vect=38))
void Excep_USB0_USBI0(void);

// USB1 D0FIFO1
#pragma interrupt (Excep_USB1_D0FIFO1(vect=40))
void Excep_USB1_D0FIFO1(void);

// USB1 D1FIFO1
#pragma interrupt (Excep_USB1_D1FIFO1(vect=41))
void Excep_USB1_D1FIFO1(void);

// USB1 USBI1
#pragma interrupt (Excep_USB1_USBI1(vect=42))
void Excep_USB1_USBI1(void);

// RSPI0 SPEI0
#pragma interrupt (Excep_RSPI0_SPEI0(vect=44))
void Excep_RSPI0_SPEI0(void);

// RSPI0 SPRI0
#pragma interrupt (Excep_RSPI0_SPRI0(vect=45))
void Excep_RSPI0_SPRI0(void);

// RSPI0 SPTI0
#pragma interrupt (Excep_RSPI0_SPTI0(vect=46))
void Excep_RSPI0_SPTI0(void);

// RSPI0 SPII0
#pragma interrupt (Excep_RSPI0_SPII0(vect=47))
void Excep_RSPI0_SPII0(void);

// RSPI1 SPEI1
#pragma interrupt (Excep_RSPI1_SPEI1(vect=48))
void Excep_RSPI1_SPEI1(void);

// RSPI1 SPRI1
#pragma interrupt (Excep_RSPI1_SPRI1(vect=49))
void Excep_RSPI1_SPRI1(void);

// RSPI1 SPTI1
#pragma interrupt (Excep_RSPI1_SPTI1(vect=50))
void Excep_RSPI1_SPTI1(void);

// RSPI1 SPII1
#pragma interrupt (Excep_RSPI1_SPII1(vect=51))
void Excep_RSPI1_SPII1(void);

// CAN0 ERS0
#pragma interrupt (Excep_CAN0_ERS0(vect=56))
void Excep_CAN0_ERS0(void);

// CAN0 RXF0
#pragma interrupt (Excep_CAN0_RXF0(vect=57))
void Excep_CAN0_RXF0(void);

// CAN0 TXF0
#pragma interrupt (Excep_CAN0_TXF0(vect=58))
void Excep_CAN0_TXF0(void);

// CAN0 RXM0
#pragma interrupt (Excep_CAN0_RXM0(vect=59))
void Excep_CAN0_RXM0(void);

// CAN0 TXM0
#pragma interrupt (Excep_CAN0_TXM0(vect=60))
void Excep_CAN0_TXM0(void);

// RTC PRD
#pragma interrupt (Excep_RTC_PRD(vect=62))
void Excep_RTC_PRD(void);

// RTC CUP
#pragma interrupt (Excep_RTC_CUP(vect=63))
void Excep_RTC_CUP(void);

// ICU IRQ0
#pragma interrupt (Excep_ICU_IRQ0(vect=64))
void Excep_ICU_IRQ0(void);

// ICU IRQ1
#pragma interrupt (Excep_ICU_IRQ1(vect=65))
void Excep_ICU_IRQ1(void);

// ICU IRQ2
#pragma interrupt (Excep_ICU_IRQ2(vect=66))
void Excep_ICU_IRQ2(void);

// ICU IRQ3
#pragma interrupt (Excep_ICU_IRQ3(vect=67))
void Excep_ICU_IRQ3(void);

// ICU IRQ4
#pragma interrupt (Excep_ICU_IRQ4(vect=68))
void Excep_ICU_IRQ4(void);

// ICU IRQ5
#pragma interrupt (Excep_ICU_IRQ5(vect=69))
void Excep_ICU_IRQ5(void);

// ICU IRQ6
#pragma interrupt (Excep_ICU_IRQ6(vect=70))
void Excep_ICU_IRQ6(void);

// ICU IRQ7
#pragma interrupt (Excep_ICU_IRQ7(vect=71))
void Excep_ICU_IRQ7(void);

// ICU IRQ8
#pragma interrupt (Excep_ICU_IRQ8(vect=72))
void Excep_ICU_IRQ8(void);

// ICU IRQ9
#pragma interrupt (Excep_ICU_IRQ9(vect=73))
void Excep_ICU_IRQ9(void);

// ICU IRQ10
#pragma interrupt (Excep_ICU_IRQ10(vect=74))
void Excep_ICU_IRQ10(void);

// ICU IRQ11
#pragma interrupt (Excep_ICU_IRQ11(vect=75))
void Excep_ICU_IRQ11(void);

// ICU IRQ12
#pragma interrupt (Excep_ICU_IRQ12(vect=76))
void Excep_ICU_IRQ12(void);

// ICU IRQ13
#pragma interrupt (Excep_ICU_IRQ13(vect=77))
void Excep_ICU_IRQ13(void);

// ICU IRQ14
#pragma interrupt (Excep_ICU_IRQ14(vect=78))
void Excep_ICU_IRQ14(void);

// ICU IRQ15
#pragma interrupt (Excep_ICU_IRQ15(vect=79))
void Excep_ICU_IRQ15(void);

// USB USBR0
#pragma interrupt (Excep_USB_USBR0(vect=90))
void Excep_USB_USBR0(void);

// USB USBR1
#pragma interrupt (Excep_USB_USBR1(vect=91))
void Excep_USB_USBR1(void);

// RTC ALM
#pragma interrupt (Excep_RTC_ALM(vect=92))
void Excep_RTC_ALM(void);

// WDT WOVI
#pragma interrupt (Excep_WDT_WOVI(vect=96))
void Excep_WDT_WOVI(void);

// AD0 ADI0
//#pragma interrupt (Excep_AD0_ADI0(vect=98))
void Excep_AD0_ADI0(void);

// AD1 ADI1
//#pragma interrupt (Excep_AD1_ADI1(vect=99))
void Excep_AD1_ADI1(void);

// S12AD ADI
//#pragma interrupt (Excep_S12AD_ADI(vect=102))
void Excep_S12AD_ADI(void);

// MTU0 TGIA0
#pragma interrupt (Excep_MTU0_TGIA0(vect=114))
void Excep_MTU0_TGIA0(void);

// MTU0 TGIB0
#pragma interrupt (Excep_MTU0_TGIB0(vect=115))
void Excep_MTU0_TGIB0(void);

// MTU0 TGIC0
#pragma interrupt (Excep_MTU0_TGIC0(vect=116))
void Excep_MTU0_TGIC0(void);

// MTU0 TGID0
#pragma interrupt (Excep_MTU0_TGID0(vect=117))
void Excep_MTU0_TGID0(void);

// MTU0 TCIV0
#pragma interrupt (Excep_MTU0_TCIV0(vect=118))
void Excep_MTU0_TCIV0(void);

// MTU0 TGIE0
#pragma interrupt (Excep_MTU0_TGIE0(vect=119))
void Excep_MTU0_TGIE0(void);

// MTU0 TGIF0
#pragma interrupt (Excep_MTU0_TGIF0(vect=120))
void Excep_MTU0_TGIF0(void);

// MTU1 TGIA1
#pragma interrupt (Excep_MTU1_TGIA1(vect=121))
void Excep_MTU1_TGIA1(void);

// MTU1 TGIB1
#pragma interrupt (Excep_MTU1_TGIB1(vect=122))
void Excep_MTU1_TGIB1(void);

// MTU1 TCIV1
#pragma interrupt (Excep_MTU1_TCIV1(vect=123))
void Excep_MTU1_TCIV1(void);

// MTU1 TCIU1
#pragma interrupt (Excep_MTU1_TCIU1(vect=124))
void Excep_MTU1_TCIU1(void);

// MTU2 TGIA2
#pragma interrupt (Excep_MTU2_TGIA2(vect=125))
void Excep_MTU2_TGIA2(void);

// MTU2 TGIB2
#pragma interrupt (Excep_MTU2_TGIB2(vect=126))
void Excep_MTU2_TGIB2(void);

// MTU2 TCIV2
#pragma interrupt (Excep_MTU2_TCIV2(vect=127))
void Excep_MTU2_TCIV2(void);

// MTU2 TCIU2
#pragma interrupt (Excep_MTU2_TCIU2(vect=128))
void Excep_MTU2_TCIU2(void);

// MTU3 TGIA3
#pragma interrupt (Excep_MTU3_TGIA3(vect=129))
void Excep_MTU3_TGIA3(void);

// MTU3 TGIB3
#pragma interrupt (Excep_MTU3_TGIB3(vect=130))
void Excep_MTU3_TGIB3(void);

// MTU3 TGIC3
#pragma interrupt (Excep_MTU3_TGIC3(vect=131))
void Excep_MTU3_TGIC3(void);

// MTU3 TGID3
#pragma interrupt (Excep_MTU3_TGID3(vect=132))
void Excep_MTU3_TGID3(void);

// MTU3 TCIV3
#pragma interrupt (Excep_MTU3_TCIV3(vect=133))
void Excep_MTU3_TCIV3(void);

// MTU4 TGIA4
#pragma interrupt (Excep_MTU4_TGIA4(vect=134))
void Excep_MTU4_TGIA4(void);

// MTU4 TGIB4
#pragma interrupt (Excep_MTU4_TGIB4(vect=135))
void Excep_MTU4_TGIB4(void);

// MTU4 TGIC4
#pragma interrupt (Excep_MTU4_TGIC4(vect=136))
void Excep_MTU4_TGIC4(void);

// MTU4 TGID4
#pragma interrupt (Excep_MTU4_TGID4(vect=137))
void Excep_MTU4_TGID4(void);

// MTU4 TCIV4
#pragma interrupt (Excep_MTU4_TCIV4(vect=138))
void Excep_MTU4_TCIV4(void);

// MTU5 TGIU5
#pragma interrupt (Excep_MTU5_TGIU5(vect=139))
void Excep_MTU5_TGIU5(void);

// MTU5 TGIV5
#pragma interrupt (Excep_MTU5_TGIV5(vect=140))
void Excep_MTU5_TGIV5(void);

// MTU5 TGIW5
#pragma interrupt (Excep_MTU5_TGIW5(vect=141))
void Excep_MTU5_TGIW5(void);

// MTU6 TGIA6
#pragma interrupt (Excep_MTU6_TGIA6(vect=142))
void Excep_MTU6_TGIA6(void);

// MTU6 TGIB6
#pragma interrupt (Excep_MTU6_TGIB6(vect=143))
void Excep_MTU6_TGIB6(void);

// MTU6 TGIC6
#pragma interrupt (Excep_MTU6_TGIC6(vect=144))
void Excep_MTU6_TGIC6(void);

// MTU6 TGID6
#pragma interrupt (Excep_MTU6_TGID6(vect=145))
void Excep_MTU6_TGID6(void);

// MTU6 TCIV6
#pragma interrupt (Excep_MTU6_TCIV6(vect=146))
void Excep_MTU6_TCIV6(void);

// MTU6 TGIE6
#pragma interrupt (Excep_MTU6_TGIE6(vect=147))
void Excep_MTU6_TGIE6(void);

// MTU6 TGIF6
#pragma interrupt (Excep_MTU6_TGIF6(vect=148))
void Excep_MTU6_TGIF6(void);

// MTU7 TGIA7
#pragma interrupt (Excep_MTU7_TGIA7(vect=149))
void Excep_MTU7_TGIA7(void);

// MTU7 TGIB7
#pragma interrupt (Excep_MTU7_TGIB7(vect=150))
void Excep_MTU7_TGIB7(void);

// MTU7 TCIV7
#pragma interrupt (Excep_MTU7_TCIV7(vect=151))
void Excep_MTU7_TCIV7(void);

// MTU7 TCIU7
#pragma interrupt (Excep_MTU7_TCIU7(vect=152))
void Excep_MTU7_TCIU7(void);

// MTU8 TGIA8
#pragma interrupt (Excep_MTU8_TGIA8(vect=153))
void Excep_MTU8_TGIA8(void);

// MTU8 TGIB8
#pragma interrupt (Excep_MTU8_TGIB8(vect=154))
void Excep_MTU8_TGIB8(void);

// MTU8 TCIV8
#pragma interrupt (Excep_MTU8_TCIV8(vect=155))
void Excep_MTU8_TCIV8(void);

// MTU8 TCIU8
#pragma interrupt (Excep_MTU8_TCIU8(vect=156))
void Excep_MTU8_TCIU8(void);

// MTU9 TGIA9
#pragma interrupt (Excep_MTU9_TGIA9(vect=157))
void Excep_MTU9_TGIA9(void);

// MTU9 TGIB9
#pragma interrupt (Excep_MTU9_TGIB9(vect=158))
void Excep_MTU9_TGIB9(void);

// MTU9 TGIC9
#pragma interrupt (Excep_MTU9_TGIC9(vect=159))
void Excep_MTU9_TGIC9(void);

// MTU9 TGID9
#pragma interrupt (Excep_MTU9_TGID9(vect=160))
void Excep_MTU9_TGID9(void);

// MTU9 TCIV9
#pragma interrupt (Excep_MTU9_TCIV9(vect=161))
void Excep_MTU9_TCIV9(void);

// MTU10 TGIA10
#pragma interrupt (Excep_MTU10_TGIA10(vect=162))
void Excep_MTU10_TGIA10(void);

// MTU10 TGIB10
#pragma interrupt (Excep_MTU10_TGIB10(vect=163))
void Excep_MTU10_TGIB10(void);

// MTU10 TGIC10
#pragma interrupt (Excep_MTU10_TGIC10(vect=164))
void Excep_MTU10_TGIC10(void);

// MTU10 TGID10
#pragma interrupt (Excep_MTU10_TGID10(vect=165))
void Excep_MTU10_TGID10(void);

// MTU10 TCIV10
#pragma interrupt (Excep_MTU10_TCIV10(vect=166))
void Excep_MTU10_TCIV10(void);

// MTU11 TGIU11
#pragma interrupt (Excep_MTU11_TGIU11(vect=167))
void Excep_MTU11_TGIU11(void);

// MTU11 TGIV11
#pragma interrupt (Excep_MTU11_TGIV11(vect=168))
void Excep_MTU11_TGIV11(void);

// MTU11 TGIW11
#pragma interrupt (Excep_MTU11_TGIW11(vect=169))
void Excep_MTU11_TGIW11(void);

// POE OEI1
#pragma interrupt (Excep_POE_OEI1(vect=170))
void Excep_POE_OEI1(void);

// POE OEI2
#pragma interrupt (Excep_POE_OEI2(vect=171))
void Excep_POE_OEI2(void);

// POE OEI3
#pragma interrupt (Excep_POE_OEI3(vect=172))
void Excep_POE_OEI3(void);

// POE OEI4
#pragma interrupt (Excep_POE_OEI4(vect=173))
void Excep_POE_OEI4(void);

// TMR0 CMIA0
#pragma interrupt (Excep_TMR0_CMIA0(vect=174))
void Excep_TMR0_CMIA0(void);

// TMR0 CMIB0
#pragma interrupt (Excep_TMR0_CMIB0(vect=175))
void Excep_TMR0_CMIB0(void);

// TMR0 OVI0
#pragma interrupt (Excep_TMR0_OVI0(vect=176))
void Excep_TMR0_OVI0(void);

// TMR1 CMIA1
#pragma interrupt (Excep_TMR1_CMIA1(vect=177))
void Excep_TMR1_CMIA1(void);

// TMR1 CMIB1
#pragma interrupt (Excep_TMR1_CMIB1(vect=178))
void Excep_TMR1_CMIB1(void);

// TMR1 OVI1
#pragma interrupt (Excep_TMR1_OVI1(vect=179))
void Excep_TMR1_OVI1(void);

// TMR2 CMIA2
#pragma interrupt (Excep_TMR2_CMIA2(vect=180))
void Excep_TMR2_CMIA2(void);

// TMR2 CMIB2
#pragma interrupt (Excep_TMR2_CMIB2(vect=181))
void Excep_TMR2_CMIB2(void);

// TMR2 OVI2
#pragma interrupt (Excep_TMR2_OVI2(vect=182))
void Excep_TMR2_OVI2(void);

// TMR3 CMIA3
#pragma interrupt (Excep_TMR3_CMIA3(vect=183))
void Excep_TMR3_CMIA3(void);

// TMR3 CMIB3
#pragma interrupt (Excep_TMR3_CMIB3(vect=184))
void Excep_TMR3_CMIB3(void);

// TMR3 OVI3
#pragma interrupt (Excep_TMR3_OVI3(vect=185))
void Excep_TMR3_OVI3(void);

// DMAC DMAC0I
#pragma interrupt (Excep_DMAC_DMAC0I(vect=198))
void Excep_DMAC_DMAC0I(void);

// DMAC DMAC1I
#pragma interrupt (Excep_DMAC_DMAC1I(vect=199))
void Excep_DMAC_DMAC1I(void);

// DMAC DMAC2I
#pragma interrupt (Excep_DMAC_DMAC2I(vect=200))
void Excep_DMAC_DMAC2I(void);

// DMAC DMAC3I
#pragma interrupt (Excep_DMAC_DMAC3I(vect=201))
void Excep_DMAC_DMAC3I(void);

// EXDMAC EXDMAC0I
#pragma interrupt (Excep_EXDMAC_EXDMAC0I(vect=202))
void Excep_EXDMAC_EXDMAC0I(void);

// EXDMAC EXDMAC1I
#pragma interrupt (Excep_EXDMAC_EXDMAC1I(vect=203))
void Excep_EXDMAC_EXDMAC1I(void);

#ifndef SELECT_SCI0
// SCI0 ERI0
#pragma interrupt (Excep_SCI0_ERI0(vect=214))
void Excep_SCI0_ERI0(void);

// SCI0 RXI0
#pragma interrupt (Excep_SCI0_RXI0(vect=215))
void Excep_SCI0_RXI0(void);

// SCI0 TXI0
#pragma interrupt (Excep_SCI0_TXI0(vect=216))
void Excep_SCI0_TXI0(void);

// SCI0 TEI0
#pragma interrupt (Excep_SCI0_TEI0(vect=217))
void Excep_SCI0_TEI0(void);
#endif

#ifndef SELECT_SCI1
// SCI1 ERI1
#pragma interrupt (Excep_SCI1_ERI1(vect=218))
void Excep_SCI1_ERI1(void);

// SCI1 RXI1
#pragma interrupt (Excep_SCI1_RXI1(vect=219))
void Excep_SCI1_RXI1(void);

// SCI1 TXI1
#pragma interrupt (Excep_SCI1_TXI1(vect=220))
void Excep_SCI1_TXI1(void);

// SCI1 TEI1
#pragma interrupt (Excep_SCI1_TEI1(vect=221))
void Excep_SCI1_TEI1(void);
#endif

#ifndef SELECT_SCI2
// SCI2 ERI2
#pragma interrupt (Excep_SCI2_ERI2(vect=222))
void Excep_SCI2_ERI2(void);

// SCI2 RXI2
#pragma interrupt (Excep_SCI2_RXI2(vect=223))
void Excep_SCI2_RXI2(void);

// SCI2 TXI2
#pragma interrupt (Excep_SCI2_TXI2(vect=224))
void Excep_SCI2_TXI2(void);

// SCI2 TEI2
#pragma interrupt (Excep_SCI2_TEI2(vect=225))
void Excep_SCI2_TEI2(void);
#endif

#ifndef SELECT_SCI3
// SCI3 ERI3
#pragma interrupt (Excep_SCI3_ERI3(vect=226))
void Excep_SCI3_ERI3(void);

// SCI3 RXI3
#pragma interrupt (Excep_SCI3_RXI3(vect=227))
void Excep_SCI3_RXI3(void);

// SCI3 TXI3
#pragma interrupt (Excep_SCI3_TXI3(vect=228))
void Excep_SCI3_TXI3(void);

// SCI3 TEI3
#pragma interrupt (Excep_SCI3_TEI3(vect=229))
void Excep_SCI3_TEI3(void);
#endif

#ifndef SELECT_SCI5
// SCI5 ERI5
#pragma interrupt (Excep_SCI5_ERI5(vect=234))
void Excep_SCI5_ERI5(void);

// SCI5 RXI5
#pragma interrupt (Excep_SCI5_RXI5(vect=235))
void Excep_SCI5_RXI5(void);

// SCI5 TXI5
#pragma interrupt (Excep_SCI5_TXI5(vect=236))
void Excep_SCI5_TXI5(void);

// SCI5 TEI5
#pragma interrupt (Excep_SCI5_TEI5(vect=237))
void Excep_SCI5_TEI5(void);
#endif

#ifndef SELECT_SCI6
// SCI6 ERI6
#pragma interrupt (Excep_SCI6_ERI6(vect=238))
void Excep_SCI6_ERI6(void);

// SCI6 RXI6
#pragma interrupt (Excep_SCI6_RXI6(vect=239))
void Excep_SCI6_RXI6(void);

// SCI6 TXI6
#pragma interrupt (Excep_SCI6_TXI6(vect=240))
void Excep_SCI6_TXI6(void);

// SCI6 TEI6
#pragma interrupt (Excep_SCI6_TEI6(vect=241))
void Excep_SCI6_TEI6(void);
#endif

// RIIC0 ICEEI0
#pragma interrupt (Excep_RIIC0_ICEEI0(vect=246))
void Excep_RIIC0_ICEEI0(void);

// RIIC0 ICRXI0
#pragma interrupt (Excep_RIIC0_ICRXI0(vect=247))
void Excep_RIIC0_ICRXI0(void);

// RIIC0 ICTXI0
#pragma interrupt (Excep_RIIC0_ICTXI0(vect=248))
void Excep_RIIC0_ICTXI0(void);

// RIIC0 ICTEI0
#pragma interrupt (Excep_RIIC0_ICTEI0(vect=249))
void Excep_RIIC0_ICTEI0(void);

// RIIC1 ICEEI1
#pragma interrupt (Excep_RIIC1_ICEEI1(vect=250))
void Excep_RIIC1_ICEEI1(void);

// RIIC1 ICRXI1
#pragma interrupt (Excep_RIIC1_ICRXI1(vect=251))
void Excep_RIIC1_ICRXI1(void);

// RIIC1 ICTXI1
#pragma interrupt (Excep_RIIC1_ICTXI1(vect=252))
void Excep_RIIC1_ICTXI1(void);

// RIIC1 ICTEI1
#pragma interrupt (Excep_RIIC1_ICTEI1(vect=253))
void Excep_RIIC1_ICTEI1(void);


//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
extern void PowerON_Reset_PC(void);                                                                                                                
//;<<VECTOR DATA END (POWER ON RESET)>>

