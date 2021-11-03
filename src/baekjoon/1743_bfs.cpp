#include<iostream>
#include<queue>
#include<cstring>

#define endl "\n"
#define MAX 101
using namespace std;

int N, M, K;
int map[MAX][MAX];
int path[MAX][MAX];
bool visit[MAX][MAX];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int bfs(int y, int x){
    int cnt =1;
    queue<pair<int, int>> q;
    q.push({y,x});
    visit[y][x] = true;

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i=0;i<4;i++){
            int ny = cy+dy[i];
            int nx = cx+dx[i];

            if(ny<1||ny>N||nx<1||nx>M) continue;
            if(map[ny][nx]==1 && visit[ny][nx]==false){
                visit[ny][nx] = true;
                cnt++;
                q.push({ny,nx});
            }
        }
    }
    return cnt;
}

void Solution(){
    memset(visit, false, sizeof(visit));
    bfs(0,0);
    //음식물이 있는 곳을 찾아 연결된 칸의 개수를 계산.
    int i, j,cc=0;
    for(i=1;i<=N;i++){
        for(j=1;j<=M;j++){
            if(map[i][j]==1 && visit[i][j]==false){
                int c = bfs(i,j);
                cc = max(cc, c); //큰 것을 cc로 갱신
            }
        }
    }
    cout<< cc <<endl;
}

void Input(){
    cin >> N >> M >> K;
    int a, b;
    for(int i=0;i<K;i++){
        cin >> a>>b;
        map[a][b] =1;
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
