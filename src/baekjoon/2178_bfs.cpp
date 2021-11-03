#include<iostream>
#include<queue>
#include<cstring>

#define endl "\n"
#define MAX 101
using namespace std;

int N, M;
int map[MAX][MAX];
int path[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
queue<pair<int,int>> q;

void bfs(int y, int x){
    path[y][x] = 1;
    visit[y][x] = true;
    q.push({y,x});

    while(!q.empty()){
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0||nx>=M||ny<0||ny>=N) continue;
            if(map[ny][nx]==1 && visit[ny][nx]==false){
                visit[ny][nx] = true;
                q.push({ny, nx});
                path[ny][nx] = path[y][x]+1;
            }
        }
    }
}

void Solution(){
    //방향 선택. 중복순열 구하기
    memset(visit, false, sizeof(visit));
    bfs(0,0);
    cout<< path[N-1][M-1]<<endl;
}

void Input(){
    cin >> N >> M;
    string input;
    for(int i=0;i<N;i++){
        cin >> input;
        for (int j = 0; j < M; j++) {
            map[i][j] = input[j] - '0';
        }
    }
}

void Solve(){
    Input();
    Solution();
}

int main(void){
    ios::sync_with_stdio(false);
    //freopen("input.txt", "r", stdin);
    Solve();
    return 0;
}
