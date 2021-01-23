#Contours and shape detection
import cv2 as cv
import numpy as np
from stack_images import stackImages

#Functions here
def getContours(img):
    contours, hierarchy = cv.findContours(img, cv.RETR_EXTERNAL, 
                                              cv.CHAIN_APPROX_NONE)
    for cnt in contours:
        area = cv.contourArea(cnt)
        print(area)
        if (area > 40):
            cv.drawContours(imgContour, cnt, -1, (0xff, 0, 0), 2)
            perimeter = cv.arcLength(cnt, closed = True)
            print(perimeter)
            approx = cv.approxPolyDP(cnt, 0.02 * perimeter, closed = True)
            print(len(approx))
            objCor = len(approx)
            x, y, w, h = cv.boundingRect(approx)
            
            objectType = ""
            #Image processing
            if (objCor == 3):
                objectType = "Tri"
            elif (objCor == 4):
                aRatio = w/float(h)
                if (.95 < aRatio and aRatio < 1.05):
                    objectType = "Square"
                else:
                    objectType = "Rectangle"
            elif (objCor > 4):
                objectType = "Circle"
            else:
                objectType = "None"

            cv.rectangle(imgContour, (x, y), (w+x, h+y), (0, 0xff, 0), 2)
            cv.putText(imgContour, objectType, (x+(w//2)-10, y+(w//2)-10), 
            cv.FONT_HERSHEY_COMPLEX, 0.5, (0, 0, 0), 2)
            
            

path = "/home/london/Pictures/OpenCV/shapes.png"
img = cv.imread(path)

imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
imgBlur = cv.GaussianBlur(img, (7, 9), 1)
imgCanny = cv.Canny(imgBlur, 50, 50)
imgBlank = np.zeros_like(img)
imgContour = img.copy()

getContours(imgCanny)

imgStack = stackImages(0.8, ([img, imgGray, imgBlur], 
                             [imgCanny, imgContour, imgBlank]))
cv.imshow("Stacked images", imgStack)
#cv.imshow("Original", img)
#cv.imshow("Grayed Image", imgGray)
#cv.imshow("Blurred Image", imgBlur)


while (cv.waitKey(1) != ord('q')):
    pass