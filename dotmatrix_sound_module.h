#include <stdio.h>

#define SPI_SPEED 1000000 //Serial Peripheral Interface 직렬 주변 장치 인터페이스
#define BRIGHT 0
#define SPI_CHANNEL 0

#define LED_G 21 // Physical 29 /GPIO.21/wPi 21/BCM 5
#define LED_R 22 // Physical 31 /GPIO.22/wPi 22/BCM 6
// 도트매트릭스 신호 설정

void data_88led (unsigned char msb, int lsb, int select){
	int i;
	unsigned char out[2] = {0};
	out[0] = msb;
	if(select == 2){
		for(i=0;i<8;i++){
			out[1] |= ((lsb%10)<<1);
			lsb = lsb/10;
		}
	}else{
		out[1] = lsb;
	}
	wiringPiSPIDataRW(SPI_CHANNEL,out,2);
}


// 도트매트릭스 열 정보
void init_88led_spi(void){
	unsigned char out[2];
	int i;
	data_88led(0x0B,0x07,0);
	data_88led(0x09,0x00,0);
	data_88led(0x0F,0x00,0);
	data_88led(0x0A,BRIGHT,0);
	data_88led(0x0C,0x01,0);
	for(i=1;i<9;i++){
		data_88led(i,0,0);
	}
}


	pinMode(LED_G, OUTPUT); // 핀모드 출력설정
	pinMode(LED_R, OUTPUT); // 핀모드 출력설정

//기본 얼글	
static void basic(){
	if(sound <= 0){//음성 데이터가 0 이하일 때

			//LED 초기화
			digitalWrite(LED_G, LOW); //적색등 OFF
			digitalWrite(LED_R, LOW); //녹색등 OFF
			
			digitalWrite(LED_R, LOW); //적색등 OFF
			digitalWrite(LED_G, HIGH); // 녹색등 ON

			data_88led (1, 0x00, 0);
			data_88led (2, 0x06, 0);
			data_88led (3, 0x36, 0);
			data_88led (4, 0x40, 0);
			data_88led (5, 0x40, 0);
			data_88led (6, 0x36, 0);
			data_88led (7, 0x06, 0);
			data_88led (8, 0x00, 0);
			delay(1000);
			//눈감기
			data_88led (2, 0x04, 0);
			data_88led (3, 0x34, 0);
			data_88led (6, 0x34, 0);
			data_88led (7, 0x04, 0);
			delay(100);
			//눈뜨기
			data_88led (2, 0x06, 0);
			data_88led (3, 0x36, 0);
			data_88led (6, 0x36, 0);
			data_88led (7, 0x06, 0);
			delay(1000);
	}
}
// 찡그린 얼굴
static void noise(){	
	if(sound >= 0){//음성 데이터가 0 이상일 때

			//LED 초기화
			digitalWrite(LED_G, LOW); //적색등 OFF
			digitalWrite(LED_R, LOW); //녹색등 OFF
			
			digitalWrite(LED_G, LOW); //적색등 OFF
			digitalWrite(LED_R, HIGH); // 녹색등 ON

			data_88led (1, 0x00, 0);
			data_88led (2, 0x04, 0);
			data_88led (3, 0x62, 0);
			data_88led (4, 0x10, 0);
			data_88led (5, 0x10, 0);
			data_88led (6, 0x62, 0);
			data_88led (7, 0x04, 0);
			data_88led (8, 0x00, 0);
			delay(2000);
		}
	
}	

static void back(){	
	//얼굴 초기화
	data_88led (1, 0x00, 0);
	data_88led (2, 0x00, 0);
	data_88led (3, 0x00, 0);
	data_88led (4, 0x00, 0);
	data_88led (5, 0x00, 0);
	data_88led (6, 0x00, 0);
	data_88led (7, 0x00, 0);
	data_88led (8, 0x00, 0);
}