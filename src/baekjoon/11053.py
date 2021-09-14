x = int(input())

arr = list(map(int, input().split())) #input을 slice해서 list에 담기

dp = [1 for i in range(x)] # dp 배열 생성

for i in range(x):
    for j in range(i):
        if arr[i] > arr[j]:
            dp[i] = max(dp[i], dp[j]+1)

print(max(dp))
