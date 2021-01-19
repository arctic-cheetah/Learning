import matplotlib.pyplot as plt
import numpy as np

x = np.arange(0,4, 0.2)
y = x ** 2
z = x ** 3

i = 10

print(str(10))

fig, ax = plt.subplots()
ax.plot(x, y, color='b', linestyle = '--')
ax.plot(x, z, color='r', linestyle = ':')

# Add gridlines
ax.grid(linestyle='-', linewidth='0.5')

plt.show()