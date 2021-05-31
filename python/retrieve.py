import bs4
import requests

response = requests.get("https://en.wikipedia.org/wiki/Mathematics")

if response is not None:
    html = bs4.BeautifulSoup(response.text, 'html.parser')

    paragraphs = html.find_all("p")
    m = paragraphs[2]

with open('sample.txt', 'w') as f:
    f.write(m.text)
