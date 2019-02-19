#include <wiringPi.h>
#include <stdio.h>


#define LedPin 1

int main(void) {
	if(wiringPiSetup() == -1){
		printf("setup wiringPi failed !");
		return 1;
	}
	printf("linker LedPin : GPIO %d(wiringPi pin\n", LedPin);
	pinMode(LedPin, OUTPUT);
	
	while(1){
		digitalWrite(LedPin, HIGH);
		printf("LED ON...\n");
		delay(500);
		digitalWrite(LedPin, LOW);
		printf("LED OFF...\n");
		delay(500);
	}
	return 0;
}