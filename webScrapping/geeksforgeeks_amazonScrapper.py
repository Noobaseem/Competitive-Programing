import bs4
import requests
import re

page = requests.get('http://www.geeksforgeeks.org/tag/amazon/')
soup = bs4.BeautifulSoup(page.content)

y = "amazon-in"
urlList = []

for link in soup.find_all('a'):
    if re.search("amazon-inter" , str(link.get('href'))):
        urlList.append(str(link.get('href')))

for url in list(set(urlList)):
    if not re.search("respon" , url):
        print(url)
        page = requests.get(url)
        soup = bs4.BeautifulSoup(page.content)
        for link in soup.find_all('p'):
            print ''.join(link.findAll(text=True))

