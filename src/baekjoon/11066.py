def solve():
    # N : 챕터의 수, A : 파일 크기를 저장하는 배열
    N, A = int(input()), [0] + list(map(int, input().split()))
    # S[i]는 1번부터 i번까지의 누적합을 의미.
    S = [0 for _ in range(N + 1)]
    for i in range(1, N + 1):
        S[i] = S[i - 1] + A[i]

    # DP[i][j] : i에서 j까지 합하는데 필요한 최소 비용
    # DP[i][k] + DP[k+1][j] + sum(A[i]~A[j])
    DP = [[0 for i in range(N + 1)] for _ in range(N + 1)]

    for i in range(2, N + 1):  # 부분 파일의 길이. 2부터~
        for j in range(1, N + 2 - i):  # 시작점. 어디서부터~  k : 먼저 계산할 부분을 계산. 1,2,3이 있을 때 (1+2,3)이 나은지 (1,2+3)이 나은지.
            DP[j][j + i - 1] = min([DP[j][j + k] + DP[j + k + 1][j + i - 1] for k in range(i - 1)]) + (
                        S[j + i - 1] - S[j - 1])# S[j+i-1]-S[j-1] : i부터 j까지 누적합.

    print(DP[1][N])

# 테스트케이스만큼 반복
for _ in range(int(input())):
    solve()
