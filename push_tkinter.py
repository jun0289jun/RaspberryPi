import tkinter
root=tkinter.Tk()
def func():
    print ('Pushed')

button=tkinter.Button(root, text='Push!', command=func)
button.pack()
root.mainloop()
