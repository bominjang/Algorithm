def solution(num):
    number = 0 #방 안에서의 번호
    room = 0 #방의 번호 
    if(num%15==0):
        room = num/15
        number = 15
    else:
        room = num/15 +1
        number = num%15
    
    print(room + " " + number)
        
