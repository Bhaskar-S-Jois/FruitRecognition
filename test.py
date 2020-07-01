import numpy as np
import cv2
import subprocess
from PIL import ImageTk
import PIL.Image
import Tkinter as tkinter
import tkFileDialog as filedialog
window = tkinter.Tk()
global filename 
def dec2bin(num):
    y=[0,0,0]
    if(num==1):
        y[0]=0
        y[1]=0
        y[2]=1
    elif(num==2):
        y[0]=0
        y[1]=1
        y[2]=0
    elif(num==3):
        y[0]=0
        y[1]=1
        y[2]=1
    elif(num==4):
        y[0]=1
        y[1]=0
        y[2]=0
    elif(num==5):
        y[0]=1
        y[1]=0
        y[2]=1
    elif(num==6):
        y[0]=1
        y[1]=1
        y[2]=0
    else:
        y[0]=0
        y[1]=0
        y[2]=0
    return y
    
def BGR2HEX(color):
    return "{:02x}{:02x}{:02x}".format(int(color[2]), int(color[1]), int(color[0]))


def testing():
    filename= filedialog.askopenfilename()
    print(filename)
    img = ImageTk.PhotoImage(PIL.Image.open(filename))
    panel = tkinter.Label(window,image = img)
    panel.image=img
    panel.pack()
    img = cv2.imread(filename)
    imggrey = cv2.imread(filename,0)
    Z = img.reshape((-1,3))
    Z = np.float32(Z)
    criteria = (cv2.TERM_CRITERIA_EPS + cv2.TERM_CRITERIA_MAX_ITER, 10, 1.0)
    K = 2
    ret,label,center=cv2.kmeans(Z,K,None,criteria,10,cv2.KMEANS_RANDOM_CENTERS)
    _, counts = np.unique(label, return_counts=True)
    center = np.uint8(center)
    res = center[label.flatten()]
    hex1=BGR2HEX(center[0])
    hex2=BGR2HEX(center[1])
    color=[0.0,0.0,0.0]
    x=[0.0,0.0,0.0]
    y1=[0,0,0]
    sum=0
    for j in range (0,2):
        sum=0
        for i in range (0,3):
            color[i]=center[j][i]
            sum=sum+color[i]
        if(sum<750):
            for i in range (0,3):
                    x[i]=color[2-i]/float(sum)
    print(x)
    _, threshold = cv2.threshold(imggrey, 240, 255, cv2.THRESH_BINARY)
    _, contours, _ = cv2.findContours(threshold, cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
    for cnt in contours:
        approx = cv2.approxPolyDP(cnt, 0.01*cv2.arcLength(cnt, True), True)
        cv2.drawContours(img, [approx], 0, (0), 5)
        if((len(approx))>5):
            print("Number of lines:"+str(len(approx)))
            if((len(approx))<9 or (len(approx))>14):
                continue
            else:
                number=(len(approx))-8
                y1=dec2bin(number)
                print(y1)
        
                
    
    f=open("info.txt","w")
    f.write(str('%.2f'%x[0]))
    f.write(" ")
    f.write(str('%.2f'%x[1]))
    f.write(" ")
    f.write(str('%.2f'%x[2]))
    f.write(" ")
    f.write(str(y1[0]))
    f.write(" ")
    f.write(str(y1[1]))
    f.write(" ")
    f.write(str(y1[2]))
    f.write(" ")
    f.close()
    subprocess.call(["gcc", "testing.c"])
    subprocess.call("./a.out")
    f=open("returnvalue.txt","r");
    tmp=float(f.read())
    if(tmp==1.0):
        labelresult = tkinter.Label(window,text = "Its an Apple.!!!").pack(side='top')	
    elif(tmp==2.0):
        labelresult = tkinter.Label(window,text = "Its a Papaya.!!!").pack(side='top')
    elif(tmp==3.0):
        labelresult = tkinter.Label(window,text = "Its an Orange.!!!").pack(side='top')
    elif(tmp==4.0):
        labelresult = tkinter.Label(window,text = "Its a Kiwi.!!!").pack(side='top')
    elif(tmp==5.0):
        labelresult = tkinter.Label(window,text = "Its a Pear.!!!").pack(side='top')
    elif(tmp==6.0):
        labelresult = tkinter.Label(window,text = "Its a Lemon.!!!").pack(side='top')
    elif(tmp==7.0):
        labelresult = tkinter.Label(window,text = "Its a Green Mango.!!!").pack(side='top')
    elif(tmp==8.0):
        labelresult = tkinter.Label(window,text = "Its a Strawberry.!!!").pack(side='top')
    elif(tmp>8.0):
        temp=int(tmp)-7
        pro=tmp-int(tmp)
        if(temp==1):
            labelresult = tkinter.Label(window,text = "It maybe an Apple with accuracy of "+str(pro)).pack(side='top')	
        elif(temp==2):
            labelresult = tkinter.Label(window,text = "It maybe a Papaya with accuracy of "+str(pro)).pack(side='top')
        elif(temp==3):
            labelresult = tkinter.Label(window,text = "It maybe an Orange with accuracy of "+str(pro)).pack(side='top')
        elif(temp==4):
            labelresult = tkinter.Label(window,text = "It maybe a Kiwi with accuracy of "+str(pro)).pack(side='top')
        elif(temp==5):
            labelresult = tkinter.Label(window,text = "It maybe an Pear with accuracy of "+str(pro)).pack(side='top')
        elif(temp==6):
            labelresult = tkinter.Label(window,text = "It maybe a Lemon with accuracy of "+str(pro)).pack(side='top')
        elif(temp==7):
            labelresult = tkinter.Label(window,text = "It maybe a Green Mango with accuracy of "+str(pro)).pack(side='top')
        elif(temp==8):
            labelresult = tkinter.Label(window,text = "It maybe a Strawberry with accuracy of "+str(pro)).pack(side='top')
    else:
        labelresult = tkinter.Label(window,text = "Sorry.!!! I can't identify this fruit.!").pack(side='top')
    

    tkinter.mainloop()
    
window.minsize(600,400)
window.title("Classification of fruits")
label1 = tkinter.Label(window,text = "Insert a fruit image to recognize the fruit").pack(side='top')
button = tkinter.Button(window,text="Browse", command=testing).pack()



tkinter.mainloop()


