import requests
import json



url = 'http://127.0.0.1:5000/stat'


response = requests.post(url)
print(response.text)
print(response.status_code)




