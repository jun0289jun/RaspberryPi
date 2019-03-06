import tkinter
root=tkinter.Tk()

def func1():
    label.config(text='Button1')
def func2():
    label.config(text='Button2')

sel=tkinter.IntVar()
sel.set(1)
label=tkinter.Label(root, text='Select Button')
label.pack()

rb1=tkinter.Radiobutton(root, text='Button 1', variable=sel, value=1, command=func1)
rb1.pack()
rb2=tkinter.Radiobutton(root, text='Button 2', variable=sel, value=2, command=func2)
rb2.pack()

root.mainloop()

