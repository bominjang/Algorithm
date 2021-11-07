#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0, count=0;
    //일반 큐
    queue<pair<int, int>> q;
    //우선순위 큐
    priority_queue<int> pq;
    
    for(int i=0;i<priorities.size();i++){
        //큐에 들어온 순서와 중요도를 넣음
        q.push({i, priorities[i]});
        //우선수위 큐에 넣음
        pq.push(priorities[i]);
    }
    
    //큐가 빌때까지 반복
    while(!q.empty()){
        int idx = q.front().first;
        int val = q.front().second;
        q.pop();
        //우선순위 큐의 첫번째에 저장된 수와 현재 값이 같다면
        if(pq.top()==val){
            //우선순위 큐 pop
            pq.pop();
            //하나가 나갔으므로 count
            count++;
            //현재 나간 것이 원하는 것과 같다면
            if(idx==location){
                answer = count;
                break;
            }
        }
        //우선순위 1순위와 현재 값이 같지 않다면 큐 뒤에 넣기
        else q.push({idx, val});
        
    }
    return answer;
}
//참고 : https://mungto.tistory.com/198
