#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const inline void fast_io() { ios_base::sync_with_stdio(false); cin.tie(0u); cout.tie(0u); }

int main() {
    fast_io();
    int n, k;
    cin >> n >> k;
    
    vector<int> numbers(n, 0);

    for (int i = 0; i < n; i++) {
        cin >> numbers[i];
    }

    nth_element(numbers.begin(), numbers.begin() + k, numbers.end());
    cout << numbers[k] << endl;

    return 0;
}


/*
P1923 【深基9.例4】求第 k 小的数
普及−

不让用 nth_element ? 我偏用
反正我还没怎么学过 STL

Check 1: AC AC AC TLE TLE
诶诶？！

Check 2: 5AC
差这么大？原来 1.06s 超时被压到 300ms
加了一个 fast_io 来自 [算竞笔记 - 题集/板子整理（C++）](https://mos9527.com/posts/cp/cp-templates/)
需要找时间研究一下 TODO

MetaMiku 20250926 18:05
*/