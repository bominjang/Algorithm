#include <stdio.h>

int solution(int n, int m){
//이 아래 필요한 변수 및 필요한 코드를 작성하세요
	int answer=0;
	// n : 재고, m : 입고되는 날짜 간격. m일마다 재고 n+1
	while(n!=0)
	{
		answer++;
		n--;
		if(answer%m == 0)
		{
			n++;
		}
	}
	
	return answer;
}

int main() {
   int m;
   int n;
   int answer;
   scanf("%d %d", &n, &m);
   answer = solution(n, m);
   printf("%d", answer);
	
   return 0;
}

