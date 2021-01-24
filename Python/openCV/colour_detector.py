#Colour detection for a webcam
import cv2 as cv
import numpy as np
from stack_images import stackImages

height = 640
width = 360

cam = cv.VideoCapture(-1)
cam.set(cv.CAP_PROP_FRAME_WIDTH, width)
cam.set(cv.CAP_PROP_FRAME_HEIGHT, height)

def empty(a):
    pass

cv.namedWindow("TrackBars")
cv.resizeWindow("TrackBars", width, height)
cv.createTrackbar("Hue Min", "TrackBars", 29, 179, empty)
cv.createTrackbar("Hue Max", "TrackBars", 179, 179, empty)

cv.createTrackbar("Sat Min", "TrackBars", 39, 255, empty)
cv.createTrackbar("Sat Max", "TrackBars", 255, 255, empty)

cv.createTrackbar("Val Min", "TrackBars", 43, 255, empty)
cv.createTrackbar("Val Max", "TrackBars", 255, 255, empty)


while (cv.waitKey(1) != ord('q')):
    success, img = cam.read()
    imgHSV = cv.cvtColor(img, cv.COLOR_BGR2HSV)

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
    imgStack = stackImages(1, ([img, imgHSV, imgRes]))
    cv.imshow("Video", imgStack)
