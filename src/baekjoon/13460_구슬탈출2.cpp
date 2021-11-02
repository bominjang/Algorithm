#include<iostream>

#define endl "\n"
#define MAX 10
using namespace std;

int N,M, Answer=987654321;
char MAP[MAX][MAX];

//상,하 / 우, 좌
int dx[] = {0,0,1,-1};
int dy[] = {1, -1, 0,0};

pair<int, int> Red, Blue;

int Inverse_Direction(int cur_Dir) {
    if(cur_Dir==0) return 1;
    else if(cur_Dir==1) return 0;
    else if(cur_Dir==2) return 3;
    else if (cur_Dir==3) return 2;
}

//움직인 거리를 return
int Move_dist(int x, int y, int xx, int yy) {
    return abs(x - xx) + abs(y - yy);
}


int Min(int A, int B) { if (A < B) return A; return B;}

void Move(int Rx, int Ry, int Bx, int By, int Cnt, int dir){
    if (Cnt>= Answer) return;
    if (Cnt>10) return;

    //Blue가 먼저 빠지면 함수 끝
    bool Red_flag = false;
    bool Blue_flag = false;

    //빨간 공 굴리기
    int nRx = Rx+dx[dir];
    int nRy = Ry+dy[dir];
    while(1)
    {
        //벽에 부딪히면 stop
        if (MAP[nRx][nRy]=='#') break;
        if(MAP[nRx][nRy]=='O') //구멍이면
        {//빠진다
            Red_flag = true;
            break;
        }
        //기울이면 한 방향으로 계속 이동하므로
        nRx = nRx+dx[dir];
        nRy = nRy+dy[dir];
    }
    //while문 탈출했을 때의 좌표는 #위치에 있으므로 한 칸 되돌려줌
    nRx = nRx-dx[dir];
    nRy = nRy-dy[dir];

    //파란 공 굴리기
    int nBx = Bx +dx[dir];
    int nBy = By +dy[dir];
    while(1)
    {
        if (MAP[nBx][nBy] =='#') break;
        if (MAP[nBx][nBy]=='O'){
            Blue_flag= true;
            break;
        }
        nBx = nBx +dx[dir];
        nBy = nBy +dy[dir];
    }
    nBx = nBx -dx[dir];
    nBy = nBy -dy[dir];

    if(Blue_flag) return;
    if(Red_flag){
        Answer = Min(Answer, Cnt);
        return;
    }
    //B와 R가 같은 좌표에 위치할때
    if (nRx==nBx && nRy==nBy){
        int Red_dist = Move_dist(Rx,Ry, nRx, nRy);
        int Blue_dist = Move_dist(Bx,By, nBx, nBy);

        if(Red_dist>Blue_dist){
            //더 많이 움직인 애를 한 칸 뒤로 보내줌.
            nRx = nRx - dx[dir];
            nRy = nRy - dy[dir];
        }
        else{
            //더 많이 움직인 애를 한 칸 뒤로 보내줌.
            nBx = nBx - dx[dir];
            nBy = nBy - dy[dir];
        }
    }

    for (int i=0;i<4;i++){
        //같은 방향이나, 지금 방향의 반대방향(제자리로 가는 것이므로)은 가지 않음
        if(i==dir) continue;
        if(i==Inverse_Direction(dir)) continue;

        Move(nRx, nRy, nBx, nBy, Cnt+1, i);
    }
}


void Solution(){
    //4방향 모두 탐색.
    for (int i=0;i<4;i++){
        int x = Red.first;
        int y = Red.second;
        int xx = Blue.first;
        int yy = Blue.second;

        Move(x, y, xx, yy, 1, i);
    }
    if (Answer>10 || Answer==987654321) Answer=-1;
    cout << Answer << endl;
}

void Input(){
    cin >> N >> M;
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cin >> MAP[i][j];
            if (MAP[i][j]=='R'){
                Red.first = i;
                Red.second = j;
                MAP[i][j] = '.';
            }else if(MAP[i][j]=='B'){
                Blue.first = i;
                Blue.second = j;
                MAP[i][j] = '.';
            }
        }
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

//[ref] : https://yabmoons.tistory.com/229
