#Crop and resize images
import cv2 as cv
import numpy as np

img = cv.imread("/home/london/Pictures/OpenCV/train/cat.3.jpg")
print(img.shape)
#Width x height
imgResize = cv.resize(img, (1000, 828))

#Height(rows) x width(col) x
print(imgResize.shape)

#height x width
imgCropped = img[0:200, 0:200]

cv.imshow("Resized Image", imgResize)
cv.imshow("Cropped Image", imgCropped)
cv.imshow("Original", img)

while (not (cv.waitKey(1) & 0xFF) == ord('q')):
    pass