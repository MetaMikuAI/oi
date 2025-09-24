#include <iostream>
#include <vector>
using namespace std;

int main (){
    int n, m; // 小人的个数 指令的条数
    cin >> n >> m;

    // pair<bool, string> // 朝向, name
    vector<pair<bool, string>> cir(n, pair<bool, string>(0, ""));

    bool dir;
    string name;

    for (int i = 0; i < n; i++) {
        cin >> dir >> name;
        cir[i].first = dir;
        cir[i].second = name;
    }

    int idx = 0;
    int len = 0;
    while (cin >> dir >> len) {
        if (dir ^ cir[idx].first) {
            idx += len;
        }
        else {
            idx += n - len;
        }
        idx %= n;
    }
    
    cout << cir[idx].second << endl;

    return 0;
}

/*
P1563 [NOIP 2016 提高组] 玩具谜题
普及−

Check 1: 20AC
一次通过，有点理解为什么打 ACM 那帮大佬不喜欢给变量起名了，这起名比想算法费劲多了……

这道题个人感觉想到用异或运算符和模运算(模拟环)就简单很多了

MetaMiku 20250924 20:19
*/