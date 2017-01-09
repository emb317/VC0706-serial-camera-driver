
#include <stdio.h>
#include "camera_drv.h"
#include "vc0706.h"

#include "r_pdl_sci.h"
#include "r_pdl_cgc.h"
#include "r_pdl_intc.h"
#include "r_pdl_definitions.h"

#define SCI_CH_PC		0
#define SCI_CH_CAMERA	2

void CameraSend(const uint8_t* data, uint32_t len);
uint32_t CameraReceive(uint8_t* data, uint32_t len);

uint8_t image_data[512];

void init(void)
{
	printf( "RPDL version %04X\n", PDL_VERSION );
	
	R_CGC_Set(12E6, 96E6, 48E6, 0, PDL_CGC_BCLK_DISABLE | PDL_CGC_SUB_CLOCK_ENABLE);	/* Initialise the system clocks */

	R_INTC_Write(PDL_INTC_REG_IPL, 0);		/* Set the CPU's Interrupt Priority Level to 0 */

	R_SCI_Create(SCI_CH_PC, PDL_SCI_ASYNC | PDL_SCI_8N1, 115200*2, 7);
}

void init_camera(void)
{
	uint8_t data[16] = {0};

#if 0
	/*	VC0706 のデフォルトのボーレートは38400である。
		下記は64KB受信した場合の実測値で、ボーレートによって取得にかかる時間が異なる。
		マイコンの性能に合わせて高いボーレートにすることを推奨する。
		115200 =  7,053ms
		 57600 = 12,665ms
		 38400 = 19,019ms
		 19200 = 37,888ms
		  9600 = 75,594ms
		ここを有効にしてEEPROMに書き込むと、次回起動時からは115200で通信可能になる。
	*/
	printf("Write baudrate 115200\n");
	R_SCI_Create(SCI_CH_CAMERA, PDL_SCI_ASYNC | PDL_SCI_8N1, 38400, 0);
	CAMERA_EEPROM_WriteBaudrate( CAMERA_BAUDRATE_115200 );
	R_CMT_CreateOneShot( 0, 0, 100E-3, PDL_NO_FUNC, 0 ); // wait 100ms
	CAMERA_Init();
	printf("OK\n");
	while(1);
#endif
	
	R_SCI_Create(SCI_CH_CAMERA, PDL_SCI_ASYNC | PDL_SCI_8N1, 115200, 0);
	
	CAMERA_Init();
	printf("CAMERA_Init\n" );
	R_CMT_CreateOneShot( 0, 0, 500E-3, PDL_NO_FUNC, 0 ); // wait 500ms

	VC0706_GetFirmwareVersion( data );
	printf("VC0706_GetFirmwareVersion '%s'\n", data);
	
	printf("CAMERA_GetCompression %d\n", CAMERA_GetCompression());
	
	// 初期化処理の最後で100ms待つ。ここまでの設定がフレームバッファに反映されるのを待つため。
	R_CMT_CreateOneShot( 0, 0, 100E-3, PDL_NO_FUNC, 0 ); // wait 100ms
}

void main(void)
{
	printf("\n\n-----------------------------\n");
	printf("init()\n");
	init();
	printf("init_camera()\n");
	init_camera();
	printf("Complete Init!\n");
	
	while(1)
	{
		uint32_t len;
		uint32_t address = 0;

		CAMERA_Capture();
		
		len = CAMERA_ReadImageDataLength();
		printf("FBufLen=%d ", len);
		
		while(address < len)
		{
			if(len - address >= sizeof(image_data))
			{
				CAMERA_ReadImageData( address, image_data, sizeof(image_data) );
				R_SCI_Send(SCI_CH_PC, PDL_NO_DATA, image_data, sizeof(image_data), PDL_NO_FUNC);
			}
			else
			{
				CAMERA_ReadImageData( address, image_data, len - address );
				R_SCI_Send(SCI_CH_PC, PDL_NO_DATA, image_data, len - address, PDL_NO_FUNC);
			}
			
			address += sizeof(image_data);
		}
		
		CAMERA_StopCapture();
		printf("Complete\n");
	}
}


void CameraSend(const uint8_t* data, uint32_t len)
{
	R_SCI_Send(SCI_CH_CAMERA, PDL_NO_DATA, data, len, PDL_NO_FUNC);
}
uint32_t CameraReceive(uint8_t* data, uint32_t len)
{
	R_SCI_Receive(SCI_CH_CAMERA, PDL_NO_DATA, data, len, PDL_NO_FUNC, PDL_NO_FUNC);
	return len;
}
