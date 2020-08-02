import requests
from time import sleep


list1 = ["V12.6C0.5T28S100","V12.5C0.4T28S090","V12.4C0.3T28S080","V12.3C0.3T28S070","V12.2C0.3T28S060","V12.1C0.3T28S050","V12.0C0.3T28S040","V11.8C0.3T28S030","V11.6C0.3T28S020","V11.3C0.3T28S010","V10.5C0.3T28S000"]

for i in list1:
 url = "https://api.thingspeak.com/update?api_key=J2PRPGGYKTNWCU95&field1="
 url = url +str(i)
 print(url)

 r = requests.get (url)
 sleep(20)
