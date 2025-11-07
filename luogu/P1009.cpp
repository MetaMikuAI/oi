#include <iostream>
#include <vector>
using namespace std;

#define N 70
#define bigNum vector<int>

bigNum parse(int src) {
    // assert src < 10
    bigNum res(N, 0);
    res[N - 1] = src % 10;
    return res;
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

bigNum mul(bigNum A, bigNum B) {
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
    int n;
    cin >> n;
    
    bigNum ONE = parse(1);
    bigNum x(N, 0);
    bigNum tmp = parse(1); // = 1 = 0!
    bigNum res(N, 0);

    for (int i = 0; i < n; i++) {
        x = add(x, ONE);
        tmp = mul(tmp, x);
        res = add(res, tmp);
    }

    print(res);

    return 0;
}

/*
P1009 [NOIP 1998 普及组] 阶乘之和
普及-

calc $\sum_{x=1}^{n}{x!}$

阶乘求和应该是简单优化一下的，不用每次从 1 累乘

话说这种大数是不是可以直接抄板子来着））
之后找找，先留个 TODO

gdb 时发现上一题 P1303 代码一个 bug：mul 会修改原值，这不太好，于是我把引用去了

忘记估算一下数据范围了，最大 50! < 10^65
取个 70 吧

Check 1: 4AC
一定要找个板子

MetaMiku 20250924 21:42
*/