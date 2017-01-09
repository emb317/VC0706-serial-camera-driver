
#ifndef _VC0706_H_
#define _VC0706_H_

#include <inttypes.h>

#define VC0706_ADDRESS_SELECT_IF			0x0007	// Select Serial Communication Interface
#define VC0706_ADDRESS_UART_BAUD_RATE		0x0008	// UART baud rate setting
#define VC0706_ADDRESS_HS_UART_BAUD_RATE	0x000A	// HS_UART baud rate setting

typedef uint8_t VC0706_STATUS;
#define VC0706_STATUS_OK			0	// Executing command right.
#define VC0706_STATUS_ERR_NO_RCV	1	// System don't receive the command.
#define VC0706_STATUS_ERR_LENGTH	2	// The data-length is error.
#define VC0706_STATUS_ERR_FORMAT	3	// Data format error.
#define VC0706_STATUS_ERR_BUSY		4	// The command can not execute now .
#define VC0706_STATUS_ERR_WRONG		5	// Command received,but executed wrong.

enum
{
	VC0706_BAUD_RATE_9600 = 0,
	VC0706_BAUD_RATE_19200,
	VC0706_BAUD_RATE_38400,
	VC0706_BAUD_RATE_57600,
	VC0706_BAUD_RATE_115200,

	VC0706_BAUD_RATE_NUM
};

enum
{
	VC0706_DEVICE_TYPE_CHIP_REGISTER = 1,
	VC0706_DEVICE_TYPE_SENSOR_REGISTER,
	VC0706_DEVICE_TYPE_CCIR656_REGISTER,
	VC0706_DEVICE_TYPE_I2C_EEPROM,
	VC0706_DEVICE_TYPE_SPI_EEPROM,
	VC0706_DEVICE_TYPE_SPI_FLASH
};

enum
{
	VC0706_FBUF_TYPE_CURRENT = 0,
	VC0706_FBUF_TYPE_NEXT,

	VC0706_FBUF_TYPE_NUM
};

#define VC0706_DATA_TRANSFER_BY_MCU	0x00
#define VC0706_DATA_TRANSFER_BY_DMA	0x01
#define VC0706_FIRST_DATA_NO		0x00
#define VC0706_FIRST_DATA_YES		0x10

enum
{
	VC0706_FBUF_CONTROL_STOP_CURRENT_FRAME = 0,
	VC0706_FBUF_CONTROL_STOP_NEXT_FRAME,
	VC0706_FBUF_CONTROL_RESUME_FRAME,
	VC0706_FBUF_CONTROL_STEP_FRAME,

	VC0706_FBUF_CONTROL_NUM
};

enum
{
	VC0706_MOTION_CONTROL_STOP = 0,
	VC0706_MOTION_CONTROL_START,

	VC0706_MOTION_CONTROL_NUM
};

enum
{
	VC0706_CONTROL_MODE_GPIO = 0,
	VC0706_CONTROL_MODE_UART,

	VC0706_CONTROL_MODE_NUM
};

enum
{
	VC0706_MIRROR_MODE_NOT_SHOW_MIRROR = 0,
	VC0706_MIRROR_MODE_SHOW_MIRROR,

	VC0706_MIRROR_MODE_NUM
};

enum
{
	VC0706_SHOW_MODE_AUTOMATICALLY = 0,
	VC0706_SHOW_MODE_MANUALLY_SELECT_COLOUR,
	VC0706_SHOW_MODE_MANUALLY_SELECT_BLACK_WHITE,

	VC0706_SHOW_MODE_NUM
};

enum
{
	VC0706_POWER_SAVE_COMMAND_TYPE_CONTROL_MODE = 0,
	VC0706_POWER_SAVE_COMMAND_TYPE_ATTRIBUTE_CONFIGURATION,

	VC0706_POWER_SAVE_COMMAND_TYPE_NUM
};

enum
{
	VC0706_POWER_SAVE_STOP = 0,
	VC0706_POWER_SAVE_START,

	VC0706_POWER_SAVE_NUM
};

enum
{
	VC0706_AE_ATTRIBUTE_SET_FREQUENCY = 0,
	VC0706_AE_ATTRIBUTE_SET_STEP_MODE,
	VC0706_AE_ATTRIBUTE_BACKLIGHT_COMPENSATION,

	VC0706_AE_ATTRIBUTE_NUM
};

enum
{
	VC0706_FREQUENCY_50HZ = 0,
	VC0706_FREQUENCY_60HZ,

	VC0706_FREQUENCY_NUM
};

enum
{
	VC0706_STEP_MODE_AUTOMATICALLY = 0,
	VC0706_STEP_MODE_FORCIBLY_INDOOR,

	VC0706_STEP_MODE_NUM
};

enum
{
	VC0706_BACKLIGHT_COMPENSATION_STOP = 0,
	VC0706_BACKLIGHT_COMPENSATION_START,

	VC0706_BACKLIGHT_COMPENSATION_NUM
};

enum
{
	VC0706_MOTION_ATTRIBUTE_MOTION_ENABLING = 0,
	VC0706_MOTION_ATTRIBUTE_ALARM_ATTRIBUTE,
	VC0706_MOTION_ATTRIBUTE_ALARM_ENABLING_CONTROL,
	VC0706_MOTION_ATTRIBUTE_ALARM_CONTROL,

	VC0706_MOTION_ATTRIBUTE_NUM
};

enum
{
	VC0706_MOTION_MONITORING_FORBID = 0,
	VC0706_MOTION_MONITORING_START,

	VC0706_MOTION_MONITORING_NUM
};

