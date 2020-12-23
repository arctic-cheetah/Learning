import math
import sys


x = 4
y = 0
try:
    print(x / y)
except:
    for x in sys.exc_info():
        print(x)