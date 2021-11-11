#include <vector>
#include <queue>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

priority_queue<int> pq;//영역의 넓이들을 저장
int area;//영역의 넓이

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int M, N;

void dfs(int y, int x, int k, vector<vector<int>> &visit, vector<vector<int>> picture){
    visit[y][x] = 1;
    area++;
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if(ny>=M || ny<0||nx>=N || nx<0) continue;
        if(picture[ny][nx]==k && visit[ny][nx]==0){
            dfs(ny, nx, k, visit, picture);
        }
    }
    
}

void pq_clear(priority_queue<int>& pq)
{
	priority_queue<int> reset;
	swap(pq, reset);
}

vector<int> solution(int m, int n, vector<vector<int>> picture) {
    area = 0;
    M = m;
    N = n;
    pq_clear(pq);
    
    vector<vector<int>> visit(M, vector<int>(N));
    
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(picture[i][j]!=0 && visit[i][j]!=1){
                int k = picture[i][j];
                dfs(i, j, k, visit, picture);
                pq.push(area);
                area=0;//영역 넓이 초기화
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = pq.size();
    answer[1] = pq.top();
    return answer;
}
