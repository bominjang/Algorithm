#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;

string str;
stack<char> oper;

void postfix() {
    for (int i = 0; i < str.length(); i++) {
        if (str[i] >= 'A' && str[i] <= 'Z') {
            printf("%c", str[i]);
            continue;
        }
        if (str[i] == '(') { oper.push(str[i]); }
        else if (str[i] == '*' || str[i] == '/') {
            while (!oper.empty() && (oper.top() == '*' || oper.top() == '/')) {
                printf("%c", oper.top());
                oper.pop();
            }
            oper.push(str[i]);
        } else if (str[i] == '+' || str[i] == '-') {
            while (!oper.empty() && (oper.top() != '(')) {
                printf("%c", oper.top());
                oper.pop();
            }
            oper.push(str[i]);
        } else if (str[i] == ')') {
            while (!oper.empty() && oper.top() != '(') {
                printf("%c", oper.top());
                oper.pop();
            }
            oper.pop();
        }
    }
    while (!oper.empty()) {
        printf("%c", oper.top());
        oper.pop();
    }
    printf("\n");
}

void input() {
    cin >> str;
}

void solve() {
    input();
    postfix();
}

int main() {
    solve();

    return 0;
}
