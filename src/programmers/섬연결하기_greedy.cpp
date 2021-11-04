#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> parent(101);

bool cmp(const vector<int> &a, const vector<int> &b){
    return a[2]<b[2]; //오름차순 정렬
}

int find(int x)
{
    if(x==parent[x]) return x;
    else return parent[x] = find(parent[x]);
}

int merge(int a, int b){
    //두 섬의 상위 부모 섬을 찾는다.
    a = find(a);
    b = find(b);
    
    if(a==b) return false;
    else{
        //최상위 부모 섬을 컨테이너에 기록해 놓는다.
        if(a>b) parent[a]=b;
        else parent[b] = a;
    }
    return true;
}

int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    //parent 벡터 초기화
    for(int i=0;i<n;i++) parent[i] = i;
    //비용 오름차순 정렬
    sort(costs.begin(), costs.end(), cmp);
    int size = costs.size();
    for(int i=0; i<size; i++){
        //다리를 잇는 작업.
        //만약 false라면 사이클이 생기는 경우. 다리를 설치하지 않음
        if(merge(costs[i][0], costs[i][1])==true)
            answer+= costs[i][2];
    }
    return answer;
}
