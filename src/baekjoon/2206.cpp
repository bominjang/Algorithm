#include<iostream>
#include <queue>
#include <stdio.h>
#define MAX 1000
using namespace std;

typedef struct {
    int y, x;
} Dir;

Dir moveDir[4] = {{1,  0},
                  {0,  1},
                  {-1, 0},
                  {0,  -1}};//상,후,하,좌

int N, M;
char map[MAX + 1][MAX + 1];
int visited[MAX + 1][MAX + 1][2]; //y,x,뚫을 수 있는 횟수
//[0][0][0]은 사용하지 X

bool isValid(int ny, int nx) {
    return (ny >= 1 && ny <= N && nx >= 1 && nx <= M);
}

int bfs() {
    queue<pair<pair<int, int>, int>> q;
    q.push({{1, 1}, 1});//y,x, 뚫을 수 있는 횟수
    visited[1][1][1] = 1;//방문했다.

    while (!q.empty()) {
        int y = q.front().first.first; //y좌표
        int x = q.front().first.second; //x좌표
        int block = q.front().second; //뚫을 수 있는 횟수
        q.pop();

        if (y == N && x == M) {
            return visited[y][x][block];
        }
        for (int i = 0; i < 4; i++) {
            int ny = y + moveDir[i].y;
            int nx = x + moveDir[i].x;
            if (isValid(ny, nx)) {
                if (map[ny][nx] == '1' && block) { //갈 수 없는 길이고, 벽을 아직 안뚫었을 때
                    visited[ny][nx][block - 1] = visited[y][x][block] + 1;//경로+1
                    q.push({{ny, nx}, block - 1}); //뚫었으므로 block-1으로 횟수를 감소시켜야 함.
                }
                //갈 수 있는 길이고, 방문하지 않았다면
                if (map[ny][nx] == '0' && visited[ny][nx][block] == 0) {
                    visited[ny][nx][block] = visited[y][x][block] + 1;
                    q.push({{ny, nx}, block});
                }
            }

        }

    }
    //목적지에 노착하지 못하고 탐색이 종료되었을 때.
    return -1;

}

int main() {
    scanf("%d %d", &N, &M);
    for (int i = 1; i <= N; i++) {
        scanf("%s", &map[i][1]);
    }

    printf("%d\n", bfs());

    return 0;
}
