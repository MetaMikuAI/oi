#include <iostream>
#include <vector>
using namespace std;

#define N 501

void parse(string& src, vector<char>& dst) {
    int len = src.length();
    for (int i = 0; i < len; i++) {
        dst[N - 1 - i] = src[len - 1 - i];
    }
}

int add(vector<char>& A, vector<char>& B, vector<char>& C) {
    int carry = 0;
    for (int i = N - 1; i >= 0; i--) {
        int sum = A[i] - '0' + B[i] - '0' + carry;
        C[i] = (sum % 10) + '0';
        carry = sum / 10;
    }
    return carry; // OF 位，本题应该是用不上
}

void print(vector<char>& bigNum) {
    bool flag = false; // 前导 0 标志位
    for (int i = 0; i < N; i++) {
        if (bigNum[i] != '0' || flag) {
            cout << bigNum[i];
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
    vector<char> A(N, '0');
    vector<char> B(N, '0');
    vector<char> C(N, '0');
    
    cin >> strA;
    cin >> strB;
    parse(strA, A);
    parse(strB, B);
    add(A, B, C);
    print(C);

    return 0;
}

/*
P1601 A+B Problem（高精）
普及−

高精度？我可以说怀念 python 了吗？
什么时候 gmp 加入 cpp 标准库？

题目说

$$
a, b \le 10^{500}
$$

我要是一个字符当一个 char 的话，开销最坏是 500 Bytes，感觉很好承受
一个一个字符读的话，我不太清楚换行是 \r\n 还是 \n 啊，想办法绕过吧
不对，我想那么多干什么，直接扔进俩 string 不就好了

直接开俩 501 个 char 的 vector 然后慢慢算去吧
注意 **对齐** 、 `- '0'` 和 输出去 '0' 的问题

Check 1: 5AC

MetaMiku 20250924 20:52
*/