#include <iostream>
using namespace std;

#define lli long long int

int main() {
    lli n, m;
    cin >> n >> m;

    lli r = 0, s = 0; // 长方形, 正方形

    lli a, b;
    a = max(m, n);
    b = min(m, n);

    for (; b > 0; b--, a--) {
        s += a * b;
    }

    cout << s << ' ';

    
    a = max(m, n);
    b = min(m, n);

    lli ra = 0, rb = 0;

    for (; a > 0; a--) {
        ra += a;
    }
    for (; b > 0; b--) {
        rb += b;
    }
    r = ra * rb - s;

    cout << r << endl;

    return 0;
}


/*
P2241 统计方形（数据加强版）
普及−

Check 1: AC AC AC WA WA WA WA WA AC AC

改 int 为 long long int

Check 2: 10AC

MetaMiku 20250929 19:26
*/
