#include <stdio.h>
#include <wiringPi.h>




#define LedPinY 0
#define LedPinG 2
#define LedPinO 3



int main(void) {

	if(wiringPiSetup() == -1){

		printf("setup wiringPi failed !");

		return 1;

	}

	printf("linker LedPin : GPIO %d(wiringPi pin)\n", LedPinY);
	printf("linker LedPin : GPIO %d(wiringPi pin)\n", LedPinG);
	printf("linker LedPin : GPIO %d(wiringPi pin)\n", LedPinO);

	pinMode(LedPinY, OUTPUT);
	pinMode(LedPinG, OUTPUT);
	pinMode(LedPinO, OUTPUT);

	

	while(1){

		digitalWrite(LedPinY, HIGH);
		printf("LED YELLOW ON...\n");
		delay(200);

		digitalWrite(LedPinY, LOW);
		printf("LED YELLOW OFF...\n");
		delay(200);

		digitalWrite(LedPinG, HIGH);
		printf("LED GREEN ON...\n");
		delay(200);

		digitalWrite(LedPinG, LOW);
		printf("LED GREEN OFF...\n");
		delay(200);
		
		digitalWrite(LedPinO, HIGH);
		printf("LED ORANGE ON...\n");
		delay(200);

		digitalWrite(LedPinO, LOW);
		printf("LED ORANGE OFF...\n");
		delay(200);
		
		digitalWrite(LedPinG, HIGH);
		printf("LED GREEN ON...\n");
		delay(200);

		digitalWrite(LedPinG, LOW);
		printf("LED GREEN OFF...\n");
		delay(200);
	}

	return 0;

}