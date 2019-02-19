#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <wiringPi.h>
#define LED 0

	
int main (void){

	if (wiringPiSetup()== -1){
		printf("Setup wiringPi failed!");
		return 1;
	}
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, OUTPUT);
	
	while(1){
		
		int i;	
		
		for(i=0; i<1; i++){
		int rand_num;
		srand((unsigned)time(NULL));
		rand_num=rand()%2000;
		digitalWrite(0, HIGH);
		printf("%d\n",rand_num);
		printf("LED 0 ON.... \n");
		delay(rand_num);
		digitalWrite(0, LOW);
		printf("LED 0 OFF.. \n");
		delay(10);
				}
		for(i=0; i<1; i++){
		int rand_num;
		srand((unsigned)time(NULL));
		rand_num=rand()%2000;
		digitalWrite(1, HIGH);
		printf("%d\n",rand_num);
		printf("LED 1 ON.... \n");
		delay(rand_num);
		digitalWrite(1, LOW);
		printf("LED 1 OFF.. \n");
		delay(10);
				}
				
		for(i=0; i<1; i++){
		int rand_num;
		srand((unsigned)time(NULL));
		rand_num=rand()%2000;
		digitalWrite(2, HIGH);
		printf("%d\n",rand_num);
		printf("LED 2 ON.... \n");
		delay(rand_num);
		digitalWrite(2, LOW);
		printf("LED 2 OFF.. \n");
		delay(10);		
				}
	}
	
	return 0;
}
