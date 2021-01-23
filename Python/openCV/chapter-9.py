#Object and face detection
import cv2 as cv
import numpy as np

path = "/home/london/Pictures/OpenCV/lena.png"
cascade_path = "/home/london/Pictures/OpenCV/haarcascades/haarcascade_frontalface_default.xml"
faceCascade = cv.CascadeClassifier(cascade_path)
img = cv.imread(path)
imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

faces = faceCascade.detectMultiScale(imgGray, 1.1, 4) 

for (x, y, w, h) in faces:
    cv.rectangle(img, (x, y), (x+w, y+h), (0, 0, 0), 2) 

cv.imshow("Face detection", img)

while (cv.waitKey(1) != ord('q')):
    pass
