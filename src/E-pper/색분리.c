//
//  main.c
//  algo
//
//  Created by 장보민 on 2021/04/08.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 8
#define SWAP(x, y, t) ((t) = (x), (x)=(y), (y)=(t))

void partition(char list[], int left, int right, char target)
{
    int low = left-1;
    int high = right+1;
    
    char temp='0';
    
    do{
        do{
            low++;
        }while(list[low] == target);
        
        do{
            high--;
        }while(list[high] != target);
        
        printf("\nlow=%d, high=%d\n", low, high);
        for(int i=0;i<MAX_SIZE;i++)
            printf("[%c] ", list[i]);
        printf("\n");
        if(low<high)
        {
            SWAP(list[low], list[high], temp);
        }
        //printf("\nlow=%d, high=%d\n", low, high);
        for(int i=0;i<MAX_SIZE;i++)
            printf("[%c] ", list[i]);
        printf("\n");
    }while(low<high);
}

void main(int argc, const char * argv[]) {
    char list[MAX_SIZE] = {'G', 'W','B','G','W','G','W','B'};
    
    for(int i=0;i<MAX_SIZE;i++)
        printf("[%c] ", list[i]);
    printf("\n"); getchar();
    
    partition(list, 0, MAX_SIZE-1, 'W');
    partition(list, 3, MAX_SIZE-1, 'G');
    printf("\n\n");
    
    printf("결과\n");
    for(int i=0;i<MAX_SIZE;i++)
        printf("[%c] ", list[i]);
    printf("\n");
}

