#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    int m;
    cin >> n >> m;

    vector<short> votes(m, 0);
    for (int i = 0; i < m; i++) {
        cin >> votes[i];
    }
    
    sort(votes.begin(), votes.end(), [](const short a, const short b) {
        return a < b;
    });
    
    for (int i = 0; i < m; i++) {
        cout << votes[i] << ' ';
    }
    cout << endl;
}

/*
P1271 【深基9.例1】选举学生会
普及-

sort

欸不是，我 gdb 怎么爆了

Check 1: 正在等待编译……
？？？
Check 1: 5AC
为什么这么久啊……
开销：
编程语言    C++14 (GCC 9) O2
代码长度    484B
用时        429ms
内存        2.46MB

MetaMiku 20250926 11:04
*/