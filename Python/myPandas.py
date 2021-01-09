import pandas as pd

data_dir = "data/dirtydata.csv"

df = pd.read_csv(data_dir)
df.dropna(inplace = True)
df["Date"] = pd.to_datetime(df["Date"])
df.drop_duplicates(inplace = True)

for x in df.index:
    if df.loc[x, "Duration"] > 120:
        df.loc[x, "Duration"] = 120

df.to_csv("cleanData.csv", index = False)

