/*""FILE COMMENT""*************************************************************
* System Name	: Serial Communication Interface API for RX62Nxx
* File Name		: r_pdl_sci_RX62Nxx.h
* Version		: 1.11
* Contents		: Serial Interface API header
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

#ifndef R_PDL_SCI_RX62Nxx_H
#define R_PDL_SCI_RX62Nxx_H

#define SCI_NUM_CHANNELS 7

#define SCI_INVALID_CHANNEL(a) ( ((a) >= SCI_NUM_CHANNELS) || ((a) == 4) ? true : false)
	
typedef enum _RPDL_MP_MODE
{
	RPDL_MP_MODE_DISABLED,
	RPDL_MP_MODE_ENABLED,
	RPDL_MP_MODE_EXPECTING_ID
}RPDL_MP_MODE;

typedef struct _RPDL_SCI_MP_SPECIFIC
{
	volatile RPDL_MP_MODE MP_mode;
	volatile uint8_t MP_rx_stationID;
}RPDL_SCI_MP_SPECIFIC;

typedef struct _RPDL_SCI_DATA_GLOBAL
{
	volatile const uint8_t * tx_string_pointer;
	volatile uint8_t * rx_string_pointer;
	volatile uint8_t * rx_string_start;
	volatile uint16_t rx_counter;
	volatile uint16_t tx_counter;
	volatile uint16_t rx_threshold;
	volatile uint16_t tx_threshold;
	volatile uint8_t tx_using_irq;
	volatile uint8_t rx_using_irq;
	volatile uint8_t rx_continuous;
	volatile uint8_t sync_simultaneous;
	volatile uint32_t baud_rate;
	RPDL_SCI_MP_SPECIFIC MP;

	/* Callback functions pointer storage*/
	VoidCallBackFunc TX_End_callback_func;
	VoidCallBackFunc RX_End_callback_func;
	VoidCallBackFunc RX_Error_callback_func;
}RPDL_SCI_DATA_GLOBAL;

/* Globals */
extern RPDL_SCI_DATA_GLOBAL  sci_global[];
/* Library prototypes */
bool R_SCI_SetAll(
	const uint8_t
);
bool R_SCI_CreateAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint8_t
);
bool R_SCI_CreateAsyncAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint8_t
);
bool R_SCI_CreateSyncAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint8_t
);
bool R_SCI_CreateSmartAll(
	const uint8_t,
	const uint32_t,
	const uint32_t,
	const uint8_t
);
bool R_SCI_DestroyAll(
	const uint8_t
);
bool R_SCI_SendAll(
	const uint8_t,
	const uint16_t,
	volatile const uint8_t * const,
	const uint16_t,
	VoidCallBackFunc const
);
bool R_SCI_SendStationID(
	const uint8_t,
	const uint16_t 
);
bool R_SCI_SendData(
	const uint8_t,
	const uint16_t,
	volatile const uint8_t * const,
	const uint16_t,
	VoidCallBackFunc const
);
bool R_SCI_ReceiveAll(
	const uint8_t,
	const uint16_t,
	volatile uint8_t * const,
	const uint16_t,
	VoidCallBackFunc const,
	VoidCallBackFunc const
);
bool R_SCI_ReceiveStationID(
	const uint8_t,
	const uint16_t,
	VoidCallBackFunc const,
	VoidCallBackFunc const
);
bool R_SCI_ReceiveData(
	const uint8_t,
	const uint16_t,
	volatile uint8_t * const,
	const uint16_t,
	VoidCallBackFunc const,
	VoidCallBackFunc const
);
bool R_SCI_ControlAll(
	const uint8_t,
	const uint8_t
);
bool R_SCI_GetStatusAll(
	const uint8_t,
	volatile uint8_t * const,
	volatile uint8_t * const,
	volatile uint16_t * const,
	volatile uint16_t * const
);
bool ReturnFalse(void);

/* Macro definitions */
#define R_SCI_Set(a) \
( R_SCI_SetAll( (a) ) )

#define R_SCI_Create(a, b, c, d)								\
(																\
( SCI_INVALID_CHANNEL(a) || ((c) == 0) || ((d) > IPL_MAX) )? 	\
ReturnFalse(): 													\
R_SCI_CreateAll( (a), (b), (c), (d) )							\
)

#define R_SCI_Destroy(a) (SCI_INVALID_CHANNEL(a) ? ReturnFalse():R_SCI_DestroyAll((a)))

#define R_SCI_Send(a, b, c, d, e)		\
( 										\
SCI_INVALID_CHANNEL(a) ?				\
ReturnFalse():							\
R_SCI_SendAll( (a), (b), (c), (d), (e) )\
)

#define R_SCI_Receive(a, b, c, d, e, f)			\
(												\
SCI_INVALID_CHANNEL(a) ?						\
ReturnFalse():									\
R_SCI_ReceiveAll( (a), (b), (c), (d), (e), (f) )\
)

#define R_SCI_Control(a, b)	\
(							\
SCI_INVALID_CHANNEL(a) ?	\
ReturnFalse():				\
R_SCI_ControlAll( (a), (b) )\
)

#define R_SCI_GetStatus(a, b, c, d, e)			\
(												\
SCI_INVALID_CHANNEL(a) ?						\
ReturnFalse():									\
R_SCI_GetStatusAll( (a), (b), (c), (d), (e) )	\
)

#endif
/* End of file */
