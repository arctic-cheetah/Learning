#A program that sorts Australian cities by states in alphabetical order
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def main():
    data_au_dir = "./data/au-cities.csv"
    au_cities = pd.read_csv(data_au_dir)
    order_by_state = au_cities.copy()
    order_by_state.sort_values(by = "admin_name",
    ascending = True, inplace = True)

    order_by_state.to_csv(data_au_dir, index = False)
    
    print(order_by_state)

if __name__ == "__main__":
    main()