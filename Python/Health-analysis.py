#An analysis of the probability of cancer world wide
#By graphing a world map in 2016
import numpy as np
import matplotlib.pyplot as plt
import pandas as pd
import geopandas as gpd
import urllib.request

def main():
    #directory for data here
    data_dir = "/home/london/Data/WHO-health/30-70cancerChdEtc.csv"
    country_to_coord = "./data/countries.csv"
    world = gpd.read_file(gpd.datasets.get_path("naturalearth_lowres"))

    nations = pd.read_csv(country_to_coord)
    df = pd.read_csv(data_dir)

    #Get the probability of cancer for both sexes in 2016
    i = 0
    num_elements = 0
    #Fetch the number of rows
    df_len = df["Location"].count()
    df_nation = []
    while i < df_len:
        x = df.iloc[i]
        if (x["Period"] == 2016 and x["Dim1"] == "Both sexes"):
            df_nation.append(x)
            num_elements +=1
        i +=1

    df_nation = pd.DataFrame(df_nation)
    #Add the coordinates of a nation to the data frame
    i = 0
    df_len = df_nation["Location"].count()
    df_nation_len = nations["name"].count()
    nation_coord = []
    excluded_nations = []
    #Interestingly there are nations missing from Google's csv data
    #Because of different names for the same nation!
    #More reason to use ISO standards
    while (i < df_len):
        j = 0
        x = df_nation.iloc[i]
        hasFound = False
        while (j < df_nation_len and hasFound == False):
            y = nations.iloc[j]
            if (x["Location"] == y["name"]):
                nation_coord.append((y["longitude"], y["latitude"]))
                hasFound = True
            j +=1
        i +=1

    nation_coord = pd.DataFrame(nation_coord)
    nation_coord.columns = ["lng", "lat"]

    #Chart the world map
    fig, ax = plt.subplots()
    plt.scatter(nation_coord["lng"], nation_coord["lat"], c = df_nation["First Tooltip"], cmap = "rainbow", marker = "o", s = 3 * df_nation["First Tooltip"])
    world.plot(ax = ax, color = "none", edgecolor = "black")
    plt.xlabel("Longitude")
    plt.ylabel("Latitude")
    plt.title("Global probability of cancer")
    plt.colorbar(label = "Probability of cancer (%)")
    #Add the nations in long, lat and the radius of the marker as the probability
    #of cancer
    plt.show()


    


if (__name__ == "__main__"):
    main()
