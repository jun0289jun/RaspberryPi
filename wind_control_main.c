#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

#include "wind_control_module.h"



int main(void) {
	
	int c;
	
	if(wiringPiSetup() == -1){
		return 1;
	}
	
	softPwmCreate(FAN_IA, 0, 1000);
	
	//무한루프
	while(1){
		scanf("%c", &c);
		
		if(c == 'w'){
			Week();
		}
		
		if(c == 'm'){
			Medium();;
		}
		
		if(c == 's'){
			Strong();
		}
		
		if(c == 'x'){
			Stop();
		}
		
		
	}
	return 0;
}