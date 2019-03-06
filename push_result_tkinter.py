import tkinter
root=tkinter.Tk()
def func():
    label.config(text='Pushed')

def func_event(ev):
    label.config(text='Push Button')

label=tkinter.Label(root, text='Push Button')
label.pack()
button=tkinter.Button(root, text='Push!', command=func)    

button.pack()
button.bind('<Leave>', func_event)
root.mainloop()

