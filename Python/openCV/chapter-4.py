#Shapes and texts
import cv2 as cv
import numpy as np

img = np.zeros((512, 512, 3), np.uint8)
#openCV uses BGR NOT RGB
img[:] = (255, 0, 0)
print(img)

cv.line(img, (0,0), (200, 200), (0, 0xff, 0))
cv.rectangle(img, (0,0), (300, 300), (0, 0, 0xff), 3)
cv.circle(img, (250, 250), 100, (100, 100, 100), 3)
cv.putText(img, "Hello world!", (100, 100), cv.QT_FONT_NORMAL, 1, (0, 0, 0xff), 1)

cv.imshow("Image", img)


while (not (cv.waitKey(1) & 0xFF) == ord('q')):
    pass