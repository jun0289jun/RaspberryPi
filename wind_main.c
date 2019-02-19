#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#include "wind_module.h"



int main(void) {
	
	if(wiringPiSetup() == -1){
		return 1;
	}
	
	softPwmCreate(FAN_IA, 0, 1000);
	
	//무한루프
	while(1){
		Week();
		Medium();
		Strong();
	}
	return 0;
}