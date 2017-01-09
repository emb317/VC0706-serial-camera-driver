
#include "vc0706.h"

uint8_t VC0706_Config_SerialNumber = 0x00;

void CameraSend( const uint8_t* data, uint32_t len );
uint32_t CameraReceive( uint8_t* data, uint32_t len );

void VC0706_Config_Send( const uint8_t* data, uint32_t length )
{
	CameraSend(data, length);
}

uint32_t VC0706_Config_Receive( uint8_t* buffer, uint32_t length )
{
	CameraReceive(buffer, length);
	return 0;
}
