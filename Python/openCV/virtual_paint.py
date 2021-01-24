#A program that makes a virtual paint on a webcam
import cv2 as cv
import numpy as np

height = 640
width = 360

cam = cv.VideoCapture(-1)
cam.set(cv.CAP_PROP_FRAME_WIDTH, width)
cam.set(cv.CAP_PROP_FRAME_HEIGHT, height)

#Need to select colours properly
#R G B
myColours = [[129, 86, 0, 179, 0xff, 0xff]
             ,[72, 80, 0, 103, 0xff, 0xff]
             ,[110, 80, 0, 127, 0xff, 0xff]
             ]
#RGB
myColourValue = [[0, 0, 0xff],
                 [0, 0xff, 0],
                 [0xff, 0, 0]]

myPoints = [] #[x, y, colourID]

def findColour (img, myColours, myColourValue):
    imgHSV = cv.cvtColor(img, cv.COLOR_BGR2HSV)
    i = 0
    newCoords = []
    for c in myColours:
        lower = np.array(c[0:3])
        upper = np.array(c[3:6])
        mask = cv.inRange(imgHSV, lower, upper)
        #Get the outline of the object
        x, y = getContours(mask)
        cv.circle(imgRes, (x, y), 10, myColourValue[i], cv.FILLED)
        if (x != 0 and y != 0):
            newCoords.append([x, y, i])
        i +=1
        #cv.imshow(str(c[0]), mask)
    return newCoords

def getContours (img):
    x = y = w = h = 0
    contours, hierarchy = cv.findContours(img, cv.RETR_EXTERNAL, 
                                              cv.CHAIN_APPROX_NONE)
    for cnt in contours:
        area = cv.contourArea(cnt)
        if (area > 40):
            cv.drawContours(imgRes, cnt, -1, (0xff, 0, 0), 3)
            perimeter = cv.arcLength(cnt, closed = True)
            approx = cv.approxPolyDP(cnt, 0.02 * perimeter, closed = True)
            x, y, w, h = cv.boundingRect(approx)
    return (x, y)

def drawOnCanvas(myPoints, myColourValue):
    for coord in myPoints:
        cv.circle(imgRes, (coord[0], coord[1]), 10, myColourValue[coord[2]], cv.FILLED)

while (cv.waitKey(1) != ord('q')):
    success, img = cam.read()
    imgRes = img.copy()
    coords = findColour(img, myColours, myColourValue)
    if (len(coords) != 0):
        for p in coords:
            myPoints.append(p)
    if (len(myPoints) != 0):
        drawOnCanvas(myPoints, myColourValue)
    cv.imshow("Web cam", imgRes)