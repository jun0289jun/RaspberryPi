import RPi.GPIO as GPIO
import time

LED = 18

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False) 
GPIO.setup(LED, GPIO.OUT)

pwm = GPIO.PWM(LED, 200)

pwm.start(0)

try :
    while True :
        for value in range(0, 1024) :

            pwm.ChangeDutyCycle(value / 10.23)
            time.sleep(0.005)
except :
    pwm.stop()
    GPIO.cleanup()
