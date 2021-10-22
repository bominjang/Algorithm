#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>
#define MAX 101
using namespace std;

int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visit[MAX][MAX]={false};
int cnt=0;
int N;

void DFS(int **matrix, int x, int y){
	visit[x][y]=true;
	cnt++;
	for(int i=0;i<4;i++){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(nx<0||ny<0||nx>=N||ny>=N) continue;
		if(matrix[nx][ny]==1 && !visit[nx][ny]){
			DFS(matrix, nx,ny);
		}
	}
}

void solution(int sizeOfMatrix, int **matrix) {
  // TODO: 이곳에 코드를 작성하세요.
	N = sizeOfMatrix;
	vector<int> vec;
	int i, j;
	for(i=0;i<sizeOfMatrix;i++){
		for(j=0;j<sizeOfMatrix;j++){
			if(matrix[i][j]==1 && !visit[i][j]){
				cnt=0;
				DFS(matrix, i,j);
				vec.push_back(cnt);
			}
		}
	}
	sort(vec.begin(), vec.end());
	cout << vec.size() << "\n";
	for(i=0;i<vec.size();i++) cout << vec[i] << " ";
}
