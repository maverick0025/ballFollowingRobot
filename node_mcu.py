import requests
ip="http://"
while True:
    x=int(input("enter zero or one or two or three:"))
    if(x==0):
        requests.get(ip+'/forward')
    if(x==1):
        requests.get(ip+'/left')
    if(x==2):
        requests.get(ip+'/right')
    if(x==3):
        requests.get(ip+'/break')
