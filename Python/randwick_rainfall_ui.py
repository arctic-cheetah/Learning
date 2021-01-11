#A program that shows the rainfall of Randwick from 1888 to 2020
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
#store the directory path
data_dir = "data/IDCJAC0001_066052_Data12.csv"

months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug"
          , "Sep", "Oct", "Nov", "Dec"]

Year = ""
while (not Year.isdigit()):
    print("Enter a year to display:")
    Year = input()
Year = int(Year)

#Read the file
rainfall = pd.read_csv(data_dir)

#remove null data
rainfall.dropna(inplace = True)

#Set the indexing column
rainfall_index = rainfall.set_index("Year", drop = False)

#Use annual data
rainfall_monthly = rainfall_index.loc[Year,months]

print(rainfall_monthly)
"""
rainfall_monthly = []
for x in year:
    rainfall_monthly.append(x)
rainfall_monthly = np.array(rainfall_monthly)
"""
plt.plot(months, rainfall_monthly, alpha = 0.5, c = "black")
plt.scatter(months, rainfall_monthly, c = rainfall_monthly, cmap = "YlGnBu")
plt.xlabel("Year")
plt.ylabel("Rainfall(mm)")
plt.colorbar()
plt.show()