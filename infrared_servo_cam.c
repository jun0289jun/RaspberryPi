/**
*	Title : HomeCamExmples
*	Author : Lee Yeh Seob
*	Version : 0.0.2
*/

#include <stdio.h>
#include <wiringPi.h>
#include <softPwm.h>

#define SERVO 2  // 서보모터 wPi 2. (Physical 13. BCM 27.)

static void Angle(int angle){ // 각도 변경 함수 각도값은 15를 중심으로 6~24 사이
	softPwmWrite(SERVO,15-angle/10);
}

int main (void){
	
	if(wiringPiSetup() == -1){return 1;} //wiringPi 셋업 검사 , 이상 발생시 종료
	softPwmCreate(SERVO,0,180); //softPwm 객체 생성
	
	char input; // 입력값 변수
	char off;   // 종료값 변수
	static int currentAngle = 0;//현재 각도
	
	
	do{
		printf("###################카메라 프로그램################### \n");
			printf("A: 왼쪽으로 10도  | D: 오른쪽으로 10도 |\n");
			printf("Z:  왼쪽  45도    | C:  오른쪽  45도   |\n");
			printf("S:    초기화      | Q:      종료       |\n");
		while(1){
			/*
			입력을 받을때 A면 왼쪽으로, D 면오른쪽으로
			10도씩 이동하며,
			S를 통해 각도를 초기화 합니다.
			Q를 누르면 각도를 초기화 하고 
			종료합니다.
			이 외의 입력은 동작하지 않으며,
			조건검사로 이동합니다.
			Z와 C 는 각각 왼쪽, 오른쪽으로 45도 방향을 보게 합니다. 
			*/
			scanf("%s",&input);
			
			if(input=='a'||input == 'A'){
				currentAngle -=10;
				if(currentAngle <-90){
					currentAngle = -90;
				}
				printf("현재 각도 : %d \n",currentAngle);
				Angle(currentAngle);
			}else if(input=='d'||input=='D'){
				currentAngle +=10;
				if(currentAngle > 90){
					currentAngle = 90;
				}
				printf("현재 각도 : %d \n",currentAngle);
				Angle(currentAngle);
			}else if(input =='s'||input=='S'){
				currentAngle =0;
				printf("###################    초기화    ################### \n");
				printf("현재 각도 : %d \n",currentAngle);
				Angle(currentAngle);
			}else if(input=='z'||input=='Z'){
				currentAngle =-45;
				printf("현재 각도 : %d \n",currentAngle);
				Angle(currentAngle);
			}else if(input=='c'||input=='C'){
				currentAngle =45;
				printf("현재 각도 : %d \n",currentAngle);
				Angle(currentAngle);
			}else if(input=='q'||input=='Q'){
				currentAngle =0;
				Angle(currentAngle);
				break;
			}else{
				continue;
			}
		}
		//종료루틴 , 입력값이 Y가 아니면 프로그램을 종료합니다.
		printf("계속하시겠습니까? :[Y,N]");
		scanf("%s",&off);
	}while(off == 'y'||off == 'Y');
	return 0;
}