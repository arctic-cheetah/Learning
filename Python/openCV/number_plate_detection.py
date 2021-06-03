import cv2 as cv
import numpy as np

#Important constants!
height = 360
width = 640
minArea = 500
txtColor = (0, 0, 0xff)

cascade_path = "/home/london/Pictures/OpenCV/haarcascades/haarcascade_russian_plate_number.xml"
numberPlates = cv.CascadeClassifier(cascade_path)

cam = cv.VideoCapture(-1)
cam.set(cv.CAP_PROP_FRAME_WIDTH, width)
cam.set(cv.CAP_PROP_FRAME_HEIGHT, height)
cam.set(cv.CAP_PROP_BRIGHTNESS, 150)

i = 0
while (cv.waitKey(1) != ord('q')):
    success, img = cam.read()
    imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

    plates = numberPlates.detectMultiScale(imgGray, 1.1, 4) 
    imgRoi = 0
    #Create a border
    for (x, y, w, h) in plates:
        area = w*h
        if (area > minArea):
            cv.rectangle(img, (x, y), (x+w, y+h), (0, 0, 0xff), 2) 
            cv.putText(img, "Number Plate", (x, y - 5), 
                       cv.FONT_HERSHEY_PLAIN, 1, txtColor, 1)
            imgRoi = img[y:y+h, x:x+w]
            cv.imshow("Selected Plate", imgRoi)
    #Save number plate as an image
    if (cv.waitKey(1) == ord('s')):
        cv.imwrite("/home/london/Pictures/OpenCV/plate" + str(i) + ".jpg", imgRoi)
        cv.rectangle(img, (0, 200), (width, height), txtColor, cv.FILLED)
        cv.putText(img, "Scan saved", (150, 265), cv.FONT_HERSHEY_PLAIN, 2
                   ,(0xff, 0, 0), 2)
        cv.imshow("Plate", img)
        cv.waitKey(2000)
        i +=1

    cv.imshow("Plate", img)
