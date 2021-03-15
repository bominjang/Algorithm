def solve(n):
    ways = [0]*(n)
    ways[0] = 1
    ways[1] = 2

    if(n<2):
        return ways[1]
    for i in range(2, n):
        ways[i] = ways[i-2]+ways[i-1]

    print("계단 오르는 방법의 수 : %d" % ways[-1])

n = int(input("계단의 수를 입력하시오 : "))
solve(n)
