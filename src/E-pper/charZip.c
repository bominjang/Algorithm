//
//  main.c
//  epper
//
//  Created by 장보민 on 2021/05/09.
//

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

char* solution(const char* s)
{
    int n, i, count = 0, idx=0;
    char *answer;
    n = strlen(s);
    answer = (char*)malloc(n*2);
    if(s[0]=='1') answer[idx++]='1';
    
    for(i = 1;i<n;i++)
    {
        if(s[i] != s[i-1])
        {
            answer[idx++] = 'A'+count;
            count=0;
        }
        else count++;
    }
    answer[idx++] = 'A'+count;
    answer[idx] =0;//null
    return answer;
}

int main(int argc, const char * argv[]) {
    char s[10000] = "";
    char *answer;
    
    printf("input str: ");
    scanf("%s", s);
    
    answer = solution(s);
    printf("answer : %s\n", answer);
    return 0;
}
