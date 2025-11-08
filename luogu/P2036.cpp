#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> data = vector<pair<int, int>>(n, pair<int, int>(0, 0));

    for (int i = 0; i < n; i++) {
        cin >> data[i].first >> data[i].second;
    }

    int ans = 0x7fffffff;
    for (int i = 1; i < (1 << n); i++) {
        int h[2] = {1, 0};
        for (int j = 0; j < n; j++) {
            if (i & (0x1 << j)) {
                h[0] *= data[j].first;
                h[1] += data[j].second;
            }
        }
        ans = min(ans, abs(h[0] - h[1]));
    }

    cout << ans << endl;

    return 0;
}

/*
P2036 [COCI 2008/2009 #2] PERKET
普及−

这好像是可以用 dp 吧？不管了

Check 1: 8AC

MetaMiku 20251108 15:00
*/