#define VC0706_ALARM_TYPE_CERTAIN_TIME		0x00
#define VC0706_ALARM_TYPE_ALL_TIMES			0x01
#define VC0706_ALARM_ELECTRICAL_LEVEL_LOW	0x00
#define VC0706_ALARM_ELECTRICAL_LEVEL_HIGH	0x02

enum
{
	VC0706_ALARM_OUTPUT_ENABLING_CONTROL_FORBID = 0,
	VC0706_ALARM_OUTPUT_ENABLING_CONTROL_ENABLE,

	VC0706_ALARM_OUTPUT_ENABLING_CONTROL_NUM
};

enum
{
	VC0706_ALARM_OUTPUT_CONTROL_STOP = 0,
	VC0706_ALARM_OUTPUT_CONTROL_START,

	VC0706_ALARM_OUTPUT_CONTROL_NUM
};

enum
{
	VC0706_TV_OUTPUT_STOP = 0,
	VC0706_TV_OUTPUT_START,

	VC0706_TV_OUTPUT_NUM
};

#define VC0706_OSD_CHAR_MAX_NUM	14

enum
{
	VC0706_ZOOMING_PROPORTION_NO_ZOOM = 0,	// 1/1
	VC0706_ZOOMING_PROPORTION_HALF,			// 1/2
	VC0706_ZOOMING_PROPORTION_QUARTER,		// 1/4
//	VC0706_ZOOMING_PROPORTION_RESERVATION,

	VC0706_ZOOMING_PROPORTION_NUM
};

enum
{
	VC0706_TRANSFER_BITMAP_STOP = 0,
	VC0706_TRANSFER_BITMAP_START,

	VC0706_TRANSFER_BITMAP_NUM
};

VC0706_STATUS VC0706_GetFirmwareVersion( uint8_t* out_buffer );
VC0706_STATUS VC0706_SetSerialNumber( uint8_t new_serial_number );
VC0706_STATUS VC0706_SetPort( uint8_t baud_rate );
VC0706_STATUS VC0706_SystemReset( void );
VC0706_STATUS VC0706_ReadData( uint8_t device_type, uint8_t data_num, uint8_t data_width, uint32_t address, uint8_t* out_buffer );
VC0706_STATUS VC0706_WriteData( uint8_t device_type, uint8_t data_num, uint8_t data_width, uint32_t address, const uint8_t* write_data );
VC0706_STATUS VC0706_ReadFBuf( uint8_t fbuf_type, uint8_t control_mode, uint32_t starting_address, uint32_t data_length, uint16_t delay, uint8_t* out_buffer );
VC0706_STATUS VC0706_WriteFBuf( uint8_t control_mode, uint32_t starting_address, uint32_t data_length, uint8_t delay, const uint8_t* write_data );
VC0706_STATUS VC0706_GetFBufLen( uint8_t fbuf_type, uint32_t* out_length );
VC0706_STATUS VC0706_SetFBufLen( uint32_t length );
VC0706_STATUS VC0706_FBufCtrl( uint8_t control_flag );
VC0706_STATUS VC0706_CommMotionCtrl( uint8_t control_flag );
VC0706_STATUS VC0706_CommMotionStatus( uint8_t* out_status );
VC0706_STATUS VC0706_CommMotionDetected( void );
VC0706_STATUS VC0706_MirrorCtrl( uint8_t control_mode, uint8_t mirror_mode );
VC0706_STATUS VC0706_MirrorStatus( uint8_t* out_control_mode, uint8_t* out_mirror_mode );
VC0706_STATUS VC0706_ColorCtrl( uint8_t control_mode, uint8_t show_mode );
VC0706_STATUS VC0706_ColorStatus( uint8_t* out_control_mode, uint8_t* out_show_mode, uint8_t* out_current_color );
VC0706_STATUS VC0706_PowerSaveCtrl( uint8_t command_type, uint8_t control_item1, uint8_t control_item2, uint8_t control_item3 );
VC0706_STATUS VC0706_PowerSaveStatus( uint8_t command_type, uint8_t* out_control_item1, uint8_t* out_control_item2, uint8_t* out_control_item3 );
VC0706_STATUS VC0706_AE_Ctrl( uint8_t ae_attribute, uint8_t control_mode, uint8_t control_item );
VC0706_STATUS VC0706_AE_Status( uint8_t ae_attribute, uint8_t* out_control_mode, uint8_t* out_control_item );
VC0706_STATUS VC0706_MotionCtrl( uint8_t motion_attribute, uint8_t control_item1, uint8_t control_item2, uint8_t control_item3 );
VC0706_STATUS VC0706_MotionStatus( uint8_t motion_attribute, uint8_t* out_control_item1, uint8_t* out_control_item2, uint8_t* out_control_item3 );
VC0706_STATUS VC0706_TV_OutCtrl( uint8_t tv_output );
VC0706_STATUS VC0706_OSD_AddChar( uint8_t x, uint8_t y, uint8_t char_num, const uint8_t* characters );
VC0706_STATUS VC0706_DownsizeCtrl( uint8_t width_zoom, uint8_t height_zoom );
VC0706_STATUS VC0706_DownsizeStatus( uint8_t* out_width_zoom, uint8_t* out_height_zoom );
VC0706_STATUS VC0706_GetFlashSize( uint32_t* out_size );
VC0706_STATUS VC0706_EraseFlashSector( uint32_t address );
VC0706_STATUS VC0706_EraseFlashAll( void );
VC0706_STATUS VC0706_ReadLogo( uint8_t logo_lengths, uint32_t address );
VC0706_STATUS VC0706_SetBitmap( uint8_t control_type, uint16_t bitmap_lengths, uint32_t address );

#endif // _VC0706_H_
