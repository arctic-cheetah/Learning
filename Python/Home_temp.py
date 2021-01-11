import matplotlib.pyplot as plt
import matplotlib.axes as pltax
import numpy as np
import pandas as pd
from scipy.stats import iqr

#Store the directory name
data_dir = "./data/LOGGER11.csv"

#Open the data
home_temp = pd.read_csv(data_dir)
############################################3

#Clean the data
#Remove any outlier via IQR
temp_sort = home_temp["temperature"].copy()
temp_sort.sort_values(ascending = True, inplace = True)
IQR_TEMP = iqr(temp_sort)
median_TEMP = temp_sort.median()
Q1_TEMP = temp_sort.quantile(q = 0.25)
Q3_TEMP = temp_sort.quantile(q = 0.75)
UPPER_TEMP = Q3_TEMP + 1.5*IQR_TEMP 
LOWER_TEMP = Q1_TEMP - 1.5*IQR_TEMP 



for x in home_temp.index:
    if home_temp.loc[x, "temperature"] > UPPER_TEMP or home_temp.loc[x, "temperature"] < LOWER_TEMP:
        home_temp.drop(x, inplace = True)


#Set the x and y variables
temp = home_temp["temperature"]
time = home_temp["time"]
print(home_temp["temperature"].describe(percentiles = [.25, .5, .75]))

axs = plt.scatter(time, temp, cmap = "plasma", alpha = 0.5, c = temp)
plt.plot(time, temp, c = "black", alpha = 0.5)
plt.ylim(0, 40)
plt.colorbar()
plt.grid(True)
plt.show()