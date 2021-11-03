#include<iostream>
#include<queue>
#include<algorithm>

#define endl "\n"
#define MAX 101
using namespace std;

long long N, M; //type조심!!
int map[MAX][MAX];
bool visit[MAX];
int answer= 21470000;
void dfs(long long x, int cnt){
    if(x>M){
        return;
    }
    if(x==M){
        answer = min(answer, cnt);
    }
    dfs(x*2, cnt+1);
    dfs(x*10+1, cnt+1);
}

void Solution(){
    dfs(N,1);
    if(answer==21470000){
        cout<<-1<<endl;
        return;
    }
    cout<< answer<<endl;
}

void Input(){
    cin >> N >> M;
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
