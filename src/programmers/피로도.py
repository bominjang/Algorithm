def dfs(tired, dungeons, cnt):
    global ans
    for i in range(len(dungeons)):
        if check[i]!=1 and tired>=dungeons[i][0]:
            check[i] = 1
            dfs(tired-dungeons[i][1], dungeons, cnt+1)
            check[i] = 0
        ans = max(ans, cnt)

def solution(k, dungeons):
    global ans, check
    ans=0
    check = [0 for _ in range(len(dungeons))]
    
    dfs(k, dungeons, 0)
    return ans
