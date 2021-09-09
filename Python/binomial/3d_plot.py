#A python program to visualise a probability

import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

data_path = "./binom_data.csv"

def main():
    data = pd.read_csv(data_path)
    x = data["number_of_rounds"]
    y = data["probability_of_a_match"]
    z = data["probability_of_win"]
    fig = plt.figure()
    ax = fig.add_subplot(projection="3d")
    ax.scatter(x, y, z)
    plt.show()

if __name__ == "__main__":
    main()