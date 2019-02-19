import RPi.GPIO as GPIO 
import fanmoter_module as MOTER

FAN_IA = 23 # BCM. 23, wPi. 4, Physical. 16 
FAN_IB = 24 # BCM. 24, WPi. 5, Physical. 18

GPIO.setmode(GPIO.BCM) 
GPIO.setup(FAN_IA, GPIO.OUT) 
GPIO.setup(FAN_IB, GPIO.OUT)

# 파일 실행시 작동
if __name__ == "__main__" :
	try :
		#무한루프
		while True :
            MOTER.Left_2_Second(GPIO, FAN_IA, FAN_IB)
			MOTER.Wait_2_Second(GPIO, FAN_IA, FAN_IB)
			MOTER.Right_2_Second(GPIO, FAN_IA, FAN_IB)
			MOTER.Wait_2_Second(GPIO, FAN_IA, FAN_IB)
			
	# Ctrl-C 종료시
	except :
		GPIO.cleanup()
		print("end")
