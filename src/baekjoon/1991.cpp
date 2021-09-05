#include<iostream>

using namespace std;

int N;

struct Node {
    char left;
    char right;
};

struct Node arr[100];

void preOrder(char root) {
    if (root == '.')
        return;
    else {
        cout << root;
        preOrder(arr[root].left);
        preOrder(arr[root].right);
    }
}

void inOrder(char root) {
    if(root=='.')
        return;
    else{
        inOrder(arr[root].left);
        cout<<root;
        inOrder(arr[root].right);
    }
}

void postOrder(char root){
    if(root=='.')
        return;
    else{
        postOrder(arr[root].left);
        postOrder(arr[root].right);
        cout<<root;
    }
}

int main() {
    scanf("%d", &N);
    char value, left, right;

    for (int i = 1; i <= N; i++) {
        cin >> value >> left >> right;
        arr[value].left = left;
        arr[value].right = right;
    }

    preOrder('A');
    cout<<"\n";
    inOrder('A');
    cout<<"\n";
    postOrder('A');
    cout<<"\n";

    return 0;
}
