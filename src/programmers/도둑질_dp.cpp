#include <string>
#include <vector>
#include <algorithm>
#define MAX 1000010
using namespace std;

int DP[MAX];//0번째 집을 털었을 때
int DP2[MAX]; //0번째 집을 털지 않았을 때
int solution(vector<int> money) {
    int n = money.size()-1;
    //0번째 집을 털었을 때
    DP[0] = money[0];
    DP[1] = DP[0];
    //0번째 집을 털지 않았을 때
    DP2[0] = 0;
    DP2[1] = money[1];
    
    //0번째 집을 털었을 때. 0번째부터 money.size()-2번째 집까지 검사.
    for(int i=2;i<n;i++){
        DP[i] = max(DP[i-2]+money[i], DP[i-1]);
    }
    //0번째 집을 털지 않았을 때. 0번째부터 money.size()-1번째 집까지 검사.
    for(int i=2;i<=n;i++){
        DP2[i] = max(DP2[i-2]+money[i], DP2[i-1]);
    }
    
    return max(DP[n-1], DP2[n]);
}
