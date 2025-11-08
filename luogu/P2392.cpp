#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define lli long long int

int fun(int n, const vector<int>& vec) {
    int ans = 0x7fffffff;
    for (int i = 0; i <= (1 << n) - 1; i++) {
        int h[2] = {0, 0};
        for (int j = 0; j < n; j++) {
            h[(bool)(i & (0x1 << j))] += vec[j];
        }
        ans = min(ans, max(h[0], h[1]));
    }
    return ans;
}

int main() {
    int s1, s2, s3, s4;
    cin >> s1 >> s2 >> s3 >> s4;

    vector<int> A = vector<int>(s1, 0);
    vector<int> B = vector<int>(s2, 0);
    vector<int> C = vector<int>(s3, 0);
    vector<int> D = vector<int>(s4, 0);

    for (int i = 0; i < s1; i++) {
        cin >> A[i];
    }
    for (int i = 0; i < s2; i++) {
        cin >> B[i];
    }
    for (int i = 0; i < s3; i++) {
        cin >> C[i];
    }
    for (int i = 0; i < s4; i++) {
        cin >> D[i];
    }


    int sum = fun(s1, A) + 
              fun(s2, B) + 
              fun(s3, C) + 
              fun(s4, D);

    cout << sum << endl;

    return 0;
}

/*
P2392 kkksc03考前临时抱佛脚
普及−

狂用位运算符

记录一个中断信号: SIGILL
原因: 函数返回值没写

.text:0000000000001283
.text:0000000000001283                         loc_1283:                               ; CODE XREF: fun(int,std::vector<int> const&)+1D↑j
.text:0000000000001283 8B 45 DC                                mov     eax, [rbp+n]
.text:0000000000001286 BA 01 00 00 00                          mov     edx, 1
.text:000000000000128B 89 C1                                   mov     ecx, eax
.text:000000000000128D D3 E2                                   shl     edx, cl
.text:000000000000128F 89 D0                                   mov     eax, edx
.text:0000000000001291 39 45 FC                                cmp     [rbp+i], eax
.text:0000000000001294 0F 8C 51 FF FF FF                       jl      loc_11EB
.text:000000000000129A 0F 0B                                   ud2
.text:000000000000129A                         ; } // starts at 11C9

程序在 ud2 处中断

Check 1: 10AC

MetaMiku 20251108 14:39
*/