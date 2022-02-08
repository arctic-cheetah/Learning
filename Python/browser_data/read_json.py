import json

f = open("browser_data2.json", "r")

obj = json.load(f)
fetch_url = obj[0]["tabs"]
url_found = []
for x in fetch_url:
    print(x["url"])
    if (x["url"]):
        url_found.append(x["url"])

# print(url_found)


