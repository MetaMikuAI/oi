#include <iostream>
#include <vector>

using namespace std;

#define lli long long int

lli map[21][21][21];

lli w(lli a, lli b, lli c) {
    if (a <= 0 || b <= 0 || c <= 0) {
        return 1;
    }

    if (a > 20 || b > 20 || c > 20) {
        return w(20, 20, 20);
    }

    if (map[a][b][c] != -1LL) {
        return map[a][b][c];
    }

    lli ans;
    if (a < b && b < c) {
        ans = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
    }
    else {
        ans = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
    }

    map[a][b][c] = ans;

    return ans;
}


int main() {
    // vector<vector<vector<lli>>> map = vector<vector<vector<lli>>>(21, vector<vector<lli>>(21, vector<lli>(21, -1)));
    
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            for (int k = 0; k < 21; k++) {
                map[i][j][k] = -1;
            }
        }
    }

    lli a, b, c;
    while (cin >> a >> b >> c) {
        if (a == -1 && b == -1 && c == -1) {
            break;
        }
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
    }
    

    return 0;
}

/*
P1464 Function
普及-

Check 1: 7WA
忘了以 -1 结束了
Check 2: 7AC

MetaMiku 20251111 18:33
*/