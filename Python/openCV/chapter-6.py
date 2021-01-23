#Joining images
import cv2 as cv
import numpy as np
from stack_images import stackImages

img = cv.imread("/home/london/Pictures/OpenCV/train/cat.1.jpg")
img2 = cv.imread("/home/london/Pictures/OpenCV/train/cat.2.jpg")

imgGray = cv.cvtColor(img, cv.COLOR_BGR2GRAY)

hor = np.hstack((img, img))
ver = np.vstack((img, img, img))

scaled = stackImages(0.5, ([img, img2]))

print(img.shape)
print(hor.shape)
print(ver.shape)

cv.imshow("Vertical", ver)
cv.imshow("Horizontal", hor)
cv.imshow("Original", img)
cv.imshow("Scaled", scaled)

while (not ((cv.waitKey(1) == ord('q')) )):
    pass