#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int solution(vector<vector<int>> routes) {
    int answer = 0, flag=30001;
    //0번째 인덱스 기준으로 내림차순 정렬
    sort(routes.rbegin(), routes.rend());
    
    for(int i=0;i<routes.size();i++){
        if(flag>routes[i][1]){
            flag = routes[i][0];
            answer++;
        }
    }
    return answer;
}
