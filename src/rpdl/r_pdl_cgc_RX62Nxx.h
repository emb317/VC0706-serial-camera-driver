/*""FILE COMMENT""*************************************************************
* System Name	: CGC API for RX62Nxx
* File Name		: r_pdl_cgc_RX62Nxx.h
* Version		: 1.11
* Contents		: CGC header
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

#ifndef R_PDL_CGC_RX62Nxx_H
#define R_PDL_CGC_RX62Nxx_H

/* Library prototypes */
bool R_CGC_SetAll(
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const uint32_t,
	const uint16_t
);

bool R_CGC_ControlAll(
	const uint16_t
);

bool R_CGC_GetStatusAll(
	volatile uint8_t * const
);

/* Macro definitions */

#define R_CGC_Set(a, b, c, d, e) \
R_CGC_SetAll( (a), (b), (c), (d), (e) )

#define R_CGC_Control(a) \
R_CGC_ControlAll( (a) )

#define R_CGC_GetStatus(a) \
R_CGC_GetStatusAll( (a) )

#endif
/* End of file */
