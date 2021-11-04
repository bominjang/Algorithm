#include <string>
#include <vector>
#include <iostream>
#include <set>
#include <math.h>
#include <algorithm>

using namespace std;

//소수 판별 함수
bool isPrime(int n){
    if(n<2) return false;
    
    //에라토스테네스의 체
    for(int i=2;i<=sqrt(n);i++){
        if(n%i==0) return false;//1과 자신이 아닌 어떤것에 나누어진다는 것이므로
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    vector<char> n; //종이 조각의 각 숫자 저장
    vector<int> nums;//종이 조각으로 만들 수 있는 모든 수 저장
    for(int i=0;i<numbers.size();i++){
        n.push_back(numbers[i]);
    }
    sort(n.begin(), n.end());
    
    do{
        string temp="";
        //만들 수 있는 모든 숫자를 nums에 저장
        for(int i=0;i<n.size();i++){
            temp.push_back(n[i]);
            nums.push_back(stoi(temp)); 
            //순열이 "012"인 경우, 0, 01, 012 저장
        }
    }while (next_permutation(n.begin(), n.end()));
    //현재 나와 있는 수열에서 인자로 넘어간 범위에 해당하는 다음 순열을 구하고 true를 반환한다. 다음 순열이 없다면(다음에 나온 순열이 순서상 이전 순열보다 작다면) false를 반환.
    
    //중복값 지우기
    sort(nums.begin(), nums.end());
    nums.erase(unique(nums.begin(), nums.end()), nums.end());
    
    //소수인 경우 answer++
    for(int i=0;i<nums.size();i++){
        if(isPrime(nums[i])) answer++;
    }
    return answer;
}

//[ref] : https://mjmjmj98.tistory.com/50
