
#include "vc0706.h"

#define VC0706_CMD_GET_VERSION			0x11 // Get Firmware version information
#define VC0706_CMD_SET_SERIAL_NUMBER	0x21 // Set serial number
#define VC0706_CMD_SET_PORT				0x24 // Set port
#define VC0706_CMD_SYSTEM_RESET			0x26 // System reset
#define VC0706_CMD_READ_DATA			0x30 // Read data regisvter
#define VC0706_CMD_WRITE_DATA			0x31 // Write data register
#define VC0706_CMD_READ_FBUF			0x32 // Read buffer register
#define VC0706_CMD_WRITE_FBUF			0x33 // Write buffer register
#define VC0706_CMD_GET_FBUF_LEN			0x34 // Get image lengths in frame buffer
#define VC0706_CMD_SET_FBUF_LEN			0x35 // Set image lengths in frame buffer 
#define VC0706_CMD_FBUF_CTRL			0x36 // Control frame buffer register
#define VC0706_CMD_COMM_MOTION_CTRL		0x37 // Motion detect on or off in comunication interface
#define VC0706_CMD_COMM_MOTION_STATUS	0x38 // Get motion monitoring status in comunication interface
#define VC0706_CMD_COMM_MOTION_DETECTED	0x39 // Motion has been detected by comunication interface
#define VC0706_CMD_MIRROR_CTRL			0x3A // Mirror control 
#define VC0706_CMD_MIRROR_STATUS		0x3B // Mirror status
#define VC0706_CMD_COLOR_CTRL			0x3C // Control color
#define VC0706_CMD_COLOR_STATUS			0x3D // Color status
#define VC0706_CMD_POWER_SAVE_CTRL		0x3E // Power mode control
#define VC0706_CMD_POWER_SAVE_STATUS	0x3F // Power save mode or not
#define VC0706_CMD_AE_CTRL				0x40 // Control AE
#define VC0706_CMD_AE_STATUS			0x41 // AE status
#define VC0706_CMD_MOTION_CTRL			0x42 // Motion control
#define VC0706_CMD_MOTION_STATUS		0x43 // Get motion status
#define VC0706_CMD_TV_OUT_CTRL			0x44 // TV output on or off control
#define VC0706_CMD_OSD_ADD_CHAR			0x45 // Add characters to OSD channels
#define VC0706_CMD_DOWNSIZE_CTRL		0x54 // Downsize Control
#define VC0706_CMD_DOWNSIZE_STATUS		0x55 // Downsize status
#define VC0706_CMD_GET_FLASH_SIZE		0x60 // Get SPI flash size
#define VC0706_CMD_ERASE_FLASH_SECTOR	0x61 // Erase one block of the flash
#define VC0706_CMD_ERASE_FLASH_ALL		0x62 // Erase the whole flash
#define VC0706_CMD_READ_LOGO			0x70 // Read and show logo
#define VC0706_CMD_SET_BITMAP			0x71 // Bitmap operation 
// unknown command #define VC0706_CMD_BATCH_WRITE			0x80 // Write mass data at a time

#define VC0706_RECEIVE_SIGN		0x56	// Protocol sign : MCU -> VC0706
#define VC0706_RETURN_SIGN		0x76	// Protocol sign : MCU <- VC0706

#ifndef NULL
  #define NULL ((void*)0)
#endif

// Protocol sign(1byte) + Serial number(1byte) + Command(1byte) + Data-lengths(1byte) + Data(0~16bytes)
typedef struct _VC0706_SND_CMD
{
	uint8_t sign;
	uint8_t serial;
	uint8_t command;
	uint8_t data_length;
	uint8_t data[16];
} VC0706_SND_CMD;

// Protocol sign(1byte) + Serial number(1byte) + Command(1byte) + Status(1byte) + Data-lengths(1byte) + Data(0~16bytes)
typedef struct _VC0706_RET_CMD
{
	uint8_t sign;
	uint8_t serial;
	uint8_t command;
	uint8_t status;
	uint8_t data_length;
	uint8_t data[16];
} VC0706_RET_CMD;

extern uint8_t VC0706_Config_SerialNumber;

void     VC0706_Config_Send( const uint8_t* data, uint32_t length );
uint32_t VC0706_Config_Receive( uint8_t* buffer, uint32_t length );

//==========================================================================================

VC0706_SND_CMD snd_cmd;
VC0706_RET_CMD ret_cmd;

//==========================================================================================

static void VC0706_SendCommnad( uint8_t command, uint8_t data_length, const uint8_t* data )
{
//	VC0706_SND_CMD snd_cmd;
	uint8_t i;

	snd_cmd.sign		= VC0706_RECEIVE_SIGN;
	snd_cmd.serial		= VC0706_Config_SerialNumber;
	snd_cmd.command 	= command;
	snd_cmd.data_length	= data_length;
	for( i=0; i < data_length; i++ )
	{
		snd_cmd.data[i] = data[i];
	}

	VC0706_Config_Send( (uint8_t*)&snd_cmd, 4 + data_length );
}

