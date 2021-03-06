#include <wiringPi.h>
#include <stdio.h>

#define FAN_IA 4
#define FAN_IB 5

static void Left_2_Second() {
	digitalWrite(FAN_IA, HIGH);
	digitalWrite(FAN_IB, LOW);
	delay(1000);
}

static void Right_2_Second() {
	digitalWrite(FAN_IA, LOW);
	digitalWrite(FAN_IB, HIGH);
	delay(1000);
}

static void Wait_2_Second() {
	digitalWrite(FAN_IA, LOW);
	digitalWrite(FAN_IB, LOW);
	delay(1000);
}

int main (void) {
		if (wiringPiSetup() == -1) {return 1;}
		
		pinMode(FAN_IA, OUTPUT);
		pinMode(FAN_IB, OUTPUT);
		
		//무한루프
		while (1) {
				Left_2_Second();
				Wait_2_Second();
				Right_2_Second();
				Wait_2_Second();
		}
		return 0;
}