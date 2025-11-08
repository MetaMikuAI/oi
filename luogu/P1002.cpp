#include <iostream>
#include <vector>
#define lli long long int

using namespace std;

lli get(const vector<vector<lli>>& map, const lli n, const lli m, const lli x, const lli y) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return 0;
    }
    return map[x][y];
}

void set(vector<vector<lli>>& map, const lli n, const lli m, const lli x, const lli y, const lli t) {
    if (x < 0 || y < 0 || x >= n || y >= m) {
        return;
    }
    map[x][y] = t;
}

lli dp(vector<vector<lli>>& map, const lli n, const lli m, const lli x, const lli y) {
    lli cache = get(map, n, m, x, y);
    if (cache != -1) {
        return cache;
    }

    lli rx = dp(map, n, m, x + 1, y + 0);
    lli ry = dp(map, n, m, x + 0, y + 1);

    lli res = rx + ry;
    set(map, n, m, x, y, res);
    return res;
}


int main() {
    lli n, m, a, b;

    cin >> n >> m >> a >> b;
    n++;
    m++;

    vector<vector<lli>> map = vector<vector<lli>>(n, vector<lli>(m, -1));

    set(map, n, m, a + 0, b + 0, 0);
    set(map, n, m, a + 1, b + 2, 0);
    set(map, n, m, a - 1, b + 2, 0);
    set(map, n, m, a + 1, b - 2, 0);
    set(map, n, m, a - 1, b - 2, 0);
    set(map, n, m, a + 2, b + 1, 0);
    set(map, n, m, a + 2, b - 1, 0);
    set(map, n, m, a - 2, b + 1, 0);
    set(map, n, m, a - 2, b - 1, 0);
    
    set(map, n, m, n - 1, m - 1, 1);
    
    lli res = dp(map, n, m, 0, 0);

    cout << res << endl;

    return 0;
}

/*
P1002 [NOIP 2002 普及组] 过河卒
普及-

Check 1: AC AC WA WA AC
int -> long long int
Check 2; 5AC

MetaMiku 20251108 17:06
*/