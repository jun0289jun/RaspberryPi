#include <wiringPi.h>
#include <softPwm.h>
#include <stdio.h>

// wpi. 4(BCM. 23, Physical. 16)
#define FAN_IA 4

//미풍
static void Week(){
	softPwmWrite(FAN_IA, 666);
	printf("Week\n");
	delay(5000);	
}

//약풍
static void Medium(){
	softPwmWrite(FAN_IA, 333);
	printf("Medium\n");
	delay(5000);	
}

//강풍
static void Strong(){
	softPwmWrite(FAN_IA, 0);
	printf("Strong\n");
	delay(5000);	
}

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