static VC0706_STATUS VC0706_ReceiveCommnad( uint8_t buffer_length, uint8_t* out_buffer )
{
//	VC0706_RET_CMD ret_cmd;
	uint8_t i;

	VC0706_Config_Receive( (uint8_t*)&ret_cmd, 5 + buffer_length );

	for( i=0; i < buffer_length; i++ )
	{
		out_buffer[i] = ret_cmd.data[i];
	}

	return ret_cmd.status;
}

static void VC0706_WriteArray16( uint8_t* buf, uint16_t data )
{
	buf[0] = (uint8_t)((data >>  8) & 0xFF);
	buf[1] = (uint8_t)((data      ) & 0xFF);
}
static void VC0706_WriteArray32( uint8_t* buf, uint32_t data )
{
	buf[0] = (uint8_t)((data >> 24) & 0xFF);
	buf[1] = (uint8_t)((data >> 16) & 0xFF);
	buf[2] = (uint8_t)((data >>  8) & 0xFF);
	buf[3] = (uint8_t)((data      ) & 0xFF);
}

//==========================================================================================

/**
 * モジュールのファームウェアバージョンを取得する。
 * 11桁の文字で取得できる。
 * 取得例 : VC0703 1.00
 * @param out_buffer バージョン情報の格納先 11byte以上必要
 */
VC0706_STATUS VC0706_GetFirmwareVersion( uint8_t* out_buffer )
{
	VC0706_SendCommnad( VC0706_CMD_GET_VERSION, 0, NULL );
	return VC0706_ReceiveCommnad( 11, out_buffer );
}

/**
 * モジュールのシリアル番号を設定する。
 * このコマンドで設定した番号は電源を切るか、SystemResetコマンドで初期値に戻る。
 * 設定したシリアル番号は以降の各コマンド送受信に使用される。
 * VC0706はシリアル番号が異なるとコマンドを受信しないため、
 * 1のUARTに複数のカメラモジュールを接続する場合に使用するコマンドだと思われる。
 * 基本的には使用しないコマンドである。
 * @param new_serial_number シリアル番号
 */
VC0706_STATUS VC0706_SetSerialNumber( uint8_t new_serial_number )
{
	VC0706_STATUS status;
	VC0706_SendCommnad( VC0706_CMD_SET_SERIAL_NUMBER, 1, &new_serial_number );
	status = VC0706_ReceiveCommnad( 0, NULL );

	if( status == VC0706_STATUS_OK )
	{
		VC0706_Config_SerialNumber = new_serial_number;
	}

	return status;
}

/**
 * モジュールとの通信ボーレートを設定する。
 * このコマンドで設定したボーレートは電源を切るか、SystemResetコマンドで初期値に戻る。
 * 設定したボーレートはコマンドの応答後に即座に反映される。
 * @param baud_rate ボーレート
 *         VC0706_BAUD_RATE_9600
 *         VC0706_BAUD_RATE_19200
 *         VC0706_BAUD_RATE_38400
 *         VC0706_BAUD_RATE_57600
 *         VC0706_BAUD_RATE_115200
 */
