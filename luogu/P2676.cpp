#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, b;
    cin >> n >> b;

    vector<int> cows(n, 0);

    int i;

    for (i = 0; i < n; i++) {
        cin >> cows[i];
    }

    sort(cows.begin(), cows.end(), [](const int a, const int b) {
        return a > b;
    });
    
    for (i = 0; b > 0; i++) {
        b -= cows[i];
    }

    cout << i << endl;

    return 0;
}

/*
P2676 [USACO07DEC] Bookshelf B
普及−

Check 1: 20AC

MetaMiku 20250926
*/