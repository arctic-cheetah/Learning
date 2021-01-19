#A program used to practice geopandas on Australian cities
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import geopandas as gpd



def main():
    data_dir = "./data/au-cities.csv"
    read_data = pd.read_csv(data_dir)
    #convert latitude and longitudes to geoDataFrame
    #au_places = gpd.GeoDataFrame(read_data, geometry = gpd.points_from_xy(read_data["lng"], read_data["lat"]))
    #print(au_places.head())

    lng = read_data["lng"]
    lat = read_data["lat"]
    population = read_data["population"]

    print("Plotting now...")
    #Plot the places on a map
    au_map = gpd.read_file("/home/london/Data/Australia_map_shapefile/SLA11aAust.shp")
    au_map.plot(color = "white", edgecolor = "black")
    plt.scatter(lng, lat, alpha = 0.5, cmap = "jet", c = np.log10(population))
    plt.colorbar(label = "log$_{10}$(Population)")
    plt.grid(True, axis = "both")
    plt.xlabel("Longitude")
    plt.ylabel("Latitude")
    plt.title("Australian population")
    plt.show()

if (__name__ == "__main__"):
    main()