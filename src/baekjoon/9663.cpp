#include <iostream>
using namespace std;
 
int answer = 0;
int arr_size = 0;
// 세로에 값이 존재하는지 확인하기 위한 행렬
int* existing_site_arr;
// 우측 대각선에 값이 존재하는지 확인하기 위한 행렬
int* cross_right_up;
// 좌측 대각선에 값이 존재하는지 확인하기 위한 행렬
int* cross_left_up;
 
void dfs(int depth) {
    // if dfs depart end point, then stop;
    if (depth == arr_size ) {
        answer++;
        return;
    } 
 
 
    // go to the next level;
    for (int i = 0; i < arr_size; i++) {
        if ((existing_site_arr[i] == 1) || (cross_right_up[depth + i] == 1) || (cross_left_up[arr_size - 1 + (depth - i)] == 1))
            continue;
 
        existing_site_arr[i] = cross_right_up[depth + i] = cross_left_up[arr_size - 1 + (depth - i)] = 1;
        dfs(depth + 1);
        existing_site_arr[i] = cross_right_up[depth + i] = cross_left_up[arr_size - 1 + (depth - i)] = 0;
    }
}
 
int main() {
    cin >> arr_size;
 
    // 동적 할당을 이용하여, 이중 배열을 생성해준다. 
    existing_site_arr = (int*)malloc(sizeof(int) * arr_size); 
    cross_right_up = (int*)malloc(sizeof(int) * (2 * arr_size - 1));
    cross_left_up = (int*)malloc(sizeof(int) * (2 * arr_size - 1));
 
    dfs(0);
 
    cout << answer;
 
    return 0;
}
