#A program to read from the serial of an Arduino
import serial
import time
import csv

s = serial.Serial("/dev/ttyUSB1", 9600)

#flush the serial
s.setDTR(False)
time.sleep(1)
s.reset_input_buffer()
s.setDTR(True)

#open a file for writing data
f = open("accelerometer.csv", "a")

#Data format:
#acc_x, acc_y, acc_z
i = 0
while (i < 100):
    bytes = s.readline()
    decoded_bytes = bytes.decode(encoding="utf-8").strip("\n\r")
    print(decoded_bytes)
    decoded_bytes+="\n"
    f.write(decoded_bytes)
    time.sleep(.5)
    i +=1

f.close()


