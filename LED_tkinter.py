import RPi.GPIO as GPIO
import tkinter
GPIO.setmode(GPIO.BOARD)

LED=11

GPIO.setup(LED, GPIO.OUT, initial=GPIO.LOW)

def func():
    GPIO.output(LED, not GPIO.input(LED))
root=tkinter.Tk()
label=tkinter.Label(root, text='press button')
label.pack()

button=tkinter.Button(root, text='LED', command=func)
button.pack()
root.mainloop()
GPIO.cleanup()
