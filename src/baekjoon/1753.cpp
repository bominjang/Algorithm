#include <iostream>
#include <queue>
#include <vector>
#define endl "\n"
#define MAX 20010
#define INF 987654321
using namespace std;

int V, E, start;
int dist[MAX];
vector<pair<int, int>> Vertex[MAX];

void input(){
    cin >> V >> E >> start;
    for(int i=0; i<E; i++){
        int u, v, w;
        cin >> u >> v >> w;
        Vertex[u].push_back(make_pair(v,w));
    }
    for(int i=1; i<=V; i++) dist[i] = INF; //정점은 일단 Inf로 초기화
}

void Solution()
{
    priority_queue<pair<int, int>> PQ;
    PQ.push(make_pair(0, start));
    dist[start] = 0;

    while(!PQ.empty()){
        int cost = -PQ.top().first;
        int here = PQ.top().second;
        PQ.pop();

        //지금 꺼낸 것보다 더 짧은 경로를 알고있다면 지금 꺼낸 것을 무시.
        if(dist[here]< cost) continue;

        //인접한 정점들 모두 검사
        for(int i=0; i < Vertex[here].size(); i++){
            int there = Vertex[here][i].first;
            int nextDist = cost + Vertex[here][i].second;

            if(dist[there] > nextDist){
                dist[there] = nextDist;//갱신
                PQ.push(make_pair(-nextDist, there));// 큐에 넣음
            }
        }
    }

    for(int i=1; i<=V; i++){
        if(dist[i] == INF) cout << "INF" << endl;
        else cout << dist[i] << endl;
    }
}

void Solve(){
    input();
    Solution();
}

int main() {
    Solve();

    return 0;
}
