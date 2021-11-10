#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    int left = 0, right=distance;
    sort(rocks.begin(), rocks.end());
    
    while(left<=right){
        int mid = (left+right)/2;//바위 사이의 거리들 중 최대값을 찾는다.
        int prev = 0, cnt = 0;
        
        for(int i=0;i<rocks.size();i++){
            if(rocks[i]-prev<mid)//mid가 최소값이 되어야 하므로 rock[i]를 제거해야 함
                cnt++;
            else
                prev = rocks[i];
        }
        //마지막 바위와 도착지점까지의 거리 체크
        if(distance - prev < mid)
            cnt++;
        if(cnt<=n){//돌을 너무 조금 지웠다 -> 거리를 좀 늘리자
            answer = max(mid, answer);
            left = mid+1;
        }else{//너무 많이 지웠다 -> 거리를 좀 줄이자
            right = mid -1;
        }
    }
    return answer;
}
//참고 : https://mjmjmj98.tistory.com/78
