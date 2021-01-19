import numpy as np
import geopandas as gpd
import matplotlib.pyplot as plt

#import ESRI shapefile
districts = gpd.read_file("./Introduction to GeoPandas/Shapefiles/districts.shp")
#print(districts)

#Plot the graphs side by side
area_of_interest = gpd.read_file("./Introduction to GeoPandas/Shapefiles/area_of_interest.shp")
atms = gpd.read_file("./Introduction to GeoPandas/Shapefiles/atms.shp")
#fig, (ax1, ax2) = plt.subplots(ncols = 2)
#districts.plot(ax = ax1, edgecolor = "black", cmap = "viridis", column = "district")
#area_of_interest.plot(ax = ax2)

#Reprojecting the map
districts = districts.to_crs(epsg = 32629)
area_of_interest = area_of_interest.to_crs(epsg = 32629)
atms = atms.to_crs(epsg = 32629)

#Plot the graphs on top of each other
fig, ax = plt.subplots()
districts.plot(ax = ax, edgecolor = "black", cmap = "viridis", column = "district")
area_of_interest.plot(ax = ax, color = "none", edgecolor = "black")
atms.plot(ax = ax, markersize = 10, color = "red")

#Check the crs used
#print((districts.crs, area_of_interest.crs, atms.crs))

#Intersecting layers
districts_in_aoi = gpd.overlay(districts, area_of_interest, how = "intersection")
districts_in_aoi.plot(edgecolor = "black")

#districts_in_aoi["area"] = districts_in_aoi.area

districts_in_aoi.to_csv("Testing.csv")
plt.show()