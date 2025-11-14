#include <iostream>
#include <string>

using namespace std;
#define lli long long int

lli r(const size_t len, const lli n) {
    if (n < len) {
        return n;
    }

    lli order = len;
    for (; order <= n; order <<= 1);
    order >>= 1;
    
    return r(len, (n + order - 1) % order);
}


int main() {
    string str;
    lli n;

    cin >> str >> n;
    n--;

    size_t len = str.size();


    lli res = r(len, n);
    cout << str[res] << endl;

    return 0;
}



/*
P3612 [USACO17JAN] Secret Cow Code S
普及-

Check 1: 10AC

循环群阶数为 len * 2 ^ k
反复减1模阶即可

MetaMiku 20251114 16:09
*/