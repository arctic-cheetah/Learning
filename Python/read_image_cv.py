import cv2 as cv

img = cv.imread("/mnt/c/Users/dudbo/Pictures/OpenCV/train/cat.0.jpg")
#img = cv.imread("C:\\Users\\dudbo\\Pictures\\OpenCV\\train\\cat.0.jpg")
cv.imshow("Output", img)
cv.waitKey(0)