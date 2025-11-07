#include <iostream>
#include <vector>
using namespace std;

#define N 2656
// #define N 10

void mul(vector<int>& num, int k) {
    int carry = 0;
    for (int i = N - 1; i > 0; i--) {
        int sum = num[i] * k + carry;
        carry = sum / 10;
        num[i] = sum % 10;
    }
    num[0] += carry;
}

void factorial(vector<int>& num, int n) {
    for (int i = 1; i <= n; i++) {
        mul(num, i);
    }
}

int count(vector<int>& num, int a) {
    int i;
    int count = 0;
    for (i = 0; i < N; i++) {
        if (num[i]) {
            break;
        }
    }
    for (; i < N; i++) {
        if (num[i] == a) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    cin >> t;


    vector<int> ONE(N, 0);
    ONE[N - 1] = 1;

    int n, a;
    while (cin >> n >> a) {
        vector<int> num(ONE);
        factorial(num, n);
        cout << count(num, a) << endl;
    }
    return 0;
}


/*
P1591 阶乘数码
普及-

$ t \le 10 $ 且 $ n \le 1000 $

同样用一 int 一位十进制做模拟，只做数乘，每个进位 carry < 10000 用 int 不会溢出

最大是 1000! 估算一下数量级

$$
10! = 10^{6.56} \\

1000! < \Pi_{x=1}^{10} (100x)^{100} = 100^{10 \cdot 100}(\Pi_{x=1}^{10}x)^{100} < 10^{2 \cdot 10 \cdot 100 + 6.56 \cdot 100} = 10^{2656}
$$

于是最大取 2656 绝对够用

看起来开销也并不是很大的样子

可能的优化方案：

1. 缓存各种结果，下次计算若缓存命中则继续计算
2. int -> short


**可能的特判**: 0

Check 1: 10WA
哎我草，不带这样的，我忘把 N 改回 2656 了

Check 2: 10AC
也算秒了(?)

MetaMiku 20250926 01:23
*/