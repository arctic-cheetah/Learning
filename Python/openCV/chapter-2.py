#Modify colours of an image
import cv2 as cv
import numpy as np

img = cv.imread("/home/london/Pictures/OpenCV/train/cat.1.jpg")

kernel = np.ones((5,5), np.uint8)

imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)
imgBlur = cv.GaussianBlur(img, (7,7), 0) 
imgCanny = cv.Canny(img, 150, 200)
imgDilation = cv.dilate(img, kernel, iterations = 1)
imgEroded = cv.erode(img, kernel, iterations = 1)

cv.imshow("imgGray", imgGray)
cv.imshow("imgBlur", imgBlur)
cv.imshow("imgCanny", imgCanny)
cv.imshow("imgDilation", imgDilation)
cv.imshow("imgEroded", imgEroded)
#Exit only when q is pressed
while ( not ((cv.waitKey(1) & 0xFF) == ord('q'))):
    pass