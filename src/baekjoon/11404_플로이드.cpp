#include <vector>
#include <iostream>
#include <algorithm>

#define MAX_V 101
#define INF 987654321

using namespace std;

int n, m;
int adj[MAX_V][MAX_V];

void printCost() {
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++)
            adj[i][j]==INF ? cout << 0 << ' ' : cout << adj[i][j] << ' ';
        cout << '\n';
    }
}

void floyd() {
    // k : 경유 노드, i : 출발 노드, j : 도착 노드
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (adj[i][j] > adj[i][k] + adj[k][j]) {
                    adj[i][j] = adj[i][k] + adj[k][j];
                }
    printCost();
}

void getData() {
    int a, b, c;
    //배열을 초기화
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            adj[i][j] = i==j ? 0 : INF;
        }
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a][b] = min(adj[a][b], c);
    }
}

int main() {
    cin >> n >> m;
    getData();
    floyd();

    return 0;
}
