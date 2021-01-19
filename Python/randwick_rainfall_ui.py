#A program that grpahs the rainfall of Randwick 
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
#store the directory path
data_dir = "data/IDCJAC0001_066052_Data12.csv"

months = ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug"
          , "Sep", "Oct", "Nov", "Dec"]

YearIn = ""
Year = 0
while(not YearIn.isdigit() or (Year > 2020 or Year < 1888)):
    print("Enter a year between 1888-2020 to display:")
    YearIn = input()
    Year = int(YearIn)


#Read the file
rainfall = pd.read_csv(data_dir)

#remove null data
rainfall.dropna(inplace = True)

#Set the indexing column
rainfall_index = rainfall.set_index("Year", drop = False)

#Use annual data
rainfall_monthly = rainfall_index.loc[Year,months]
print(rainfall_monthly.describe())

plt.plot(months, rainfall_monthly, alpha = 0.5, c = "black")
plt.scatter(months, rainfall_monthly, c = rainfall_monthly, cmap = "YlGnBu")
plt.xlabel("Year")
plt.ylabel("Rainfall(mm)")
plt.colorbar()
plt.show()