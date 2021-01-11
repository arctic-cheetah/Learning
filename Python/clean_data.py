import pandas as pd
import numpy as np

data_dir = "data/IDCJAC0001_066052_Data12.csv"

cols_del = ["Product code", "Station Number"]

df = pd.read_csv(data_dir)
df.drop(columns = cols_del, axis = 1, inplace = True)
df.to_csv("IDCJAC0001_066052_Data12.csv", index = False)
print("Data cleaned successfully!")