#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

//완전탐색, 
//for문 괄호 위치 때문에 하루를 헤맸다....................................

const int coverType[4][3][2] = {
        {{0, 0}, {1, 0}, {0, 1}},
        {{0, 0}, {0, 1}, {1, 1}},
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {1, -1}}
};

//delta = 1 -> 덮음, delta = -1 -> 블록 없앰
//겹치거나 검은 판을 덮을 때 false를 반환
bool set(vector<vector<int>> &board, int y, int x, int type, int delta) {
    bool ok = true;
    for (int i = 0; i < 3; i++) { //L type
        const int ny = y + coverType[type][i][0];
        const int nx = x + coverType[type][i][1];
        if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size())
            ok = false;
        else if ((board[ny][nx] += delta) > 1) //덮은 곳을 또 덮거나, 검은 판을 덮을 때.
            ok = false;
    }
    return ok;
}

//board의 모든 빈 칸을 덮을 수 있는 방법의 수를 반환한다.
//board[i][j] =  1 이미 덮인 칸 혹은 검은 칸
//board[i][j] = 0 아직 덮이지 않은 칸(당연히 흰색)
int FindCover(vector<vector<int>> &board) {
    //아직 채우지 못한 칸 중 가장 윗줄의 왼쪽에 있는 칸을 찾는다.
    int y = -1, x = -1;
    for (int i = 0; i < board.size(); i++) {
        for (int j = 0; j < board[i].size(); j++) {
            if (board[i][j] == 0) {
                y = i;
                x = j;
                break;
            }
        }
        //다 색칠되어 있으면 y=-1이어야하는데 아니면 break;
        if (y != -1) break;
    }

    //base condition : 모든 칸을 채웠으면 1을 return
    if (y == -1) return 1;
    int ret = 0;
    for (int type = 0; type < 4; type++) {
        //만약 board[y][x]를 type형태로 덮을 수 있으면 재귀 호출
        if (set(board, y, x, type, 1)) {
            ret += FindCover(board);
        }
        //unset
        set(board, y, x, type, -1);
    }
    return ret;
}


int main() {
    int C;
    cin >> C;
    assert(C <= 50);
    while (C--) {
        int H, W;
        cin >> H >> W;
        assert(H <= 20 && W <= 20);
        int whites = 0;
        vector<vector<int> > board(H, vector<int>(W, 0));
        for (int i = 0; i < H; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < s.size(); j++) {
                if (s[j] == '#')
                    board[i][j] = 1;
            }
            whites += count(board[i].begin(), board[i].end(), 0);
        }
        assert(whites <= 50);
        int ways = FindCover(board);
        cout << ways << endl;
    }
    return 0;
}
