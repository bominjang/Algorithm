#include <queue>
using namespace std;
// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
priority_queue<int> pq;//영역의 넓이 저장
int area;//영역의 넓이
//x, y의 direction
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int M, N;//m,n을 저장할 전역변수
//visit를 주소로 받는 것이 포인트!!
void dfs(int y, int x, int k, vector<vector<int>> &visit, vector<vector<int>> picture){
	//방문 표시를 해주고
    visit[y][x] = 1;
	//영역 증가시켜주기
    area++;
	//for문 돌면서 상,하,좌,우 탐색
    for(int i=0;i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        //영역 검사
        if(ny>=M || ny<0||nx>=N || nx<0) continue;
		//해당 좌표의 값이 k와 같으면서 방문하지 않은 곳이면
        if(picture[ny][nx]==k && visit[ny][nx]==0){
			//방문하기
            dfs(ny, nx, k, visit, picture);
        }
    }
    
}
//전역 변수인 Priority queue를 초기화하는 함수. pq자체를 초기화 해야하므로 주소를 받아야 함.
void pq_clear(priority_queue<int>& pq)
{
	priority_queue<int> reset;
	swap(pq, reset);
}
vector<int> solution(int m, int n, vector<vector<int>> picture) {
	//전역변수 초기화
    area = 0;
    M = m;
    N = n;
    pq_clear(pq);
    //방문한 것을 기록할 2차원 벡터 선언. 벡터는 선언하면 기본으로 0으로 초기화됨.
    vector<vector<int>> visit(M, vector<int>(N));
    
	//picture전체를 돌면서, 0이 아니면서 방문하지 않은 곳을에 대해 dfs 호출
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            if(picture[i][j]!=0 && visit[i][j]!=1){
                int k = picture[i][j];
                dfs(i, j, k, visit, picture);
                pq.push(area);//영역의 넓이를 뜻하는 area 변수를 priority queue에 넣기
                area=0;//또 다른 영역을 탐색해야 하므로, 영역 넓이 0으로 초기화
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = pq.size();//영역의 개수
    answer[1] = pq.top();//가장 큰 영역의 넓이를 구해야 하므로
    return answer;
}
