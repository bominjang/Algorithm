#include<iostream>
#include<queue>
#include<cstring>

#define endl "\n"
#define MAX 101
using namespace std;

int N, M;
int map[MAX][MAX];
bool visit[MAX];

int bfs(int x){
    int cnt =0;
    queue<int> q;
    q.push(x);
    visit[x] = true;

    while(!q.empty()){
        int cx = q.front();
        q.pop();

        for(int i=1;i<=N;i++){
            if(map[cx][i]==1 && visit[i]==false){
                visit[i] = true;
                q.push(i);
                cnt++;
            }
        }
    }
    return cnt;
}

void Solution(){
    memset(visit, false, sizeof(visit));

    //음식물이 있는 곳을 찾아 연결된 것의 개수를 탐색
    cout<< bfs(1) <<endl;
}

void Input(){
    cin >> N;
    cin >> M;
    int a, b;
    for(int i=0;i<M;i++){
        cin >> a>>b;
        map[a][b] = 1;
        map[b][a] = 1;
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
