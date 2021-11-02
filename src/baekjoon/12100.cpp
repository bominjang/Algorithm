#include<iostream>

#define endl "\n"
#define MAX 20
using namespace std;

int N,Answer=0;
int MAP[MAX][MAX];
int C_MAP[MAX][MAX];
int selected[5];

int Bigger(int A, int B){ if (A>B) return A; return B;}

void copyMap()
{
    for(int i=0;i<N;i++){
        for(int j=0;j<N; j++){
            C_MAP[i][j] = MAP[i][j];
        }
    }
}

int Find_Max()
{
    int Max = 0;
    for (int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++){
            if(C_MAP[i][j] > Max){
                Max = C_MAP[i][j];
            }
        }
    }
    return Max;
}

void moveL(){
    int i, j, k;
    for(i=0;i<N;i++){
        for(j=0;j<N-1;j++){
            bool check = false;
            if(C_MAP[i][j]==0){
                k=j+1;
                while(k<=N-1){
                    if(C_MAP[i][k]!=0){
                        check=true;
                        break;
                    }
                    k++;
                }
                if(check==true){
                    //옮기기
                    C_MAP[i][j] = C_MAP[i][k];
                    C_MAP[i][k] = 0;
                }
            }
        }
    }
}

void Move_Left(){
    moveL();
    int i,j;
    for(i=0;i<N;i++)
    {
        for(j=0;j<N-1;j++){
            //같은 거 두개 나란히 있으면 합침
            if(C_MAP[i][j]==C_MAP[i][j+1]){
                C_MAP[i][j] = 2*C_MAP[i][j];
                C_MAP[i][j+1] = 0;
            }
        }
    }
    moveL();
}

void moveR(){
    int i, j, k;
    for(i=0;i<N;i++){
        for(j=N-1;j>0;j--){
            bool check=false;
            //빈칸이라면, 여기로 땡겨와야함
            if(C_MAP[i][j]==0){
                k=j-1;
                while(k>=0){
                    if(C_MAP[i][k]!=0){
                        check=true;
                        break;
                    }
                    k--;
                }
                if(check==true){
                    C_MAP[i][j] = C_MAP[i][k];
                    C_MAP[i][k] = 0;
                }
            }
        }
    }
}

void Move_Right(){
    int i,j;
    moveR();
    //같은 수 붙어있는 것 처리
    for(i=0;i<N; i++){
        for(j=N-1;j>0;j--){
            if(C_MAP[i][j]==C_MAP[i][j-1]){
                C_MAP[i][j]= 2*C_MAP[i][j];
                C_MAP[i][j-1] = 0;
            }
        }
    }
    moveR();
}

void moveU(){
    int i, j,k;
    for(i=0;i<N-1;i++){//행
        for(j=0;j<N;j++){//열
            bool check= false;
            if(C_MAP[i][j]==0){//j행
                k=i+1;//행을 움직이며 탐색
                while(k<=N-1){
                    if(C_MAP[k][j] != 0){
                        check=true;
                        break;
                    }
                    k++;
                }
                if(check==true){
                    C_MAP[i][j] = C_MAP[k][j];
                    C_MAP[k][j] = 0;
                }
            }
        }
    }
}


void Move_Up(){
    int i,j;
    moveU();
    for(i=0;i<N-1;i++){
        for(j=0;j<N;j++){
            if(C_MAP[i][j]==C_MAP[i+1][j]){
                C_MAP[i][j] = 2*C_MAP[i][j];
                C_MAP[i+1][j] = 0;
            }
        }
    }
    moveU();
}

void moveD(){
    int i,j,k;

    for(i=N-1;i>0;i--){
        for(j=0;j<N;j++){
            bool check = false;
            if(C_MAP[i][j]==0){ //만약 i,j가 0이라면 당겨올 것을 찾아야함
                k=i-1;//위로 탐색
                while(k>=0){
                    if(C_MAP[k][j]!=0){
                        check=true;
                        break;
                    }
                    k--;
                }
                if(check==true){
                    C_MAP[i][j] = C_MAP[k][j];
                    C_MAP[k][j] = 0;
                }
            }
        }
    }
}

void Move_Down(){
    int i,j;
    moveD();
    for(i=N-1;i>0;i--){
        for(j=0;j<N;j++){
            if(C_MAP[i-1][j]==C_MAP[i][j])
            {
                C_MAP[i][j] = 2*C_MAP[i][j];
                C_MAP[i-1][j] = 0;
            }
        }
    }
    moveD();
}

void playTheGame(){
    for (int i=0;i<5;i++)
    {
        int dir = selected[i];
        if(dir==0) Move_Right();
        else if(dir==1) Move_Left();
        else if(dir==2) Move_Down();
        else if(dir==3) Move_Up();
    }
    Answer = Bigger(Answer, Find_Max());
}

void selectDirection(int cnt)
{
    if(cnt==5){
        copyMap();
        playTheGame();
        return;
    }

    //우, 좌, 하, 상
    for (int i=0;i<4;i++){
        selected[cnt] = i;
        selectDirection(cnt+1);
    }
}

void Solution(){
    //방향 선택. 중복순열 구하기
    selectDirection(0);
    cout << Answer << endl;
}

void Input(){
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> MAP[i][j];
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
