#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(0u); cout.tie(0u); }

int main() {
    fast_io();

    int n;
    cin >> n;
    
    vector<int> numbers(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end());
    numbers.erase(unique(numbers.begin(), numbers.end()), numbers.end());

    cout << numbers.size() << endl;
    for (int i = 0; i < numbers.size(); i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}



/*
P1059 [NOIP 2006 普及组] 明明的随机数
普及−

排序去重

Check 1: 10AC

unique 要和 erase 一起用才能去重

MetaMiku 20250926 18:16
*/