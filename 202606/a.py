def qwe(data,left,right):
    midd = data[left]
    while left <right:
        while data[right] >= midd and left < right:
            right -=1   
        data[left] = data[right]
        # print(f"{data} =====right")
        while data[left] <= midd and left < right:
            left += 1
        data[right] = data[left]
        # print(f"{data} =====left")
    data[left] = midd
    return left
i = 0

def quer(data,left,right):
    if left < right:
        mid = qwe(data,left,right)
        print(f"第{i}次{data}")
        quer(data,left,mid-1)
        quer(data,mid+1,right)
       


li = [4,6,2,8,23,8,345,876,22,2,3,1]
print(li)
quer(li,0,len(li)-1)
print(li)