#A program that uses a scatter plot and colouring to show the population
#of Australia
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def main():
    data_au_dir = "./data/au-cities.csv"
    au_cities = pd.read_csv(data_au_dir)
    latitude = au_cities["lat"]
    longitude = au_cities["lng"]
    population = au_cities["population"]

    plt.scatter(longitude, latitude, alpha = 0.5, label = "none", 
    c = np.log10(population), cmap = "viridis")

    plt.axis("equal")
    plt.xlabel("Longitude")
    plt.ylabel("Latitude")
    plt.colorbar(label = "log$_{10}$(Population)")

    plt.show()

if __name__ == "__main__":
    main()