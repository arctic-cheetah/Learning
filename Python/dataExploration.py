import pandas as pd

melbourne_dir = "./data/melb_data.csv"
melb_data = pd.read_csv(melbourne_dir)

print(melb_data.describe())