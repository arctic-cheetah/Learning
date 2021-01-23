#Colour detection
import cv2 as cv
import numpy as np
from stack_images import stackImages

path = "/home/london/Pictures/OpenCV/tennis-ball-l.jpg"
img = cv.imread(path)
print(img.shape)

#Create a window to read HSV 
def empty(a):
    pass
cv.namedWindow("TrackBars")
cv.resizeWindow("TrackBars", 640, 480)
cv.createTrackbar("Hue Min", "TrackBars", 23, 179, empty)
cv.createTrackbar("Hue Max", "TrackBars", 179, 179, empty)

cv.createTrackbar("Sat Min", "TrackBars", 70, 255, empty)
cv.createTrackbar("Sat Max", "TrackBars", 255, 255, empty)

cv.createTrackbar("Val Min", "TrackBars", 114, 255, empty)
cv.createTrackbar("Val Max", "TrackBars", 255, 255, empty)


imgHSV = cv.cvtColor(img, cv.COLOR_BGR2HSV)


while (cv.waitKey(1) != ord('q')):
    h_min = cv.getTrackbarPos("Hue Min", "TrackBars")
    h_max = cv.getTrackbarPos("Hue Max", "TrackBars")

    s_min = cv.getTrackbarPos("Sat Min", "TrackBars")
    s_max = cv.getTrackbarPos("Sat Max", "TrackBars")
    
    v_min = cv.getTrackbarPos("Val Min", "TrackBars")
    v_max = cv.getTrackbarPos("Val Max", "TrackBars")

    lower = np.array([h_min, s_min, v_min])
    upper = np.array([h_max, s_max, v_max])
    mask = cv.inRange(imgHSV, lower, upper)

    imgRes = cv.bitwise_and(img, img, mask = mask)

    cv.imshow("Original", img)
    #cv.imshow("HSV", imgHSV)
    #cv.imshow("Mask", mask)
    #cv.imshow("Result", imgRes)

    imgStack = stackImages(0.6, ([img, imgHSV], [mask, imgRes]))
    cv.imshow("Stacked images", imgStack)
