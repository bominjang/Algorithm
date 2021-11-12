#include <string>
#include <vector>
#include <algorithm>
 
using namespace std;
 
vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    int i, j, q;
    //map, tmp 초기화
    vector<vector<int>> map(rows+1, vector<int>(columns+1));
    vector<vector<int>> tmp(rows+1, vector<int>(columns+1));//여기에 수정하고, 수정내용을 map에 복사하는 식으로 진행.
    for(i=1;i<=rows;i++){
        for(j=1;j<=columns;j++){
            map[i][j] = (i-1)*columns+j;
            tmp[i][j] = (i-1)*columns+j;
        }
    }
    
    int mini, x1, y1, x2, y2;
    for(q=0;q<queries.size();q++){
        //x1 행, y1열 ~ x2행, y2열
        mini = 2147000000;
        x1 = queries[q][0];
        y1 = queries[q][1];
        x2 = queries[q][2];
        y2 = queries[q][3];
        //top x: 행, y : 열
        for(j = y1+1; j<=y2;j++){
            tmp[x1][j] = map[x1][j-1];//앞의 것을 당겨옴
            mini = min(tmp[x1][j], mini);
        }
        //right
        for(i = x1+1; i<=x2;i++){
            tmp[i][y2] = map[i-1][y2];
            mini = min(tmp[i][y2], mini);
        }
        //bottom
        for(j = y2-1; j>=y1; j--){
            tmp[x2][j] = map[x2][j+1];
            mini = min(tmp[x2][j], mini);
        }
        //left
        for(i= x2-1; i>=x1;i--){
            tmp[i][y1] = map[i+1][y1];
            mini = min(tmp[i][y1], mini);
        }
        map = {tmp.begin(), tmp.end()};
        answer.push_back(mini);
    }
    
    return answer;
}
