#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int ans = 9;

void dfs(int n, int num, int cnt, int cur)
{
    if(cnt>8) return;
    if(cur==num){
        ans = min(ans, cnt);
        return;
    }
    //더하기, 붙이기, 나누기
    int tmp=0;
    for(int i=1;i+cnt<=8;i++){
        tmp = tmp*10+n;
        dfs(n, num, cnt+i, cur+tmp);
        dfs(n, num, cnt+i, cur*tmp);
        dfs(n, num, cnt+i, cur/tmp);
        dfs(n, num, cnt+i, cur-tmp);
    }
    
}

int solution(int N, int number) {
    dfs(N, number, 0, 0);
    if(ans>8)
        ans=-1;
    return ans;
}
