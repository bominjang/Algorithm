#include <cmath>
using namespace std;

long long solution(int w,int h) {
    long long answer = 1;
    long long cantuse = 0;
    
    for(int i=1;i<=w;i++){
        cantuse += (long long)ceil((long double)i*h/w) - (long long)floor((long double)(i-1)*h/w);
    }
    answer = (long long)w*h - cantuse;
    return answer;
}
