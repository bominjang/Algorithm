def solve(stair, n):
    scores = []
    scores.append(stair[0])
    for i in range(1,3):
        if i==1:
            scores.append(max(scores[i-1]+stair[i], stair[i]))
            continue
        else:
            scores.append(max(scores[i-2]+stair[i], stair[i-1]+stair[i]))

    for i in range(3,n):
        scores.append(max(stair[i]+stair[i-1]+scores[i-3], stair[i]+scores[i-2]))
    print(scores[-1])

stair = []
n = int(input().strip())
for i in range(n):
    stair.append(int(input().strip()))
solve(stair, n)
