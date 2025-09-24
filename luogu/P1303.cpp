#include <iostream>
#include <vector>
using namespace std;

#define N 5000
#define bigNum vector<int>

void parse(string& src, bigNum& dst) {
    int len = src.length();
    for (int i = 0; i < len; i++) {
        dst[N - 1 - i] = src[len - 1 - i] - '0';
    }
}

bigNum add(bigNum& A, bigNum& B) {
    bigNum res(N, 0);
    int carry = 0;
    for (int i = N - 1; i >= 0; i--) {
        int sum = A[i] + B[i] + carry;
        res[i] = (sum % 10);
        carry = sum / 10;
    }
    // return carry; // OF 位，本题应该是用不上
    return res;
}

bigNum mul_n(bigNum& A, int n) { // 按位乘
    bigNum res(N, 0);
    int carry = 0;
    for (int i = N - 1; i >= 0; i--) {
        int sum = A[i] * n + carry;
        res[i] = (sum % 10);
        carry = sum / 10;
    }
    // return carry; // OF 位，<s> 只要我 N 开的足够大就不会有 OF </s>
    return res;
}

int shl(bigNum& A) { // 自左移，本题每次只要左移一位即可
    int overflow = A[0];
    for (int i = 0; i < N - 1; i++) {
        A[i] = A[i+1];
    }
    A[N-1] = 0;
    return overflow;
}

int shr(bigNum& A) { // 自右移，本题每次只要右移一位即可
    int underflow = A[N - 1];
    for (int i = N - 1; i >= 1; i--) {
        A[i] = A[i - 1];
    }
    A[0] = 0;
    return underflow;
}

bigNum mul(bigNum& A, bigNum& B) {
    bigNum res(N, 0);
    bigNum tmp(N, 0);
    for (int i = N - 1; i >= 0; i--) {
        tmp = mul_n(A, B[N - 1]);
        shr(B);
        shl(A);
        res = add(res, tmp);
    }
    return res;
}


void print(bigNum& A) {
    bool flag = false; // 前导 0 标志位
    for (int i = 0; i < N; i++) {
        if (A[i] != 0 || flag) {
            cout << A[i];
            flag = true;
        }
    }
    if (flag == false) { // 全 0
        cout << "0";
    }
    cout << endl;
}

int main() {
    string strA = "";
    string strB = "";
    bigNum A(N, 0);
    bigNum B(N, 0);
    bigNum C(N, 0);

    cin >> strA;
    cin >> strB;
    parse(strA, A);
    parse(strB, B);
    C = mul(A, B);
    print(C);

    return 0;
}

/*
P1303 A*B Problem
普及−

顺着上一题写就好了

Check 1: AC AC WA RE RE
RE 是什么鬼？
哦我忘记调 N 的大小了

Check 2: AC AC AC AC WA
啊？再看看题，原来输入最大是 10^2000，N 改成 5000 总不能还爆吧

Check 3: 5AC


MetaMiku 20250924 21:21
*/