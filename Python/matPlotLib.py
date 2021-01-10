import matplotlib.pyplot as plt
import numpy as np

x1 = np.random.randint(100, size = (100))
y1 = np.random.randint(100, size = (100))

plt.scatter(x1, y1, s=x1, alpha = .5 ,c = y1 ,cmap = "nipy_spectral")
plt.colorbar()
plt.show()