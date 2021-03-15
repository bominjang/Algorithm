data = []
cnt = 0
def solve(n, Open, Close, ok):
    global cnt

    if(Open==n and Close==n):
        data.append(ok)
        cnt += 1
        return
    if Open < n :
        solve(n, Open+1, Close, ok+'(')
    if Open>Close:
        solve(n, Open, Close+1, ok+')')


#-------main--------
n = int(input())
solve(n, 0, 0, '')
print(cnt)
