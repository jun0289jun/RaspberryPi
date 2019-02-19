#include<stdio.h>
#include<wiringPi.h>

#define A 13
#define B 14
#define C 4
#define D 5
#define E 21
#define F 22
#define G 23

unsigned char SEGMENTS[7] = {A, B, C, D, E, F, G};
unsigned char NUMBER[10][7] = {
	{0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 1, 1, 1},
	{0, 0, 1, 0, 0, 1, 0},
	{0, 0, 0, 0, 1, 1, 0},
	{1, 0, 0, 1, 1, 0, 0},
	{0, 1, 0, 0, 1, 0, 0},
	{0, 1, 0, 0, 0, 0, 0},
	{0, 0, 0, 1, 1, 1, 1},
	{0, 0, 0, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 0, 0}
};

int main(void){
	if(wiringPiSetup() == -1){return 1;}
	
	for (char i = 0; i < 7 ; i++){
		pinMode(SEGMENTS[i], OUTPUT);
	}
	
	while(1) {
		for (char i = 0; i < 10 ; i++) {
			for (char j = 0 ; j < 7 ; j++) {
				digitalWrite(SEGMENTS[j], NUMBER[i][j]);
			}
			delay(500);
			
		}
	}
}