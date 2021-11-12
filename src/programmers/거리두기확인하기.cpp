#include <string>
#include <vector>
#include <stdlib.h>
#include <algorithm>
#include <iostream>

using namespace std;

string person = "P";
string table = "O";
//y,x
//상, 우, 하, 좌
vector<pair<int, int>> near = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
//대각선과 상하좌우 간격 2
vector<pair<int, int>> dir = {{-1,-1}, {-1, 1}, {1, -1}, {1, 1},
                              {-2, 0}, {0, 2}, {2, 0}, {0, -2}};

//범위 검사
bool isValid(int row, int column)
{
    return (row<5 && row>=0 && column<5 && column>=0);
}

bool checkMan(int r, int c, vector<string> p)
{
    //상하좌우 인접한 것이 있는지 먼저 체크.
    for(int i=0;i<4;i++){
        int nr = r + near[i].first;
        int nc = c + near[i].second;
        //사람 둘이 붙어있다면 거리두기 X이므로 false를 return
        if(isValid(nr,nc) && (p[nr][nc]=='P')){
            return false;
        }
    }
    
    //대각선, 일직선 검사
    for(int i=0;i<dir.size();i++){
        int nr = r + dir[i].first;
        int nc = c + dir[i].second;
        
        if(!isValid(nr, nc) || p[nr][nc]!='P') continue;
        //대각선과 일직선(거리 차 2) 좌표 중 P인경우만 여기까지 들어옴.
        //대각선 검사
        if(abs(nr-r)==1||abs(nc-c)==1){
            if(p[r][nc]=='O'||p[nr][c]=='O') return false;
        }
        //일직선 검사
        if(abs(nr-r)==2||abs(nc-c)==2){
            if(nc<c && p[r][c-1]=='O') return false;
            if(nc>c && p[r][c+1]=='O') return false;
            if(nr<r && p[r-1][c]=='O') return false;
            if(nr>r && p[r+1][c]=='O') return false;
        }
    }
    //검사를 모두 통과하면 return true
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    //5개의 대기실, 5*5크기
    //맨해튼 거리가 3이상이어야 함.
    //예외 : 자리 사이 파티션 존재 시 맨해튼 2여도 OK
    //but, 사이에 빈 테이블이있는 경우는 X
    // P: 응시자, O : 빈테이블, X: 파티션
    //대기실 별로 거리두기 지키면 1 , 아니면 0
    vector<int> answer;
    
    for(int P=0;P<5;P++){//교실
        int ans = 1;//지키는지 안지키는지. default : 지킨다.
        for(int i=0;i<5;i++){//행
            for(int j=0;j<5;j++){//열
                if(places[P][i][j]=='P'){
                    if(!checkMan(i,j, places[P])){//P이면 주변 검사하러 보냄. false이면 지키지 못하므로
                        ans = 0;//ans을 0으로 세팅하고 그만.
                        break;
                    }
                }
            }
            if(ans==0) break;
        }
        answer.push_back(ans);//한 교실 끝날때마다 ans값 
        
    }
    
    return answer;
}
