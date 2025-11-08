#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define N 100000
#define MAX_LEN 5000
#define MOD 1000000007
const inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(0u); cout.tie(0u); }
#define lli long long int

inline lli c2(int n) {
    return (lli)n * (lli) (n - 1) / 2;
}


int main() {
    fast_io(); 
    vector<int> sticks = vector<int>(MAX_LEN + 1, 0); // 下标为 长度，值为 数量

    int n;
    cin >> n;


    for (int i = 0; i < n; i++) {
        int l;
        cin >> l;
        sticks[l]++;
    }

    lli count = 0;

    for (int l = 1; l <= MAX_LEN; l++) {
        if (sticks[l] < 2) {
            continue;
        }
        lli sum = 0;
        if ((l & 0x1)  == 0) {
            sum += c2(sticks[l >> 1]);
        }
        for (int r = 1; r * 2 < l; r++) {
            sum += sticks[r] * sticks[l - r];
        }
        count += sum * c2(sticks[l]);
    }

    cout << count % MOD << endl;

    return 0;
}

/*
P3799 妖梦拼木棒
普及/提高−

Check 1: 10WA
Check 2: 10WA
Check 3: 10WA
什么玩意

Check 4: 10AC
哎我是傻*

r < l / 2 右侧掉精度
改成 r * 2 < l 就好了

MetaMiku 20251108 13:24
*/