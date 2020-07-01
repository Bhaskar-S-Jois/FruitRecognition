import numpy as np
import cv2
import subprocess
from PIL import ImageTk
import PIL.Image
import Tkinter as tkinter
import tkFileDialog as filedialog
window = tkinter.Tk()
def button_show():
    epoch=e1.get()
    rate=e2.get()
    subprocess.call(["gcc", "feature.c"])
    tmp=subprocess.call(["./a.out",epoch,rate])
    subprocess.call(["gcc", "color.c"])
    tmp=subprocess.call(["./a.out",epoch,rate])
    labelresult = tkinter.Label(window,text = "Network trained.!").pack(side='top')



tkinter.Label(window, text="Epoch").pack()    
e1 = tkinter.Entry(window)
e1.pack()

tkinter.Label(window, text="Learning Rate").pack()
e2 = tkinter.Entry(window)
e2.pack()
 
    
window.minsize(400,400)
buttontrain=tkinter.Button(window,text="Train the network", command=button_show).pack()

window.mainloop()
