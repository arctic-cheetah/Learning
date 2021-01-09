import pandas as pd
import matplotlib.pyplot as plt

data_dir = "data/data.csv"
df = pd.read_csv(data_dir)

mean = float(df["Calories"].mean())
median = float( df["Calories"].median())
mode = float(df["Calories"].mode())

print(mean, median, mode)
print(df.corr())
#df.plot(kind = "hist", x = "Pulse", y = "Maxpulse")
myPlot = df["Duration"].plot(kind = "hist")
myPlot.set_xlabel("Duration")
plt.show()
