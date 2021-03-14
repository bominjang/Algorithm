def solution():
    num = intput()
    number = 0 #방 안에서의 번호
    room = 0 #방의 번호 
    if(num%15==0):
        room = num/15
        number = 15
    else:
        room = num/15 +1
        number = num%15
    
    print(room + " " + number)
        
#==============================================

# -*- coding: utf-8 -*-
# UTF-8 encoding when using korean
from pip._vendor.distlib.compat import raw_input

n = int(raw_input())
room_n = 1+n//15
in_n = n%15
if(in_n==0):
    room_n = n//15
    in_n = 15

print("%d %d" %(room_n, in_n))
