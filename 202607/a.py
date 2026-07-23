import time
wood = time.time()
import requests
print(wood)


url = "https://www.baidu.com"

heardrs = {
    
"user-agent":"Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/148.0.0.0 Safari/537.36"
}

re=requests.get(url,headers=heardrs)
with open("wa.html","w",encoding="utf8") as f:
    f.write(re.text)
