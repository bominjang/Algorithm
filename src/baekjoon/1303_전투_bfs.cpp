#include<iostream>
#include<queue>
#include<cstring>

#define endl "\n"
#define MAX 1001
using namespace std;

int N, M, W, B;
string map[MAX];
bool visit[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

int bfs(int i, int j , char c){
    int cnt=0;
    queue<pair<int,int>> q;
    q.push({i,j});
    visit[i][j]= true;

    while(!q.empty()){
        int x = q.front().first, y = q.front().second;
        q.pop();
        cnt++;

        int i;
        for(i=0;i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];

            if(nx<0 || nx>=M || ny<0 || ny>=N || visit[nx][ny]) continue;
            if(map[nx][ny]==c){
                visit[nx][ny] =true;
                q.push({nx,ny});
            }
        }
    }
    return cnt;
}

void Solution(){
    //방향 선택. 중복순열 구하기
    memset(visit, false, sizeof(visit));
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(!visit[i][j]){
                int cc=0;
                if(map[i][j]=='W'){
                    cc += bfs(i,j,'W');
                    W+=cc*cc;
                }else{
                    cc+=bfs(i,j,'B');
                    B+=cc*cc;
                }
            }
        }
    }
    cout<<W<<" "<<B;
}

void Input(){
    cin >> N >> M;
    for(int i=0;i<M;i++){
        cin >> map[i];
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
