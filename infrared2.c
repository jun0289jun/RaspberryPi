#include <wiringPi.h> 
#include <stdio.h>
#define INFRARED 11 // WPi. 11(BCM. 7, Physical. 26) 
#define LED 12 // wPi. 12(BCM. 10, Physical. 19)

int main (void) {
	if (wiringPiSetup() == -1) { return 1; }
	// wiringPi 비활성화시 종료

	pinMode(INFRARED, INPUT); 
	// 적외선 센서는 감지 여부를 전송해주므로 INPUT이다. 
	pinMode(LED, OUTPUT);
	
	for (;;) {
	// 무한루프

		if (digitalRead(INFRARED) == HIGH) {
			// 적외선 센서가 감지했을 때
			digitalWrite(LED, HIGH); 
			printf("1");
			} else {
			 //적외선 센서에 아무것도 감지되지 않을 때
			digitalWrite(LED, LOW);
			printf("0");
			}
	}
		return 0;
}