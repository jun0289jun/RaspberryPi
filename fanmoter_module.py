import time

# 왼쪽으로 2초 회전 
def Left_2_Second(GPIO, a, b):
	GPIO.output(a, True) 
	GPIO.output(b, False) 
	time.sleep (2)
	
# 오른쪽으로 2초 회전
def Right_2_Second(GPIO, a, b):
	GPIO.output(a, False) 
	GPIO.output(b, True) 
	time.sleep(2)
	
# 정지상태로 2초 대기
def Wait_2_Second(GPIO, a, b):
	GPIO.output(a, False) 
	GPIO.output(b, False) 
	time.sleep (2)
