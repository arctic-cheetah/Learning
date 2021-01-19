#A program that graphs the number of covid cases for multiple nations
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import urllib.request 
import matplotlib.dates as mdates
import matplotlib.cbook as cbook
import random

#User functions
#Add a nation's data to the graph

def main():
    #Ask for update from user
    print("Update data set?\nY or N: ", end = "")
    isUpdate = input()
    data_dir = "./COVID-19-data/owid-covid-data.csv" 

    if (isUpdate.capitalize() == "Y"):
        covid_data_dir = "https://covid.ourworldindata.org/data/owid-covid-data.csv"
        print("Fetching latest COVID data")
        urllib.request.urlretrieve(covid_data_dir, data_dir)

    #Get data on the desired nation
    fig, ax = plt.subplots()
    
    covid_data = pd.read_csv(data_dir)
    mdates.set_epoch(covid_data["date"][0])
    nation = []
    #Ask for the number of nations to display
    print("Enter the number of nations to display: ", end = "")
    numNations = int(input())
    i = 0
    while(i < numNations):
        print("Enter a nation to display: ", end = "")
        nation.append(input()) 
        i +=1

    num_locations = covid_data["location"].count()
    for n in nation: 
        print(n)
        start_row = 0
        end_row = 0
        first_time = True
        i = 0
    #Fetch the selected nation's data
        while (i < num_locations): 
            x = covid_data.iloc[i]
            if (x["location"] == n and first_time):
                start_row = i
                end_row = i
                first_time = False
            elif (x["location"] == n):
                end_row +=1
            i +=1
        #Now works!
        nation_data = covid_data.iloc[start_row:end_row, :]
        total_cases = nation_data["total_cases"]
        date = nation_data["date"]
        colour = random.randrange(1, 0xFFFFFF)
        hex_string = "#{:02x}".format(colour)
        ax.plot(date, total_cases, color = hex_string, label = n)     


    ax.set_title("Covid cases")
    ax.set_xlabel("Date")
    ax.set_ylabel("Number of COVID cases")
    ax.legend()

    """
    debugging output
    print(nation_data)
    print(nation_data.describe())
    print(date)
    """

    #date formatting
    months = mdates.MonthLocator()
    years_fmt = mdates.DateFormatter("%Y-%m")

    ax.xaxis.set_major_locator(months)
    ax.xaxis.set_major_formatter(years_fmt)

    # format the coords message box
    ax.format_xdata = mdates.DateFormatter('%Y-%m-%d')
    ax.grid(True, axis = "both")
    # rotates and right aligns the x labels, and moves the bottom of the
    # axes up to make room for them
    fig.autofmt_xdate()
    plt.show()

if __name__ == "__main__":
    main()


