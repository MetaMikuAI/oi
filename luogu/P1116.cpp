#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> m(n, 0);
    
    int i;
    for (i = 0; i < n; i++) {
        cin >> m[i];
    }
    
    int count = 0;
    while (m.size()) {
        int minIdx = 0;
        for (i = 0; i < m.size(); i++) {
            if (m[minIdx] > m[i]) {
                minIdx = i;
            }
        }
        count += minIdx;
        m.erase(m.begin() + minIdx);
    }
    
    cout << count << endl;

    return 0;
}

/*
P1116 车厢重组
普及−

遍历数组找出最小元素的下标累加到 count 后擦除最小元素

Check 1: 10AC

MetaMiku 20250926 20:59
*/