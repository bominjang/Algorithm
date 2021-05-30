#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int arr[25][25];
int visit[25][25];

int dy[4] = {-1,1,0,0}; // 상하좌우
int dx[4] = { 0,0,-1,1 };

vector <int> v;
queue <pair<int, int>> q;

void bfs(int iy, int ix, int N) {
	int count = 0;

	count += 1;
	q.push({ iy,ix });

	while (!q.empty()) {

		int idy = q.front().first;
		int idx = q.front().second;
		visit[idy][idx] = 1;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int ty = idy + dy[k];
			int tx = idx + dx[k];
			if (ty < N && ty >= 0 && tx < N && tx >= 0
				&& arr[ty][tx] == 1 && visit[ty][tx] == 0) {

				q.push({ ty, tx });
				visit[ty][tx] = 1;
				count += 1;
			}
		}
	}
	v.push_back(count);
	count = 0;
}

int main() {
	int N;
	int count = 0;
	int iy, ix;
	int ty, tx;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	for (int row = 0; row < N; row++) {
		for (int col = 0; col < N; col++) {
			if (arr[row][col] == 1 && visit[row][col] == 0) {			
				bfs(row, col, N);
			}
		}
	}

	sort(v.begin(), v.end());	
	printf("%d\n", v.size());

	for (int i = 0; i < v.size(); i++) {
		printf("%d\n", v[i]);
	}

}
