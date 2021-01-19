#A program to practice choropleth maps
import pandas as pd
import matplotlib.pyplot as plt
import geopandas as gpd
import numpy as np
import geoplot as gp
import mapclassify

def main():
    data_dir = "./data/au-cities.csv"
    world = gpd.read_file(gpd.datasets.get_path("naturalearth_lowres"))
    cities = gpd.read_file(gpd.datasets.get_path("naturalearth_cities"))

    print(world.head())
    ax = gp.polyplot(world, projection = gp.crs.Orthographic())
    ax.outline_patch.set_visible(True)

    #Graphs a choropleth of gdp / population
    gdp_per_person = world["gdp_md_est"] / world["pop_est"]
    scheme = mapclassify.Quantiles(gdp_per_person, k = 5)
    gp.choropleth(world, hue = gdp_per_person, scheme = scheme, 
    cmap = "Greens")

    #Graphs population size by establishing area size 
    #to the African continent
    africa = world[world.continent == "Africa"] 
    ax = gp.cartogram(africa, scale = "pop_est", limits = (0.2, 1), 
    edgecolor = "black")
    gp.polyplot(africa, edgecolor = "black", ax = ax)

    plt.show()


if __name__ == "__main__":
    main()