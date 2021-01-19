#A program to view shapefiles
import geopandas as gpd
import matplotlib.pyplot as plt
import numpy as np
import pandas as pd


def main():
    print("Enter full pathname to open the file: ", end="")
    data_dir = input()

    gdf = gpd.read_file(data_dir)
    gdf.plot(edgecolor = "black", alpha = 0.5, cmap = "viridis")
    plt.show()
    


if __name__ == "__main__":
    main()