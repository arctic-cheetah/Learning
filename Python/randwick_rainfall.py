#A program that shows the rainfall of Randwick from 1888 to 20
import pandas as pd
import matplotlib.pyplot as plt
#store the directory path
data_dir = "data/IDCJAC0001_066052_Data12.csv"


#Read the file
rainfall = pd.read_csv(data_dir)

#remove null data
rainfall.dropna(inplace = True)

#Use annual data
rainfall_annual = rainfall["Annual"]
year = rainfall["Year"]

print(rainfall_annual.describe())

plt.plot(year, rainfall_annual, alpha = 0.5, c = "black")
plt.scatter(year, rainfall_annual, c = rainfall_annual, cmap = "YlGnBu")
plt.xlabel("Year")
plt.ylabel("Rainfall(mm)")
plt.ylim(0, 3000)
plt.colorbar()
plt.show()

