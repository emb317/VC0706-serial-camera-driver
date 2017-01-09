/************************************************************************
*
* Device     : RX/RX600/RX621,RX62N
*
* File Name  : vecttbl.c
*
* Abstract   : Initialize of Vector Table.
*
* History    : 1.00 (2010-03-05)  [Hardware Manual Revision : 0.20]
*            : 1.10 (2011-02-21)  [Hardware Manual Revision : 0.50]
*            : 1.11 (2011-06-20)  [Hardware Manual Revision : 1.00]
*            : 1.20 (2013-02-18)  [Hardware Manual Revision : 1.30]
*
* NOTE       : THIS IS A TYPICAL EXAMPLE.
*
* Copyright (C) 2013 (2010,2011) Renesas Electronics Corporation. and
* Renesas Solutions Corp. All rights reserved.
*
************************************************************************/

#include "vect.h"

#if 0
#pragma section C FIXEDVECT

void (*const Fixed_Vectors[])(void) = {
//;0xffffffd0  Exception(Supervisor Instruction)
    Excep_SuperVisorInst,
//;0xffffffd4  Exception(Access Instruction)
    Excep_AccessInst,
//;0xffffffd8  Reserved
    Dummy,
//;0xffffffdc  Exception(Undefined Instruction)
    Excep_UndefinedInst,
//;0xffffffe0  Reserved
    Dummy,
//;0xffffffe4  Exception(Floating Point)
    Excep_FloatingPoint,
//;0xffffffe8  Reserved
    Dummy,
//;0xffffffec  Reserved
    Dummy,
//;0xfffffff0  Reserved
    Dummy,
//;0xfffffff4  Reserved
    Dummy,
//;0xfffffff8  NMI
    NonMaskableInterrupt,
//;0xfffffffc  RESET
//;<<VECTOR DATA START (POWER ON RESET)>>
//;Power On Reset PC
    /*(void*)*/ PowerON_Reset_PC                                                                                                                 
//;<<VECTOR DATA END (POWER ON RESET)>>
};
#endif

#pragma address id_code=0xffffffa0 // ID codes (Default)
const unsigned long id_code[4] = {
        0xffffffff,
        0xffffffff,
        0xffffffff,
        0xffffffff,
};
