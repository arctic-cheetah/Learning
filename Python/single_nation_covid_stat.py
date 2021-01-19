#A program that graphs the count of covid cases for a single nation
import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
import urllib.request 
import matplotlib.dates as mdates
import matplotlib.cbook as cbook

#User functions

def main():
    #Ask for update from user
    print("Update data set?\nY or N: ", end = "")
    isUpdate = input()
    copy_to_dir = "./COVID-19-data/owid-covid-data.csv" 

    if (isUpdate == "Y"):
        covid_data_dir = "https://covid.ourworldindata.org/data/owid-covid-data.csv"
        print("Fetching latest COVID data")
        urllib.request.urlretrieve(covid_data_dir, copy_to_dir)

    #Get data on the desired nation
    covid_data = pd.read_csv(copy_to_dir)

    print("Enter a nation to display: ", end = "")
    nation = input()
    num_locations = covid_data["location"].count()
    i = 0
    start_row = 0
    end_row = 0
    first_time = True
    #Fetch the selected nation's data
    while (i < num_locations): 
        x = covid_data.iloc[i]
        if (x["location"] == nation and first_time):
            start_row = i
            end_row = i
            first_time = False
        elif (x["location"] == nation):
            end_row +=1
        i +=1
    #print("start_row: %d \n end_row: %d" %(start_row, end_row))
    nation_data = covid_data.iloc[start_row:end_row, :]

    total_cases = nation_data["total_cases"]
    date = nation_data["date"]

    fig, ax = plt.subplots()
    ax.plot(date, total_cases)
    ax.set_title("Covid cases " + nation)
    ax.set_xlabel("Date")
    ax.set_ylabel("Number of COVID cases")
    """
    ax.xlabel("Date")
    ax.ylabel("Cases")
    ax.set_title("Covid cases")
    
    debugging output
    print(nation_data)
    print(nation_data.describe())
    print(date)
    """

    #date formatting
    months = mdates.MonthLocator()
    years_fmt = mdates.DateFormatter("%Y-%m")

    mdates.set_epoch(date[start_row])
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


