/*
TITLE : home
AUTHOR : jun
Version : 0.0.1
*/

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define FLAME 0 // Physical 11
#define SERVO 1 // Physical 12
#define FAN_IA 2 // Physical 13
#define BUZZER 4 // Physical 16


// 서보모터 제어 함수
static void Angle(int angle){
	
		softPwmWrite(SERVO,15-angle/10);

	delay(50);
}


int main (void){
	if(wiringPiSetup()==-1){return 1;}  // wiringPiSetup 검사, -1이면 프로그램 종료

	softPwmCreate(SERVO,0,180);
	pinMode(FLAME,INPUT);
	pinMode(BUZZER,OUTPUT);
	pinMode(FAN_IA,OUTPUT);
	
	for(;;){
		if(digitalRead(FLAME) == HIGH){  // 불꽃 센서가 감지했을 때 
			Angle(0);
			digitalWrite(FAN_IA,HIGH);
			digitalWrite(BUZZER,LOW);
		}else{   // 불꽃 센서에 아무것도 감지되지 않을 때 
			Angle(90);
			digitalWrite(FAN_IA,LOW);
			digitalWrite(BUZZER,HIGH);
		}
	}
	
}