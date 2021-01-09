import numpy as np

arr = np.array([1, 2, 3, 4, 5, 6, 7, 8])
myListEven = []

for x in np.nditer(arr):
    if (x & 1 == 0):
        myListEven.append(int(x))

print(myListEven)
