import cv2 as cv
import numpy as np
from stack_images import stackImages

#Dimensions
height = 360
width = 640

cap = cv.VideoCapture(-1)
cap.set(cv.CAP_PROP_FRAME_WIDTH, width)
cap.set(cv.CAP_PROP_FRAME_HEIGHT, height)
cap.set(cv.CAP_PROP_BRIGHTNESS, 150)

def preProcessing(img):
    imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
    imgBlur = cv.GaussianBlur(imgGray, (5, 5), 1)
    imgCanny = cv.Canny(imgBlur, 200, 200)
    kernel = np.ones((5,5))
    imgDil = cv.dilate(imgCanny, kernel, iterations = 2)
    imgThres = cv.erode(imgDil, kernel, iterations = 1)

    return imgThres


def getContours(img):
    contours, hierarchy = cv.findContours(img, cv.RETR_EXTERNAL, 
                                              cv.CHAIN_APPROX_NONE)
    biggest = np.array([])
    maxArea = 0
    for cnt in contours:
        area = cv.contourArea(cnt)
        if (area > 5000):
            #cv.drawContours(imgContour, cnt, -1, (0xff, 0, 0), 3)
            perimeter = cv.arcLength(cnt, closed = True)
            approx = cv.approxPolyDP(cnt, 0.02 * perimeter, closed = True)
            if ( (area > maxArea) and (len(approx) == 4) ):
                biggest = approx
                maxArea = area
            objCor = len(approx)
            x, y, w, h = cv.boundingRect(approx)
    cv.drawContours(imgContour, biggest, -1, (0, 0, 0xff), 10)
    return biggest


#Need to get the images in the correct order
#The angling of the image can cause the reordering to be incorrect
#Algorithm needs to be replaced!
def reorder(coords):
    orderedCoords = np.zeros((4, 1, 2), np.int32)
    coords = coords.reshape((4, 2))
    sum = coords.sum(axis=1)
    #print(sum)
    #Get (0,0) and (maxHeight and maxWidth)
    orderedCoords[0] = coords[np.argmin(sum)]
    orderedCoords[3] = coords[np.argmax(sum)]
    diff = np.diff(coords, axis = 1)
    #print(diff)
    #Check for greatest width
    orderedCoords[1] = coords[np.argmin(diff)]
    orderedCoords[2] = coords[np.argmax(diff)]
    print(orderedCoords)
    return orderedCoords
    

def getWarp(img, biggest):
    ordered = reorder(biggest)
    pts1 = np.float32(ordered)
    pts2 = np.float32([[0, 0], [width, 0], [0, height], [width, height]])
    matrix = cv.getPerspectiveTransform(pts1, pts2)
    imgOutput = cv.warpPerspective(img, matrix, (width, height))
    return imgOutput


while (cv.waitKey(1) != ord('q')):
    success, img = cap.read()
    img = cv.resize(img, (width, height))
    imgContour = img.copy()
    #Prepare the image for use
    imgThres = preProcessing(img)
    #Get the contours
    biggest = getContours(imgThres)
    #print(biggest.shape)
    print(biggest)
    if (len(biggest) != 0):
    #Get the warped image
        imgWarped = getWarp(img, biggest)
        cv.imshow("Warped", imgWarped)

    cv.imshow("Contour",imgContour)
    cv.imshow("Video", imgThres)