VC0706_STATUS VC0706_SetPort( uint8_t baud_rate )
{
	const uint8_t BAUD_RATE[VC0706_BAUD_RATE_NUM][3]={
		{0x01, 0xAE,0xC8}, // 9600
		{0x01, 0x56,0xE4}, // 19200
		{0x01, 0x2A,0xF2}, // 38400
		{0x01, 0x1C,0x1C}, // 57600
		{0x01, 0x0D,0xA6}  // 115200
	};

	if( baud_rate >= VC0706_BAUD_RATE_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}

	VC0706_SendCommnad( VC0706_CMD_SET_PORT, 3, BAUD_RATE[baud_rate] );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/**
 * モジュールをリセットする。
 * コマンド実行後必要な待ち時間 : 500ms
 * プロトコル仕様書には記載されていないが、初期化の完了までに480ms程度かかる。
 * また、初期化完了までの間に以下の文字列がモジュールから送信される。
 * "VC0703 1.00\r\n"
 * "Ctrl infor exist\r\n"
 * "OV7720\r\n"
 * "525\r\n"
 * "Init end\r\n"
 */
VC0706_STATUS VC0706_SystemReset( void )
{
	VC0706_STATUS status;
	VC0706_SendCommnad( VC0706_CMD_SYSTEM_RESET, 0, NULL );
	status = VC0706_ReceiveCommnad( 0, NULL );

	// リセット後はシリアルナンバーも初期化される
	if( status == VC0706_STATUS_OK )
	{
		VC0706_Config_SerialNumber = 0;
	}

	return status;
}

/**
 * 指定したアドレスからデータを読み出す。
 * @param device_type 読み出し先デバイス
 *          VC0706_DEVICE_TYPE_CHIP_REGISTER
 *          VC0706_DEVICE_TYPE_SENSOR_REGISTER
 *          VC0706_DEVICE_TYPE_CCIR656_REGISTER
 *          VC0706_DEVICE_TYPE_I2C_EEPROM
 *          VC0706_DEVICE_TYPE_SPI_EEPROM
 *          VC0706_DEVICE_TYPE_SPI_FLASH
 * @param data_num 読み出すデータ数
 * @param data_width 1データのサイズ (SensorまたはCCIR656=1～3、それ以外1固定)
 * @param address 読み出し開始アドレス
 * @param out_buffer 読み出しデータの格納先(サイズは data_num * data_width 分必要)
 */
VC0706_STATUS VC0706_ReadData( uint8_t device_type, uint8_t data_num, uint8_t data_width, uint32_t address, uint8_t* out_buffer )
{
// Chip register:   0x56+serial number+0x30+0x04+0x01+the data num ready to read +register address(2 bytes).
// Sensor register: 0x56+serial number+0x30+0x05+0x02+the data num ready to read +register data width(1 byte)+register address(2 bytes).
// CCIR656 register:0x56+serial number+0x30+0x05+0x03+the number of ready reading+register data width(1 byte)+register address(2 bytes).
// I2C EEPROM:      0x56+serial number+0x30+0x04+0x04+the data num ready to read +register address(2 bytes).
// SPI EEPROM:      0x56+serial number+0x30+0x04+0x05+the number of ready reading+register address(2 bytes).
// SPI Flash:       0x56+serial number+0x30+0x06+0x06+the data num ready to read +register address(4 bytes).
	uint8_t data[6] = { device_type, data_num, 0 };
	uint8_t send_length = 0;

	if( data_num * data_width > 16 )
	{
		return VC0706_STATUS_ERR_LENGTH;
	}

	switch( device_type )
	{
	case VC0706_DEVICE_TYPE_SENSOR_REGISTER:
	case VC0706_DEVICE_TYPE_CCIR656_REGISTER:
		data[2] = data_width;
		VC0706_WriteArray16( &data[3], (uint16_t)address );
		send_length = 5;
		break;
	case VC0706_DEVICE_TYPE_CHIP_REGISTER:
	case VC0706_DEVICE_TYPE_I2C_EEPROM:
	case VC0706_DEVICE_TYPE_SPI_EEPROM:
		VC0706_WriteArray16( &data[2], (uint16_t)address );
		send_length = 4;
		break;
	case VC0706_DEVICE_TYPE_SPI_FLASH:
		VC0706_WriteArray32( &data[2], address );
		send_length = 6;
		break;
	default:
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_READ_DATA, send_length, data );
	return VC0706_ReceiveCommnad( data_num * data_width, out_buffer );
}

/**
 * 指定したアドレスへデータを書き込む。
 * @param device_type 読み出し先デバイス
 *          VC0706_DEVICE_TYPE_CHIP_REGISTER
 *          VC0706_DEVICE_TYPE_SENSOR_REGISTER
 *          VC0706_DEVICE_TYPE_CCIR656_REGISTER
 *          VC0706_DEVICE_TYPE_I2C_EEPROM
 *          VC0706_DEVICE_TYPE_SPI_EEPROM
 *          VC0706_DEVICE_TYPE_SPI_FLASH
 * @param data_num 書き込むデータ数
 * @param data_width 1データのサイズ (SensorまたはCCIR656=1～3、それ以外1固定)
 * @param address 書込み開始アドレス
 * @param write_data 書き込むデータ(サイズは data_num * data_width 分必要)
 */
VC0706_STATUS VC0706_WriteData( uint8_t device_type, uint8_t data_num, uint8_t data_width, uint32_t address, const uint8_t* write_data )
{
// Chip register:   0x56+serial number+0x31+Data-length+0x01+the data num ready to write+register address(2 bytes)+data.
// Sensor register: 0x56+serial number+0x31+Data-length+0x02+the data num ready to write+register data width(1 byte)+register address(2 bytes)+data.
// CCIR656 register:0x56+serial number+0x31+Data-length+0x03+the data num ready to write+register data width(1 byte)+register address(2 bytes)+data.
// I2C EEPROM:      0x56+serial number+0x31+Data-length+0x04+the data num ready to write+register address(2 bytes)+data.
// SPI EEPROM:      0x56+serial number+0x31+Data-length+0x05+the data num ready to write+register address(2 bytes)+data.
// SPI Flash:       0x56+serial number+0x31+Data-length+0x06+the data num ready to write+register address(4 bytes)+data.
	uint8_t data[16] = { device_type, data_num, 0 };
	uint8_t send_length = 0;
	uint8_t write_data_length = data_num * data_width;
	uint8_t i;
	uint8_t data_start;

	switch( device_type )
	{
	case VC0706_DEVICE_TYPE_SENSOR_REGISTER:
	case VC0706_DEVICE_TYPE_CCIR656_REGISTER:
		data[2] = data_width;
		VC0706_WriteArray16( &data[3], (uint16_t)address );
		send_length = 5 + write_data_length;
		data_start = 5;
		break;
	case VC0706_DEVICE_TYPE_CHIP_REGISTER:
	case VC0706_DEVICE_TYPE_I2C_EEPROM:
	case VC0706_DEVICE_TYPE_SPI_EEPROM:
		VC0706_WriteArray16( &data[2], (uint16_t)address );
		send_length = 4 + write_data_length;
		data_start = 4;
		break;
	case VC0706_DEVICE_TYPE_SPI_FLASH:
		VC0706_WriteArray32( &data[2], address );
		send_length = 6 + write_data_length;
		data_start = 6;
		break;
	default:
		return VC0706_STATUS_ERR_FORMAT;
	}

	if( send_length > 16 )
	{
		return VC0706_STATUS_ERR_LENGTH;
	}

	for( i = 0; i < write_data_length; i++ )
	{
		data[data_start + i] = write_data[i];
	}

	VC0706_SendCommnad( VC0706_CMD_WRITE_DATA, send_length, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/**
 * フレームバッファから画像データを読み出す。
 * このコマンドは他のコマンドと異なり、以下のように送信される。
 * コマンド応答(5byte) + delay + 画像データ(data_length byte) + delay + コマンド応答(5byte)
 * delayは読み出しに失敗しない程度に可能な限り小さな値を設定したほうが、読み出し時間が短くなる。
 * 早いマイコンであれば0や1でも構わない。
 * delay の値の単位は コマンド仕様によると10usとなっているが、実測では約12us～13usである。
 * 0=262us, 10=413us, 20=532us, 30=660us, 100=1536us, 200=2772us, 400=5265us
 * 上記の実測値の通り、0を指定しても250us以上遅延する。
 * @param fbuf_type		読み出すフレームバッファを指定する
 *          VC0706_FBUF_TYPE_CURRENT 現在のフレーム
 *          VC0706_FBUF_TYPE_NEXT    次のフレーム
 * @param control_mode	転送モードを指定する
 *          VC0706_DATA_TRANSFER_BY_MCU
 *          VC0706_DATA_TRANSFER_BY_DMA (動作しなかった)
 * @param starting_address	読み出し開始アドレス
 * @param data_length		読み出すデータ数
 * @param delay				コマンド応答後、VC0706がデータを送信し始めるまでの時間
 * @param out_buffer		読み出したデータの格納先アドレス
 * <使用例>
 * uint32_t length = 0, address = 0;
 * uint8_t buffer[32];
 * VC0706_FBufCtrl( VC0706_FBUF_CONTROL_STOP_CURRENT_FRAME );
 * VC0706_GetFBufLen( VC0706_FBUF_TYPE_CURRENT, &length );
 * while( address < length )
 * {
 *     if( len - address >= 32 )
 *         VC0706_ReadFBuf( VC0706_FBUF_TYPE_CURRENT, VC0706_DATA_TRANSFER_BY_MCU, address, 32, 0, buffer )
 *     else
 *         VC0706_ReadFBuf( VC0706_FBUF_TYPE_CURRENT, VC0706_DATA_TRANSFER_BY_MCU, address, length-address, 0, buffer )
 *     address += 32;
 * }
 * VC0706_FBufCtrl( VC0706_FBUF_CONTROL_RESUME_FRAME );
 */
VC0706_STATUS VC0706_ReadFBuf( uint8_t fbuf_type, uint8_t control_mode, uint32_t starting_address, uint32_t data_length, uint16_t delay, uint8_t* out_buffer )
{
	uint8_t data[12] = {0};

	if( fbuf_type >= VC0706_FBUF_TYPE_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}

	data[0] = fbuf_type;
	data[1] = 0x0A | control_mode;
	VC0706_WriteArray32( &data[ 2], starting_address );
	VC0706_WriteArray32( &data[ 6], data_length );
	VC0706_WriteArray16( &data[10], delay );
	
	VC0706_SendCommnad( VC0706_CMD_READ_FBUF, 12, data );
	
	VC0706_Config_Receive( (uint8_t*)&ret_cmd, 5 );

	if( ret_cmd.status == VC0706_STATUS_OK )
	{
		VC0706_Config_Receive( out_buffer, data_length );

		VC0706_Config_Receive( (uint8_t*)&ret_cmd, 5 );
	}

	return ret_cmd.status;
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_WriteFBuf( uint8_t control_mode, uint32_t starting_address, uint32_t data_length, uint8_t delay, const uint8_t* write_data )
{
	uint8_t data[11] = {0};

	data[0] = 0x0A | control_mode;
	VC0706_WriteArray32( &data[1], starting_address );
	VC0706_WriteArray32( &data[5], data_length );
	VC0706_WriteArray16( &data[9], delay );
	
	VC0706_SendCommnad( VC0706_CMD_WRITE_FBUF, 11, data );
	
	VC0706_Config_Receive( (uint8_t*)&ret_cmd, 5 );

	if( ret_cmd.status == VC0706_STATUS_OK )
	{
		VC0706_Config_Send( write_data, data_length );

		VC0706_Config_Receive( (uint8_t*)&ret_cmd, 5 );
	}

	return ret_cmd.status;
}

/**
 * フレームバッファの画像データサイズを取得する。
 * フレームの更新を停止してから取得すること。
 * @param fbuf_type サイズを取得するフレーム
 *         VC0706_FBUF_TYPE_CURRENT
 *         VC0706_FBUF_TYPE_NEXT
 * @param out_length フレームバッファのデータ長
 */
VC0706_STATUS VC0706_GetFBufLen( uint8_t fbuf_type, uint32_t* out_length )
{
	uint8_t tmp[4];
	VC0706_STATUS status;

	if( fbuf_type >= VC0706_FBUF_TYPE_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}

	VC0706_SendCommnad( VC0706_CMD_GET_FBUF_LEN, 1, &fbuf_type );
	status = VC0706_ReceiveCommnad( 4, tmp );
	if( status == VC0706_STATUS_OK )
	{
		*out_length = (tmp[0] << 24) | (tmp[1] << 16) | (tmp[2] << 8) | tmp[3];
	}
	else
	{
		*out_length = 0;
	}
	return status;
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_SetFBufLen( uint32_t length )
{
	uint8_t data[4];

	if( length > 65535 )
	{
		return VC0706_STATUS_ERR_LENGTH;
	}

	VC0706_WriteArray32( data, length );
	VC0706_SendCommnad( VC0706_CMD_SET_FBUF_LEN, 4, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/**
 * フレームバッファの動作を設定する。
 * 画像を取得する際はこのコマンドでフレームバッファを停止してから取得する。
 * @param control_flag
 *         VC0706_FBUF_CONTROL_STOP_CURRENT_FRAME
 *         VC0706_FBUF_CONTROL_STOP_NEXT_FRAME
 *         VC0706_FBUF_CONTROL_RESUME_FRAME
 *         VC0706_FBUF_CONTROL_STEP_FRAME
 */
VC0706_STATUS VC0706_FBufCtrl( uint8_t control_flag )
{
	if( control_flag >= VC0706_FBUF_CONTROL_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_FBUF_CTRL, 1, &control_flag );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_CommMotionCtrl( uint8_t control_flag )
{
	if( control_flag >= VC0706_MOTION_CONTROL_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_COMM_MOTION_CTRL, 1, &control_flag );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_CommMotionStatus( uint8_t* out_status )
{
	VC0706_SendCommnad( VC0706_CMD_COMM_MOTION_STATUS, 0, NULL );
	return VC0706_ReceiveCommnad( 1, out_status );
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_CommMotionDetected( void )
{
	VC0706_SendCommnad( VC0706_CMD_COMM_MOTION_DETECTED, 0, NULL );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/**
 * 画像を左右反転させる設定。
 * コマンド実行後必要な待ち時間 : 70ms
 * @param control_mode
 *         VC0706_CONTROL_MODE_GPIO
 *         VC0706_CONTROL_MODE_UART
 * @param mirror_mode
 *         VC0706_MIRROR_MODE_NOT_SHOW_MIRROR
 *         VC0706_MIRROR_MODE_SHOW_MIRROR
 * note : コマンド実行後、70m以上待たずに画像を取得した場合、設定前の状態で取得してしまう。
 * <使用例>
 * 画像を左右反転させる例。
 * VC0706_MirrorCtrl( VC0706_CONTROL_MODE_UART, VC0706_MIRROR_MODE_SHOW_MIRROR );
 */
VC0706_STATUS VC0706_MirrorCtrl( uint8_t control_mode, uint8_t mirror_mode )
{
	uint8_t data[2] = { control_mode, mirror_mode };
	if( control_mode >= VC0706_CONTROL_MODE_NUM || mirror_mode >= VC0706_MIRROR_MODE_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_MIRROR_CTRL, 2, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/**
 * 現在の画像を左右反転させる設定を取得する。
 * @param out_control_mode
 *         VC0706_CONTROL_MODE_GPIO
 *         VC0706_CONTROL_MODE_UART
 * @param out_control_mode
 *         VC0706_MIRROR_MODE_NOT_SHOW_MIRROR
 *         VC0706_MIRROR_MODE_SHOW_MIRROR
 */
VC0706_STATUS VC0706_MirrorStatus( uint8_t* out_control_mode, uint8_t* out_mirror_mode )
{
	uint8_t data[2];
	VC0706_STATUS status;
	VC0706_SendCommnad( VC0706_CMD_MIRROR_STATUS, 0, NULL );
	status = VC0706_ReceiveCommnad( 2, data );
	*out_control_mode = data[0];
	*out_mirror_mode  = data[1];
	return status;
}

/**
 * 色の制御設定。
 * @param control_mode
 *         VC0706_CONTROL_MODE_GPIO
 *         VC0706_CONTROL_MODE_UART
 * @param show_mode
 *         VC0706_SHOW_MODE_AUTOMATICALLY
 *         VC0706_SHOW_MODE_MANUALLY_SELECT_COLOUR
 *         VC0706_SHOW_MODE_MANUALLY_SELECT_BLACK_WHITE
 */
VC0706_STATUS VC0706_ColorCtrl( uint8_t control_mode, uint8_t show_mode )
{
	uint8_t data[2] = { control_mode, show_mode };
	if( control_mode >= VC0706_CONTROL_MODE_NUM || show_mode >= VC0706_SHOW_MODE_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_COLOR_CTRL, 2, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/**
 * 現在の色制御設定を取得する。
 * @param out_control_mode
 *         VC0706_CONTROL_MODE_GPIO
 *         VC0706_CONTROL_MODE_UART
 * @param out_control_mode
 *         VC0706_SHOW_MODE_AUTOMATICALLY
 *         VC0706_SHOW_MODE_MANUALLY_SELECT_COLOUR
 *         VC0706_SHOW_MODE_MANUALLY_SELECT_BLACK_WHITE
 * @param out_current_color 現在の色
 */
VC0706_STATUS VC0706_ColorStatus( uint8_t* out_control_mode, uint8_t* out_show_mode, uint8_t* out_current_color )
{
	uint8_t data[3];
	VC0706_STATUS status;
	VC0706_SendCommnad( VC0706_CMD_COLOR_STATUS, 0, NULL );
	status = VC0706_ReceiveCommnad( 3, data );
	*out_control_mode  = data[0];
	*out_show_mode     = data[1];
	*out_current_color = data[2];
	return status;
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_PowerSaveCtrl( uint8_t command_type, uint8_t control_item1, uint8_t control_item2, uint8_t control_item3 )
{
	uint8_t data[4] = { command_type, control_item1, control_item2, control_item3 };
	if( command_type == VC0706_POWER_SAVE_COMMAND_TYPE_CONTROL_MODE )
	{
		if( control_item1 >= VC0706_CONTROL_MODE_NUM || control_item2 >= VC0706_POWER_SAVE_NUM )
		{
			return VC0706_STATUS_ERR_FORMAT;
		}
	}
	else if( command_type == VC0706_POWER_SAVE_COMMAND_TYPE_ATTRIBUTE_CONFIGURATION )
	{
	}
	else
	{
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_POWER_SAVE_CTRL, command_type==VC0706_POWER_SAVE_COMMAND_TYPE_CONTROL_MODE? 3: 4, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_PowerSaveStatus( uint8_t command_type, uint8_t* out_control_item1, uint8_t* out_control_item2, uint8_t* out_control_item3 )
{
	uint8_t data[3] = {0};
	VC0706_STATUS status;
	if( command_type >= VC0706_POWER_SAVE_COMMAND_TYPE_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_POWER_SAVE_STATUS, 1, &command_type );
	status = VC0706_ReceiveCommnad( command_type == VC0706_POWER_SAVE_COMMAND_TYPE_CONTROL_MODE? 2: 3, data );
	*out_control_item1 = data[0];
	*out_control_item2 = data[1];
	*out_control_item3 = data[2];
	return status;
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_AE_Ctrl( uint8_t ae_attribute, uint8_t control_mode, uint8_t control_item )
{
	uint8_t data[] = { ae_attribute, control_mode, control_item };
	if( control_mode >= VC0706_CONTROL_MODE_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}

	switch( ae_attribute )
	{
	case VC0706_AE_ATTRIBUTE_SET_FREQUENCY:
		if( control_item >= VC0706_FREQUENCY_NUM )
		{
			return VC0706_STATUS_ERR_FORMAT;
		}
		break;
	case VC0706_AE_ATTRIBUTE_SET_STEP_MODE:
		if( control_item >= VC0706_STEP_MODE_NUM )
		{
			return VC0706_STATUS_ERR_FORMAT;
		}
		break;
	case VC0706_AE_ATTRIBUTE_BACKLIGHT_COMPENSATION:
		if( control_item >= VC0706_BACKLIGHT_COMPENSATION_NUM )
		{
			return VC0706_STATUS_ERR_FORMAT;
		}
		break;
	default:
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_AE_CTRL, 3, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_AE_Status( uint8_t ae_attribute, uint8_t* out_control_mode, uint8_t* out_control_item )
{
	uint8_t data[3];
	VC0706_STATUS status;
	if( ae_attribute >= VC0706_AE_ATTRIBUTE_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_AE_STATUS, 1, &ae_attribute );
	status = VC0706_ReceiveCommnad( 3, data );
	*out_control_mode = data[1];
	*out_control_item = data[2];
	return status;
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_MotionCtrl( uint8_t motion_attribute, uint8_t control_item1, uint8_t control_item2, uint8_t control_item3 )
{
	uint8_t data[4] = { motion_attribute, control_item1, control_item2, control_item3 };
	uint8_t data_length;
	switch( motion_attribute )
	{
	case VC0706_MOTION_ATTRIBUTE_MOTION_ENABLING:
		if( control_item1 >= VC0706_CONTROL_MODE_NUM || control_item2 >= VC0706_MOTION_MONITORING_NUM )
		{
			return VC0706_STATUS_ERR_FORMAT;
		}
		data_length = 3;
		break;
	case VC0706_MOTION_ATTRIBUTE_ALARM_ATTRIBUTE:
		data_length = 4;
		break;
	case VC0706_MOTION_ATTRIBUTE_ALARM_ENABLING_CONTROL:
		if( control_item1 >= VC0706_ALARM_OUTPUT_ENABLING_CONTROL_NUM )
		{
			return VC0706_STATUS_ERR_FORMAT;
		}
		data_length = 2;
		break;
	case VC0706_MOTION_ATTRIBUTE_ALARM_CONTROL:
		if( control_item1 >= VC0706_ALARM_OUTPUT_CONTROL_NUM )
		{
			return VC0706_STATUS_ERR_FORMAT;
		}
		data_length = 2;
		break;
	default:
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_MOTION_CTRL, data_length, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_MotionStatus( uint8_t motion_attribute, uint8_t* out_control_item1, uint8_t* out_control_item2, uint8_t* out_control_item3 )
{
	uint8_t data[4] = {0};
	const uint8_t DATA_LENGTH[] = { 3, 4, 2, 2 };
	VC0706_STATUS status;
	if( motion_attribute >= VC0706_MOTION_ATTRIBUTE_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_MOTION_STATUS, 1, &motion_attribute );
	status = VC0706_ReceiveCommnad( DATA_LENGTH[ motion_attribute ], data );
	*out_control_item1 = data[1];
	*out_control_item2 = data[2];
	*out_control_item3 = data[3];
	return status;
}

/**
 * ビデオ信号出力のON/OFF設定。
 * 出力を停止すると、CVBSはLow固定出力になる。
 * @param tv_output
 *         VC0706_TV_OUTPUT_STOP
 *         VC0706_TV_OUTPUT_START
 */
VC0706_STATUS VC0706_TV_OutCtrl( uint8_t tv_output )
{
	if( tv_output >= VC0706_TV_OUTPUT_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}
	VC0706_SendCommnad( VC0706_CMD_TV_OUT_CTRL, 1, &tv_output );
	return VC0706_ReceiveCommnad( 0, NULL );
}

VC0706_STATUS VC0706_OSD_AddChar( uint8_t x, uint8_t y, uint8_t char_num, const uint8_t* characters )
{
	uint8_t data[ 2 + VC0706_OSD_CHAR_MAX_NUM ];
	uint8_t i;

	if( char_num > VC0706_OSD_CHAR_MAX_NUM )
	{
		return VC0706_STATUS_ERR_LENGTH;
	}

	data[0] = char_num;
	data[1] = (x << 4) | y;
	for( i=0; i<char_num; i++ )
	{
		data[2 + i] = characters[i];
	}
	VC0706_SendCommnad( VC0706_CMD_OSD_ADD_CHAR, 2 + char_num, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/**
 * 画像サイズを変更する。
 * 160x480のように幅と高さの比が4:3でなくてもよい。
 * コマンド実行後必要な待ち時間 : 70ms
 * @param width_zoom
 *  width  = 640 : VC0706_ZOOMING_PROPORTION_NO_ZOOM
 *  width  = 320 : VC0706_ZOOMING_PROPORTION_HALF
 *  width  = 160 : VC0706_ZOOMING_PROPORTION_QUARTER
 * @param height_zoom
 *  height = 480 : VC0706_ZOOMING_PROPORTION_NO_ZOOM
 *  height = 240 : VC0706_ZOOMING_PROPORTION_HALF
 *  height = 120 : VC0706_ZOOMING_PROPORTION_QUARTER
 * note : コマンド実行後、70m以上待たずに画像を取得した場合、画像サイズ変更前のサイズで取得してしまう。
 */
VC0706_STATUS VC0706_DownsizeCtrl( uint8_t width_zoom, uint8_t height_zoom )
{
	uint8_t data;
	if( width_zoom >= VC0706_ZOOMING_PROPORTION_NUM || height_zoom >= VC0706_ZOOMING_PROPORTION_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}
	
	// プロトコル仕様書には Bit[3:2]：height となっているが、正しくは Bit[5:4]
	data = (height_zoom << 4) | width_zoom;

	// プロトコル仕様書にはのコマンド詳細には 0x53 となっているが、正しくはコマンド一覧の通り 0x54
	VC0706_SendCommnad( VC0706_CMD_DOWNSIZE_CTRL, 1, &data );

	return VC0706_ReceiveCommnad( 0, NULL );
}

/**
 * 画像サイズを取得し、引数のアドレスに格納する。
 * @param out_width_zoom
 *  width  = 640 : VC0706_ZOOMING_PROPORTION_NO_ZOOM
 *  width  = 320 : VC0706_ZOOMING_PROPORTION_HALF
 *  width  = 160 : VC0706_ZOOMING_PROPORTION_QUARTER
 * @param out_height_zoom
 *  height = 480 : VC0706_ZOOMING_PROPORTION_NO_ZOOM
 *  height = 240 : VC0706_ZOOMING_PROPORTION_HALF
 *  height = 120 : VC0706_ZOOMING_PROPORTION_QUARTER
 */
VC0706_STATUS VC0706_DownsizeStatus( uint8_t* out_width_zoom, uint8_t* out_height_zoom )
{
	uint8_t data;
	VC0706_STATUS status;

	// プロトコル仕様書にはのコマンド詳細には 0x54 となっているが、正しくはコマンド一覧の通り 0x55
	VC0706_SendCommnad( VC0706_CMD_DOWNSIZE_STATUS, 0, NULL );

	status = VC0706_ReceiveCommnad( 1, &data );
	
	// プロトコル仕様書には Bit[3:2]：height となっているが、正しくは Bit[5:4]
	*out_width_zoom  = data & 0x03;
	*out_height_zoom = (data >> 4) & 0x03;
	return status;
}

#if 0

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_GetFlashSize( uint32_t* out_size )
{
	uint8_t data[4];
	VC0706_STATUS status;
	VC0706_SendCommnad( VC0706_CMD_GET_FLASH_SIZE, 0, NULL );
	status = VC0706_ReceiveCommnad( 4, data );
	*out_size = ((uint32_t)data[0] << 24) | (data[1] << 16) | (data[2] << 8) | data[3];
	return status;
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_EraseFlashSector( uint32_t address )
{
	uint8_t data[4];
	VC0706_WriteArray32( data, address );
	VC0706_SendCommnad( VC0706_CMD_ERASE_FLASH_SECTOR, 4, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_EraseFlashAll( void )
{
	VC0706_SendCommnad( VC0706_CMD_ERASE_FLASH_ALL, 0, NULL );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_ReadLogo( uint8_t logo_lengths, uint32_t address )
{
	uint8_t data[2+4];
	VC0706_WriteArray16( &data[0], logo_lengths );
	VC0706_WriteArray32( &data[2], address );
	VC0706_SendCommnad( VC0706_CMD_READ_LOGO, 6, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

/* !!! 動作未確認 !!! */
VC0706_STATUS VC0706_SetBitmap( uint8_t control_type, uint16_t bitmap_lengths, uint32_t address )
{
	uint8_t data[7];
	data[0] = control_type;
	if( control_type >= VC0706_TRANSFER_BITMAP_NUM )
	{
		return VC0706_STATUS_ERR_FORMAT;
	}

	if( control_type == VC0706_TRANSFER_BITMAP_START )
	{
		VC0706_WriteArray16( &data[1], bitmap_lengths );
		VC0706_WriteArray32( &data[3], address );
	}

	VC0706_SendCommnad( VC0706_CMD_SET_BITMAP, control_type==VC0706_TRANSFER_BITMAP_START? 7: 1, data );
	return VC0706_ReceiveCommnad( 0, NULL );
}

#endif

