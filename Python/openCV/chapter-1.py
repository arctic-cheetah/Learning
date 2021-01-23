#Read images and videos
import cv2 as cv

img = cv.imread("/home/london/Pictures/OpenCV/train/cat.1.jpg")
cv.imshow("Output", img)
cv.waitKey(1000)

#Sometimes the external webcam is set to a negative number
cap = cv.VideoCapture(-1)
cap.set(3, 1080)
cap.set(4, 1920)
cap.set(cv.CAP_PROP_BRIGHTNESS, 1000)


while True:
    success, img = cap.read()
    cv.imshow("Video", img)
    if (cv.waitKey(1) & 0xFF == ord('q')):
        break