#include <wiringPi.h>
#include <softPwm.h> 
#include <stdio.h>

#define INFRARED 11 // wPi. 11(BCM. 7, Physical. 26) 
#define BUZZER 0 // wPi. O(BCM. 17, Physical. 11) 
#define LED 1 // wPi. 1(BCM. 18, Physical. 12)
#define SERVO 2 // wpi. 2, BCM. 27, Physical. 13)
// 서보모터의 각도는 -90도 부터 90도 까지 가능


static void Angle(int angle) {
	softPwmWrite(SERVO, 15 - angle / 10);
	printf("%d\n", angle);
	delay(1000);
}

int main (void) {
	if (wiringPiSetup() == -1) { return 1; } 
	// wiringPi 비활성화시 종료
	
	pinMode(INFRARED, INPUT); 
	// 적외선 센서는 감지 여부를 전송해 주므로 INPUT이다. 
	pinMode(BUZZER, OUTPUT); 
	pinMode(LED, OUTPUT);
	pinMode(SERVO, OUTPUT);
	
	for (;;) {
	// 무한루프

	if (digitalRead(INFRARED) == HIGH) {
			// 적외선 센서가 감지했을 때 
			digitalWrite(BUZZER, HIGH);
			digitalWrite(LED, HIGH);
			printf("1");
			
			softPwmCreate(SERVO, 0, 180);
			Angle(0);
			Angle(30);
			Angle(60);
			Angle(90);
			Angle(60);
			Angle(30);
			Angle(0);
			Angle(-30);
			Angle(-60);
			Angle(-90);
			Angle(-60);
			Angle(-30);
			Angle(0);

		} else {
			// 적외선 센서에 아무것도 감지되지 않을 때 
			digitalWrite(BUZZER, LOW); 
			digitalWrite(LED, LOW);
			printf("0");
		}
	}
	return 0;

}