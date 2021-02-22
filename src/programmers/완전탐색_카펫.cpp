#include <string>
#include <vector>

using namespace std;

bool isOK(int brown, int row, int col) {
    if(brown==(row*2+col*2-4)){
        return true;
    }
    else{
        return false;
    }
}

vector<int> solution(int brown, int yellow) {
    //세로==가로 or 세로<가로
    //col = 가로 갯수, row = 세로 갯수
    vector<int> answer;
    int whole = brown+yellow;

    for(int row = 3; row*row <= whole; row++){
        if(whole%row==0){
            int col = whole/row;

            if(isOK(brown,row,col)){
                answer.push_back(col);
                answer.push_back(row);
                break;
            }
        }

    }


    return answer;

}
