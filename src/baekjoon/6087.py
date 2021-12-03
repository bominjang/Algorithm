from collections import deque

def bfs(x, y):
    queue = deque([(x,y)])
    visited[x][y] = 0 #방문 표시
    while queue:
        x, y = queue.popleft()
        for i in range(4):
            #동 남 서 북 순서.
            nx, ny = x+dx[i],y+dy[i]
            while True:
                #범위를 벗어난다
                if not(0<=nx<n and 0<=ny<m): break
                #벽을 만난다
                if board[nx][ny] =='*' : break
                #지난 적 있는 곳인데 지금 경로로는 너무 많은 거울이 필요
                if visited[nx][ny]<visited[x][y]+1 : break
                #board 업데이트, queue 추가
                queue.append((nx,ny))
                visited[nx][ny] = visited[x][y]+1
                #한 방향으로 계속 가기
                nx = nx+dx[i]
                ny = ny+dy[i]


m,n = map(int, input().split()) #열, 행
board = [input() for _ in range(n)] # 행만큼 반복해서 한줄씩 넣기

# 동 남 서 북/ x가 행을 움직임
dx = (0,1, 0, -1)
dy = (1, 0, -1, 0)

# 레이저의 위치
C = []
for i in range(n):#행
    for j in range(m):#열
        if board[i][j]=='C':
            C.append((i,j))

#sx, sy : 시작지점
#ex,ey : 도착지점

(sx,sy), (ex,ey) = C

visited = [[float('inf')]*m for _ in range(n)]
bfs(sx, sy)

print(visited[ex][ey]-1)
