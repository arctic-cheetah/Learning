#Warping perspectives
import cv2 as cv
import numpy as np

img = cv.imread("/home/london/Pictures/OpenCV/train/cat.1.jpg")
(width, height) = 278, 351
pts1 = np.float32([[100, 123], [50, 68], [46, 35], [252, 360]])
pts2 = np.float32([[0, 0], [width, 0], [0, height], [width, height]])
matrix = cv.getPerspectiveTransform(pts1, pts2)
imgOutput = cv.warpPerspective(img, matrix, (width, height))

cv.imshow("Original", img)
cv.imshow("Output", imgOutput)

while(not (cv.waitKey(1) & 0xff) == ord('q') ):
    pass