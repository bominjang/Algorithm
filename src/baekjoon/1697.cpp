#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

queue<pair<int,int>> q;
bool visit[100001];
int N, K, result;

// 해당 위치가 유효한지 확인하는 함수
bool valid(int n) {
	if (n < 0 || n > 100000 || visit[n])
		return false;
	return true;
}

void bfs(int n) {
	while (!q.empty()) {
		// 큐에서 꺼내기
		int data = q.front().first;
		int depth = q.front().second;
		q.pop();
        // K와 같으면 바로 그 때의 depth를 담고 종료
		if (data == K) {
			result = depth;
			break;
		}
        // 갈 수 있는 3갈래의 좌표의 유효성을 판단하고 큐에 push
		if (valid(data - 1)){ 
			visit[data - 1] = true;
			q.push({ data - 1, depth + 1 });
		}
		if (valid(data + 1)) {
			visit[data + 1] = true;
			q.push({ data + 1, depth + 1 });
		}
		if (valid(data * 2)) {
			visit[data * 2] = true;
			q.push({ data * 2, depth + 1 });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> N >> K;
	q.push({ N, 0 });
	visit[N] = true;
	bfs(N);
    
	cout << result;
	return 0;
}
