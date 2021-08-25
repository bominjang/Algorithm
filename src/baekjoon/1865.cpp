#include <iostream>
#include <vector>
#define MAX 505
#define INF 987654321
#define START 1
using namespace std;

int TC;
int N, M, W;
int S, E, T;
string answer;
vector<pair<int, int>> adj[MAX];

void initialize() {
    for (int i = 1; i <= N; ++i) adj[i].clear();
}

void Solution()
{
  //upper 사이즈 N으로 지정했다가 메모리초과남........ -_-
    vector<int> upper(N+1, INF);
    upper[START] = 0;

    //음수 사이클의 존재 여부. V번의 완화를 성공한다면
    for(int iter = 0; iter<N; iter++){
        for(int here=1; here<=N; here++){
            for(auto it : adj[here]){
                int there = it.first;
                int cost = it.second;

                //V번의 완화가 성공한다면 here는 음수 사이클에 들어있음.
                if(upper[here]+cost < upper[there]){
                    upper[there] = upper[here]+cost;
                    //이 음수사이클을 포함하는 경로가 있는가?
                    if(iter == N-1){
                        answer= "YES";
                        return;
                    }
                }
            }
        }
    }
    answer = "NO";
    return;
}

void input(){
    cin >> N >> M >> W;
    initialize();
    for(int j=0; j<M; j++){
        cin >> S >> E >> T;
        adj[S].push_back(make_pair(E, T));
        adj[E].push_back(make_pair(S, T));
    }
    for(int k=0; k<W; k++){
        cin >> S >> E >> T;
        adj[S].push_back(make_pair(E, (-1)*T));//웜홀
    }
}

void Solve(){
    cin >> TC;
    while(TC--){
        input();
        Solution();
        cout << answer << "\n";
    }
}

int main() {
    Solve();

    return 0;
}
