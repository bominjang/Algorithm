#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void makeSco(priority_queue<int,vector<int>, greater<int>> &pq){
    int min1 = pq.top();
    pq.pop();
    int min2 = pq.top();
    pq.pop();
    int mix = min1 + (min2*2);
    pq.push(mix);
}

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    while(pq.top()<K){
        makeSco(pq);
        answer++;
        if(pq.size()==1 && pq.top()<K){
            answer=-1;
            break;
        }
    }
    return answer;
}
