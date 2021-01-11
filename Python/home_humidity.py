import matplotlib.pyplot as plt
import numpy as np
import pandas as pd
from scipy.stats import iqr

#Store the directory name
data_dir = "./data/LOGGER11.csv"

#Open the data
home_data = pd.read_csv(data_dir)
############################################3

#Clean the data
#Remove any outlier via IQR
humid_sort = home_data["humidity"].copy()
humid_sort.sort_values(ascending = True, inplace = True)
IQR_HUMID = iqr(humid_sort)
Q1_HUMI = humid_sort.quantile(q = .25)
Q3_HUMI = humid_sort.quantile(q = .75)
UPPER_HUMI = Q3_HUMI + 1.5*IQR_HUMID
LOWER_HUMI = Q1_HUMI - 1.5*IQR_HUMID


for x in home_data.index:
    if home_data.loc[x, "humidity"] > UPPER_HUMI or home_data.loc[x, "humidity"] < LOWER_HUMI:
        home_data.drop(x, inplace = True)


#Set the x and y variables
humidity = home_data["humidity"]
time = home_data["time"]
print(home_data["humidity"].describe(percentiles = [.25, .5, .75]))

axs = plt.scatter(time, humidity, cmap = "plasma", alpha = 0.5, c = humidity)
plt.plot(time, humidity, c = "black", alpha = 0.5)
plt.ylim(0, 100)
plt.grid(b = True, which = "both")
plt.minorticks_on()
plt.colorbar()
plt.show()