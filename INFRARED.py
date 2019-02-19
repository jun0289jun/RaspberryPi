import RPi.GPIO as GPIO

INFRARED = 7
LED = 10

GPIO.setmode(GPIO.BCM)
GPIO.setup(INFRARED, GPIO.IN)
GPIO.setup(LED, GPIO.OUT)


try :
    while True :
        if GPIO.input(INFRARED) ==1 :
            GPIO.output(LED, True)
        else :
            GPIO.output(LED, False)
except :
    GPIO.cleanup()
    print("end")
