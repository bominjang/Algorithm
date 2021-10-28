from collections import deque


def solution(rectangle, characterX, characterY, itemX, itemY):
    answer = 0
    board = [[0] * 101 for i in range(101)]
    cX = 2 * characterX
    cY = 2 * characterY
    iX = 2 * itemX
    iY = 2 * itemY

    #모두 1로 처리해준다
    for x1, y1, x2, y2 in rectangle:
        for i in range(2 * x1, 2 * x2 + 1):
            for j in range(2 * y1, 2 * y2 + 1):
                board[i][j] = 1

    #그다음 내부를 0으로 바꿔준다.
    for x1, y1, x2, y2 in rectangle:
        for i in range(2 * x1 + 1, 2 * x2):
            for j in range(2 * y1 + 1, 2 * y2):
                board[i][j] = 0
#### 테두리 완성!####

    #BFS 시작
    visited = [[0] * 101 for i in range(101)]
    visited[cX][cY] = 1
    queue = deque([(cX, cY)]) #방문한 곳의 x, y쌍을 큐에 넣는다

    d = [[1, 0], [0, 1], [-1, 0], [0, -1]]

    while queue:
        x, y = queue.popleft()

        if (x, y) == (iX, iY):
            answer = (board[x][y] - 1) // 2 #board[cX][cY] = 1로 시작했기 때문. 시작한 곳의 거리는 빼줌
            break

        for i, j in d:
            nx = x + i
            ny = y + j

            if 0 <= nx < 101 and 0 <= ny < 101 and board[nx][ny] != 0 and visited[nx][ny] != 1:
                board[nx][ny] = board[x][y] + 1 #거리 누적
                visited[nx][ny] = 1
                queue.append((nx, ny))

    return answer


