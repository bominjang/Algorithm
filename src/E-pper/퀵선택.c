#include <stdio.h>
#include <stdlib.h>
 
/* Swap */
void Swap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
 
/* Partition */
int Partition(int arr[], int left, int right)
{
    // 기본적으로 QuickSort의 Pivot 선정 후 교환 과정과 동일
    // pivot은 가장 왼쪽의 인덱스로 결정
    int pos = arr[left];
    int low = left + 1, high = right;
    while (low <= high)
    {
        while (low <= right && arr[low] <= pos)
        {
            low++;
        }
        while (high >= (left+1) && arr[high] >= pos)
        {
            high--;
        }
        if (low <= high)
        {
            Swap(&arr[low], &arr[high]);
        }
    }
    Swap(&arr[left], &arr[high]);
    return high;
}
 
/* QuickSelect */
int QuickSelect(int arr[], int left, int right, int select)
{
    // 찾고자 하는 인덱스가 범위 내에 존재할 때,
    if (select > 0 && select <= right - left + 1)
    {
        int pos = Partition(arr, left, right);
 
        // 찾고자 하는 숫자를 찾은 경우
        if (pos - left == select - 1)
        {
            return arr[pos];
        }
        // 찾고자 하는 숫자가 small group에 있는 경우
        else if (pos - left > select - 1)
        {
            return QuickSelect(arr, left, pos - 1, select);
        }
        // 찾고자 하는 숫자가 large group에 있는 경우
        else
        {
            return QuickSelect(arr, pos + 1, right, select - pos + left - 1);
        }
    }
    // 탐색 실패 시,
    return -1;
}
 
int main(void)
{
    int n, index; // n: arr size, k: index
    int *arr = NULL;
 
    printf("배열 크기 : ");
    scanf("%d", &n);
    printf("몇 번째 크기의 원소 : ");
    scanf("%d", &index);
 
    arr = (int*)malloc(sizeof(int)*n);
 
    printf("배열 입력 : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", (arr + i));
    }
 
    printf("%d 번째 크기의 원소 : %d\n", index, QuickSelect(arr, 0, n - 1, index));
    return 0;
}
