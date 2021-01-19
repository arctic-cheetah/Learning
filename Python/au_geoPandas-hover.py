#A program used to practice geopandas on Australian cities
#and a bubble text over the points
import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
import geopandas as gpd

data_dir = "./data/au-cities.csv"
read_data = pd.read_csv(data_dir)
#convert latitude and longitudes to geoDataFrame
#au_places = gpd.GeoDataFrame(read_data, geometry = gpd.points_from_xy(read_data["lng"], read_data["lat"]))
#print(au_places.head())
city = read_data["city"]
lng = read_data["lng"]
lat = read_data["lat"]
population = read_data["population"]

print("Plotting now...")
#Plot the places on a map
fig, ax = plt.subplots()
au_map = gpd.read_file("/home/london/Data/Australia_map_shapefile/SLA11aAust.shp")
au_map.plot(ax = ax, color = "white", edgecolor = "black")

sc = plt.scatter(lng, lat, alpha = 0.5, cmap = "jet", c = np.log10(population))
plt.colorbar(label = "log$_{10}$(Population)")
plt.grid(True, axis = "both")
plt.xlabel("Longitude")
plt.ylabel("Latitude")
plt.title("Australian population")

annot = ax.annotate("", xy=(0,0), xytext=(20,20),textcoords="offset points",
                    bbox=dict(boxstyle="round", fc="w"),
                    arrowprops=dict(arrowstyle="->"))
annot.set_visible(False)

#Good effort on trying to to make a functional bubble text
#But due to the size of the dataframe, it is too slow
def update_annot(ind):
    pos = sc.get_offsets()[ind["ind"][0]]
    annot.xy = pos
    text = "{}".format("".join(city[n] for n in ind["ind"]))
    annot.set_text(text)
    annot.get_bbox_patch().set_alpha(0.4)

def hover(event):
    vis = annot.get_visible()
    if event.inaxes == ax:
        cont, ind = sc.contains(event)
        if cont:
            update_annot(ind)
            annot.set_visible(True)
            fig.canvas.draw_idle()
        else:
            if vis:
                annot.set_visible(False)
                fig.canvas.draw_idle()


fig.canvas.mpl_connect("motion_notify_event", hover)
plt.show()
