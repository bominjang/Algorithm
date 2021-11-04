#include<iostream>
#include <queue>
#include<algorithm>
#include <vector>
#include <cstring>

#define endl "\n"
#define MAX 50
using namespace std;

int dx[8] = {0,0,-1,1, -1, 1, -1, 1};
int dy[8] = {-1,1,0,0,-1, -1, 1, 1};

int N, M, answer;
bool visit[MAX][MAX];//갔는지 체크
int map[MAX][MAX];
vector<pair<int,int>> V;

int bfs(int a, int b){
    queue<pair<pair<int, int>, int>> q;
    q.push({{a,b},0});
    visit[a][b] = true;

    while(!q.empty()){
        int x = q.front().first.first;
        int y = q.front().first.second;
        int cnt = q.front().second;
        q.pop();

        if(map[x][y]==1) return cnt;
        for(int i=0;i<8;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx>=0 && ny>=0 && nx<N && ny<M){
                if(visit[nx][ny]== false){
                    visit[nx][ny]= true;
                    q.push({{nx,ny},cnt+1});
                }
            }
        }
    }
}

void Solution(){
    for(int i=0;i<V.size();i++){
        memset(visit,false, sizeof(visit));
        int x = V[i].first;
        int y = V[i].second;

        int temp = bfs(x,y);
        if(temp>answer) answer=temp;
    }
    cout<<answer<<endl;
}

void Input(){
    cin >> N >> M;
    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            cin>>map[i][j];
            if(map[i][j]==0){
                V.push_back({i,j});
            }
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
