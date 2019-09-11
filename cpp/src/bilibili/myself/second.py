from datetime import datetime

s = input()

a = s.split('-')

year = int(a[0].lstrip("0"))
month = int(a[1].lstrip("0"))
day=int(a[2].lstrip("0"))

da_1=datetime(year,month,day)-datetime(year,1,1)



print(da_1.days+1)