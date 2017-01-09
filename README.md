# VC0706-serial-camera-driver

小型TTLシリアルJPEGカメラ（NTSCビデオ出力付）用のドライバ。  
<http://akizukidenshi.com/catalog/g/gM-07746/>

プロトコル仕様書 : <https://cdn-shop.adafruit.com/datasheets/VC0706protocol.pdf>  
*誤記が多いため注意*

## RX62N用サンプルプロジェクト
* カメラで撮影した画像をPCにUARTで転送するプログラム。  
* 使用例として Interface2011年5月号の RX62N (R5F562N7BDFB) 基板で動作させている。  
* E1エミュレータが必要。  
* サンプルプロジェクトはROMを使わず、すべてRAMで動作させるように設定してある。  
これはRX62NのROMの書き換え保障回数は1000回しかなく、ROMを劣化させないため。  
プロジェクトのリンクオプションのセクション FIXEDVECT のアドレスが 0x0000FFD0 になっているが、  
0xFFFFFFD0 に変えて一度RX62Nに書き込んだ後、元の0x0000FFD0に戻すこと。
* Renesas Peripheral Driver Library を使用している。  
<https://www.renesas.com/ja-jp/products/software-tools/tools/code-generator/renesas-peripheral-driver-library.html>  

![読み出し時間](/src/camera/Time_to_read_image.png")
