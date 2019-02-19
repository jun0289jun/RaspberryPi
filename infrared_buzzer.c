#include <wiringPi.h> 
#include <stdio.h>

#define INFRARED 11 // wPi. 11(BCM. 7, Physical. 26) 
#define BUZZER 0 // wPi. O(BCM. 17, Physical. 11) 
#define LED 1 // wPi. 1(BCM. 18, Physical. 12)

int main (void) {
	if (wiringPiSetup() == -1) { return 1; } 
	// wiringPi 비활성화시 종료
	
	pinMode(INFRARED, INPUT); 
	// 적외선 센서는 감지 여부를 전송해 주므로 INPUT이다. 
	pinMode(BUZZER, OUTPUT); 
	pinMode(LED, OUTPUT);
	
	for (;;) {
	// 무한루프

	if (digitalRead(INFRARED) == HIGH) {
			// 적외선 센서가 감지했을 때 
			digitalWrite(BUZZER, HIGH);
			digitalWrite(LED, HIGH);
			printf("1");
		} else {
			// 적외선 센서에 아무것도 감지되지 않을 때 
			digitalWrite(BUZZER, LOW); 
			digitalWrite(LED, LOW);
			printf("0");
		}
	}
	return 0;

}