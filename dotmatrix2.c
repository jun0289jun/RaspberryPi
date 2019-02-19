#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>
#define SPI_SPEED 1000000
#define BRIGHT 0
#define SPI_CHANNEL 0

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
int main(void){
	if(wiringPiSPISetup(SPI_CHANNEL,SPI_SPEED) == -1){ printf ("error"); return -1;}
	
	delay(200);
		printf("8x8 dot matrix test!\n");
	//while(1){
		init_88led_spi();
		data_88led(1,0x00,0);
		delay(200);
		data_88led(2,0x00,0);
		delay(200);
		data_88led(3,0x66,0);
		delay(200);
		data_88led(4,0x66,0);
		delay(200);
		data_88led(5,0x00,0);
		delay(200);
		data_88led(6,0x24,0);
		delay(200);
		data_88led(7,0x24,0);
		delay(200);
		data_88led(8,0x18,0);
		delay(500);
		data_88led(3,0x00,0);
		delay(500);
		data_88led(3,0x66,0);
		delay(500);
		data_88led(3,0x00,0);
		delay(500);
		data_88led(3,0x66,0);
		delay(3000);
		while(1){
			data_88led(3,0x00,0);
			delay(1000);
			data_88led(3,0x66,0);
			delay(1000);
			data_88led(3,0x00,0);
			delay(500);
			data_88led(3,0x66,0);
			delay(3000);
			data_88led(7,0x3C,0);
			delay(30);
			data_88led(7,0x24,0);
			data_88led(6,0x3C,0);
			data_88led(7,0x24,0);
			delay(3000);
			data_88led(6,0x24,0);
			data_88led(7,0x3C,0);
			delay(30);
			data_88led(7,0x24,0);
			delay(3000);
			data_88led(3,0x60,0);
			delay(500);
			data_88led(3,0x66,0);
			delay(3000);
		}
	//}
	return 0;
}