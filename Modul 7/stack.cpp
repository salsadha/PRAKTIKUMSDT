#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.top = 0;
}

void push(Stack &S, infotype x) {
    if (S.top < 20) {
        S.info[S.top] = x;
        S.top++; 
    }
}

infotype pop(Stack &S) {
    infotype x = -1;
    if (S.top > 0) {
        S.top--; 
        x = S.info[S.top];
    }
    return x;
}

void printInfo(Stack S) {
    cout << "[TOP] ";
    for (int i = S.top - 1; i >= 0; i--) {
        cout << S.info[i] << " ";
    }
    cout << endl;
}

void balikStack(Stack &S) {
    Stack temp1, temp2;
    createStack(temp1);
    createStack(temp2);

    while (S.top > 0) { push(temp1, pop(S)); }
    while (temp1.top > 0) { push(temp2, pop(temp1)); }
    while (temp2.top > 0) { push(S, pop(temp2)); }
}

void getInputStream(Stack &S) {
    char c;
    while (cin.get(c) && c != '\n') {
        if (c >= '0' && c <= '9') {
            push(S, c - '0');
        }
    }
}