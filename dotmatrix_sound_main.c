/*
 * dotmatrix__sound.c
 *
 *  Created on: 2019. 1. 24.
 *      Author: JUN
 */

#include <stdio.h>
#include <wiringPi.h>
#include <wiringPiSPI.h>

#include "dotmatrix_sound_module.h"



int main(void){
	
	int sound = 0; //사운드 센서 변수
	
	if(wiringPiSPISetup(SPI_CHANNEL,SPI_SPEED) == -1){ 
		printf ("error"); 
		return -1;
	}
	
		//wiringPiSetup 실패시
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed!");
		return 1;
	}
	
	delay(200);
		printf("8x8 dot matrix ON!\n");
	while(1){		

		void data_88led;
		
		
		static void basic();
		static void noise();
		static void back();
			
		
	}
	return 0;
}