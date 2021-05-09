//
//  main.c
//  epper
//
//  Created by 장보민 on 2021/05/09.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
//s : 희망 시작시간, e : 희망 종료시간
// s_len은 배열 s의 길이입니다.
// e_len은 배열 e의 길이입니다.
int solution(int s[], size_t s_len, int e[], size_t e_len) {
    int answer = 0, N = s_len;//N은 학생의 수
    int i, j, tmp, e1 = -1, e2=-1; //e1, e2는 각 자리를 의미.
    
    //학생들을 종료시간 오름차순으로 정렬
    for(i =0;i<N;i++)
    {
        for(j=0;j<N-1;j++)
        {
            if((e[j]>e[j+1])||(e[j]==e[j+1]&&s[j]>s[j+1]))
            {
                tmp = s[j];
                s[j] = s[j+1];
                s[j+1] = tmp;
                tmp = e[j];
                e[j] = e[j+1];
                e[j+1] = tmp;
            }
        }
    }
    
    for(i = 0; i<N;i++)
    {
        if(e1<=s[i])//1번 자리가 비어있다면 학생을 할당
        {
            e1 = e[i]; //1번 자리에 학생의 종료 시간을 넣음
            answer++; //학생이 1명 할당 되었으니 학생수 올려줌
        }
        
        else if(e2<=s[i])//2번 자리가 비어있다면 학생을 할당
        {
            e2 = e1; //1번 자리의 값을 2번 자리에 넣어서 이미 자리에 할당된 학생의 종료시간을 보존
            e1= e[i]; //1번 자리에 학생의 종료 시간을 대입
            answer++; //학생이 1명 할당 되었으니 학생수를 또 올려줌
        }
    }
    return answer;
}

int main(int argc, const char * argv[]) {
    int s[] = {1, 2, 3, 4, 5};
    int e[] = {2, 3, 4, 5, 6};
    size_t s_len = sizeof(s)/4;
    size_t e_len = sizeof(e)/4;
        
    printf("\n\n TestCase Result : %d \n", solution(s, s_len, e, e_len));
}
