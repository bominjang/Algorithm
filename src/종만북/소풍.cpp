#include <algorithm>
#include <iostream>

using namespace std;
//page 157.p - 완전 탐색. 가능한 조합의 수. 재귀.
int n, m;
int c;
bool areFriends[10][10];

int countPairings(bool taken[10]) {
    int firstFree = -1;
    //남은 학생들 중 번호가 가장 빠른 학생 찾기. 중복을 제거하기 위함.
    for (int i = 0; i < n; i++) {
        if (!taken[i]) {
            firstFree = i;
            break;
        }
    }
    //base condition : 모든 학생이 짝을 찾았으면 한 가지 방법을 찾았으니 종료
    if (firstFree == -1) return 1;
    int ret = 0;

    //이 학생과 짝지을 학생을 결정
    for (int pairWith = firstFree + 1; pairWith < n; pairWith++) {
        //항상 사전 순으로 가장 먼저 오는 답 하나만 세기. 중복을 제거하기 위함.
        if (!taken[pairWith] && areFriends[firstFree][pairWith]) {
            taken[firstFree] = taken[pairWith] = true;
            ret += countPairings(taken);
            taken[firstFree] = taken[pairWith] = false;
        }
    }
    return ret;

}

void solve() {
    scanf("%d", &c);

    while (c--) {
        cin >> n >> m;
        assert(n>=2 && m<=10);
        memset(areFriends, false, sizeof(areFriends));
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            assert(0 <= a && a < n && 0 <= b && b < n);
            assert(!areFriends[a][b]);
            areFriends[a][b] = areFriends[b][a] = true;
        }
        bool taken[10];
        memset(taken, false, sizeof(taken));
        cout << countPairings(taken) << "\n";
    }
}


int main() {
    solve();

    return 0;
}
