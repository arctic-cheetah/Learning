import matplotlib.pyplot as plt
import numpy as np
import pandas as pd

data_dir = "./accelerometer.csv"
acc = pd.read_csv(data_dir)

acc_x = acc["acc_x"]
acc_y = acc["acc_y"]
acc_z = acc["acc_z"]

x = np.asfarray([i for i in range(1, len(acc.index) + 1)])

fig, ax = plt.subplots(1)
ax.plot(x, acc_x, x, acc_y, x, acc_z, "-o")
#Set the axes
ax.set_xlabel("1 time step = 500ms")
ax.set_ylabel("Graviational Acceleration (m/s^2)")
ax.set_title("Gravitational acceleration of the MPU6050 sensor per unit time")
ax.grid(True)
plt.show()