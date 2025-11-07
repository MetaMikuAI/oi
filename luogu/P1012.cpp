#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<string> ns(n, "");

    for(int i = 0; i < n; i++) {
        cin >> ns[i];
    }

    sort(ns.begin(), ns.end(), [](const string& a, const string& b) {
        // return a > b; // Wrong
        return a + b > b + a;
    });

    for (int i = 0; i < n; i++) {
        cout << ns[i];
    }

    return 0;
}

/*
P1012 [NOIP 1998 提高组] 拼数
普及-

左对齐数字最大，用字符串比较最好

Check: WA 27AC WA
Wrong Answer.wrong answer On line 1 column 6, read 1, expected 3.
Wrong Answer.wrong answer On line 1 column 6, read 1, expected 3.

这俩不会是一个测试例吧

想到一个对

```cpp 
[](const string& a, const string& b) {
    return a > b;
}
```

不利的例子:

301, 3011, 2

3011 > 301 > 2

但是预期为

301 2 3011

Check 2: 29AC

做完了第二个题单 [【算法1-2】排序](https://www.luogu.com.cn/training/107#problems) 今天不做了

MetaMiku 20250926 22:10
*/