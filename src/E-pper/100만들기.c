//프로그래머스에서는 main함수 및 입출력문이 필요하지 않습니다. 대신 solution함수만 작성하면 됩니다.
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
// 정수 배열 numbers 의 길이는 9 입니다.
int* solution(int numbers[]) {
 //할당 길이는 상황에 맞게 변경해주세요.
 int* answer = malloc(sizeof(int) * 7);
 int* delete = malloc(sizeof(int) * 2);
 int sum = 0, temp = 0;
 int i=0, j=8;


 for(int i=0;i<9;i++)
     sum+=numbers[i];
 temp = sum-100;
 
 while (i < j){
     int del = numbers[i]+numbers[j];
        if (del==temp)
                {
                    delete[0] = i;
                    delete[1] = j;
                    break;
                }
        else if(del>temp){
                    j--;
                } //합보다 크면 끝의 포인터를 하나 줄이고,
            
        else{
                    i++;
                }//합보다 작으면 처음의 포인터를 하나 올립니다.
     
 }
    j=0;
    for(int i=0;i<9;i++){
        if(delete[0]==i || delete[1]==i) continue;
        answer[j++] = numbers[i];
    }
    free(delete);
    
 return answer;
}

int main(void) {
    int numbers[9];
    int i;
    int *r=NULL;
    
    for (i = 0; i < 9; i++) {
        scanf("%d", &numbers[i]);
    }
    
    
    r = solution(numbers);
    for (i = 0; i < 7; i++) {
        printf("%d ", r[i]);
    }
}

