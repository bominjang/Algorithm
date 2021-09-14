#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
int n;
vector<int> arr;
vector<int> dp;

bool comp;

int solution() {
    for(int i=0; i<n; i++){
        for(int j=0; j<i; j++){
            if(arr[i]> arr[j]){
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }
    sort(dp.begin(), dp.end());
    return dp[n-1];
}

int main(){
    scanf("%d", &n);
    int element;
    for(int i=0; i<n; i++){
        cin >> element;
        arr.push_back(element);
        dp.push_back(1);
    }
    printf("%d\n", solution());
}
