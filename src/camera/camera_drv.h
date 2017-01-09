
#ifndef _CAMERA_DRV_H_
#define _CAMERA_DRV_H_

#include <inttypes.h>
#include "vc0706.h"

#define CAMERA_RESOLUTION_160X120	VC0706_ZOOMING_PROPORTION_QUARTER
#define CAMERA_RESOLUTION_320X240	VC0706_ZOOMING_PROPORTION_HALF
#define CAMERA_RESOLUTION_640X480	VC0706_ZOOMING_PROPORTION_NO_ZOOM

enum
{
	CAMERA_BAUDRATE_9600 = 0,
	CAMERA_BAUDRATE_19200,
	CAMERA_BAUDRATE_38400,
	CAMERA_BAUDRATE_57600,
	CAMERA_BAUDRATE_115200,
	CAMERA_BAUDRATE_NUM
};

uint8_t  CAMERA_Init( void );
uint8_t  CAMERA_Capture( void );
uint32_t CAMERA_ReadImageDataLength( void );
uint8_t  CAMERA_ReadImageData( uint16_t address, uint8_t* buffer, uint16_t length );
uint8_t  CAMERA_StopCapture( void );
uint8_t  CAMERA_SetCompression( uint8_t compression );
uint8_t  CAMERA_GetCompression( void );
uint8_t  CAMERA_SetResolution( uint8_t resolution );
uint8_t  CAMERA_SetBaudrate( uint8_t baudrate );
uint8_t  CAMERA_EEPROM_WriteBaudrate( uint8_t baudrate );
uint8_t  CAMERA_OSD( uint8_t x, uint8_t y, const char* str );

#endif // _CAMERA_DRV_H_
