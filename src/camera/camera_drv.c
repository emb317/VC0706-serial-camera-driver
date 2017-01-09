
#include "camera_drv.h"

VC0706_STATUS camera_result;

/**
 * カメラを初期化する。
 * @return 1=OK; 0=Error
 * @note 本関数呼び出し後、500msはカメラへのアクセスを行わないこと
 */
uint8_t CAMERA_Init( void )
{
	camera_result = VC0706_SystemReset();
	return camera_result == VC0706_STATUS_OK;
}

/**
 * キャプチャを開始する。
 * @return 1=OK; 0=Error
 */
uint8_t CAMERA_Capture( void )
{
	camera_result = VC0706_FBufCtrl( VC0706_FBUF_CONTROL_STOP_CURRENT_FRAME );
	return camera_result == VC0706_STATUS_OK;
}

/**
 * キャプチャデータのデータ長を取得する。
 * @return Data length; 0=Error
 */
uint32_t CAMERA_ReadImageDataLength( void )
{
	uint32_t len = 0;
	camera_result = VC0706_GetFBufLen( VC0706_FBUF_TYPE_CURRENT, &len );
	return len;
}

/**
 * キャプチャデータを取得する。
 * 1回に取得するサイズは 512byte を推奨する。
 * 下記は115200で64KB読み出したときの実測値で 32byte だと他のサイズの2倍時間がかかる。
 * また、512byte以上は差が少ない。
 * length = 2048 :  6,363 ms
 * length = 1024 :  6,463 ms
 * length =  512 :  6,660 ms
 * length =  256 :  7,053 ms
 * length =   64 :  9,410 ms
 * length =   32 : 12,553 ms
 * @param address 読み出し開始位置
 * @param buffer 読み出したデータの格納先アドレス
 * @param length 読み出すデータサイズ
 * @return 1=OK; 0=Error
 */
uint8_t CAMERA_ReadImageData( uint16_t address, uint8_t* buffer, uint16_t length )
{
	camera_result = VC0706_ReadFBuf( VC0706_FBUF_TYPE_CURRENT, VC0706_DATA_TRANSFER_BY_MCU, address, length, 0, buffer );
	return camera_result == VC0706_STATUS_OK;
}

/**
 * キャプチャを停止する。
 * @return 1=OK; 0=Error
 */
uint8_t CAMERA_StopCapture( void )
{
	camera_result = VC0706_FBufCtrl( VC0706_FBUF_CONTROL_RESUME_FRAME );
	return camera_result == VC0706_STATUS_OK;
}

/**
 * 画像の圧縮率を指定する。
 * 値が小さいほど圧縮率が下がるが、下げすぎると上限サイズの64KBを超えてしまい
 * 画像が取得できなくなる。
 * リセット後のデフォルト値の 53 以上の値を推奨する。
 * @param compression 0～255
 * @return 1=OK; 0=Error
 */
uint8_t CAMERA_SetCompression( uint8_t compression )
{
	camera_result = VC0706_WriteData( VC0706_DEVICE_TYPE_CHIP_REGISTER, 1, 1, 0x1204, &compression );
	return camera_result == VC0706_STATUS_OK;
}

/**
 * 画像の圧縮率を取得する。
 * @return compression 0～255
 */
uint8_t CAMERA_GetCompression( void )
{
	uint8_t compression = 0;
	camera_result = VC0706_ReadData( VC0706_DEVICE_TYPE_CHIP_REGISTER, 1, 1, 0x1204, &compression );
	return compression;
}

/**
 * 画像のサイズを設定する。
 * @param compressibility
 *  CAMERA_RESOLUTION_640X480
 *  CAMERA_RESOLUTION_320X240
 *  CAMERA_RESOLUTION_160X120
 * @return 1=OK; 0=Error
 */
uint8_t CAMERA_SetResolution( uint8_t resolution )
{
	camera_result = VC0706_DownsizeCtrl( resolution, resolution );
	return camera_result == VC0706_STATUS_OK;
}

/**
 * ボーレートを設定する。
 * @param baudrate
 *  CAMERA_BAUDRATE_9600
 *  CAMERA_BAUDRATE_19200
 *  CAMERA_BAUDRATE_38400 (default)
 *  CAMERA_BAUDRATE_57600
 *  CAMERA_BAUDRATE_115200
 * @return 1=OK; 0=Error
 */
uint8_t CAMERA_SetBaudrate( uint8_t baudrate )
{
	camera_result = VC0706_SetPort( baudrate );
	return camera_result == VC0706_STATUS_OK;
}

/**
 * EEPROMにボーレートを書き込む。
 * @param baudrate
 *  CAMERA_BAUDRATE_9600
 *  CAMERA_BAUDRATE_19200
 *  CAMERA_BAUDRATE_38400 (default)
 *  CAMERA_BAUDRATE_57600
 *  CAMERA_BAUDRATE_115200
 * @return 1=OK; 0=Error
 */
uint8_t CAMERA_EEPROM_WriteBaudrate( uint8_t baudrate )
{
	const uint8_t DATA[CAMERA_BAUDRATE_NUM][2] =
	{
		{ 0xAE, 0xC8 }, // 9600
		{ 0x56, 0xE4 }, // 19200
		{ 0x2A, 0xF2 }, // 38400
		{ 0x1C, 0x4C }, // 57600
		{ 0x0D, 0xA6 }  // 115200
	};
	camera_result = VC0706_WriteData( VC0706_DEVICE_TYPE_I2C_EEPROM, 2, 1, 0x0008, DATA[baudrate] );
	return camera_result == VC0706_STATUS_OK;
}

/**
 * 画面に文字を表示する。
 * @param x X座標 0～1
 * @param y Y座標 0～15
 * @param str 表示する文字列 使用可能文字 0～9 A～Z a～z -_:./*()[]@!+|\# スペース
 * @return 1=OK; 0=Error
 */
uint8_t CAMERA_OSD( uint8_t x, uint8_t y, const char* str )
{
	uint8_t i, j;
	uint8_t data[VC0706_OSD_CHAR_MAX_NUM];
	const char* CODE = "-_:./*()[]@!+|\\#";
	
	for( i=0; str[i] && i < sizeof(data); i++ )
	{
		char c = str[i];
		if((c >= '0') && (c <= '9'))
		{
			data[i] = str[i] - '0';
		}
		else if((c >= 'A') && (c <= 'Z'))
		{
			data[i] = str[i] - 'A';
			data[i] = str[i] + 10;
		}
		else if((c >= 'a') && (c <= 'z'))
		{
			data[i] = str[i] - 'a';
			data[i] = str[i] + 36;
		}
		else if(c==' ')
		{
			data[i] = 79;
		}
		else
		{
			data[i] = 78;
			for (j = 0; CODE[j]; j++)
			{
				if(c == CODE[j])
				{
					data[i] = 62 + j;
					break;
				}
			}
		}
	}
	
	camera_result = VC0706_OSD_AddChar(x, y, i, data);
	return camera_result == VC0706_STATUS_OK;
}

