import time
wood = time.time()

print(wood)


with open("wa.txt","w",encoding="utf-8") as f:
    f.write("hello world")