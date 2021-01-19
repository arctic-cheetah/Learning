#A program that uses a scatter plot and colouring to show the population
#of an Australian state
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

def main():
    data_au_dir = "./data/au-cities.csv"
    au_cities = pd.read_csv(data_au_dir)

    print("Enter an Australian state or territory: ", end = "")
    state = input()
    #Fetch data for the states
    start_row = 0
    end_row = 0
    first_time = True
    i = 0
    for x in au_cities["admin_name"]:
        if (x == state and first_time):
            end_row = i
            start_row = i
            first_time = False
        elif (x == state):
            end_row +=1
        i +=1

    print((start_row, end_row))
    au_cities = au_cities.iloc[start_row:end_row, :]

    latitude = au_cities["lat"]
    longitude = au_cities["lng"]
    population = au_cities["population"]

    plt.scatter(longitude, latitude, alpha = 0.5, label = "none", 
    c = np.log10(population), cmap = "viridis")

    plt.title("Population of " + state)
    plt.axis("equal")
    plt.xlabel("Longitude")
    plt.ylabel("Latitude")
    plt.colorbar(label = "log$_{10}$(Population)")

    plt.show()

if __name__ == "__main__":
    main()