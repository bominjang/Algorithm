#include<iostream>
#include <algorithm>

using namespace std;

int N;

int triangle[501][501];

bool comp(int a, int b) {
    return a > b;
}

int main() {
    scanf("%d", &N);

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= i; j++) {
            if (i == 1 && j == 1) {
                cin >> triangle[i][j];
            } else {
                int num;
                cin >> num;
                //맨 왼쪽 끝이거나 맨 오른쪽 끝이면, 각각 이전줄의 맨왼쪽 끝과 맨 오른쪽밖에 더할 게 없음.
                if (j == 1) {
                    triangle[i][j] = num + triangle[i - 1][j];
                } else if (j == i) {
                    triangle[i][j] = num + triangle[i - 1][j - 1];
                } else { //그게 아니라면, 왼쪽 대각선 위의 것과 오른쪽 대각선 위의 것 중 큰 것을 더함
                    triangle[i][j] = num + max(triangle[i - 1][j - 1], triangle[i - 1][j]);
                }
            }
        }
    }
    sort(triangle[N], triangle[N]+N+1, comp);

    cout << triangle[N][0];

    return 0;
}
