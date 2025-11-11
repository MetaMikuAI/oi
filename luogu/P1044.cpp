#include <iostream>
#include <vector>

using namespace std;

#define lli long long int

int main() {
    int n;
    cin >> n;

    vector<vector<lli>> map = vector<vector<lli>>(n + 2, vector<lli>(n + 2, 0));
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0) {
                map[i][j] = 1;
                continue;
            }
            if (j == 0) {
                map[i][j] = map[i-1][j+1];
                continue;
            }
            map[i][j] = map[i][j-1] + map[i-1][j+1];
        }
    }

    cout << map[n][0] << endl;

    return 0;
}

/*
P1044 [NOIP 2003 普及组] 栈
普及-

Check 1: 5AC

太神奇了 dp 转移方程

MetaMiku 20251111 17:55
*/