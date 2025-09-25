#include <iostream>
using namespace std;


void print(bool flag, int c, int e) {
    if (flag == false && c > 0) {
        cout << '+';
    }
    
    if (c > 1) {
        cout << c;
    }
    else if (c == 1) {
        // pass
    }
    else if (c == 0) {
        if (e == 0 && flag) {
            cout << '0';
        }
        return;
    }
    else if (c == -1) {
        cout << '-';
    }
    else { // c < -1
        cout << c;
    }

    if (e > 1) {
        cout << "x^" << e;
    }
    else if (e == 1) {
        cout << "x";
    }
    else { // e == 0
        if (c == 1 || c == -1) {
            cout << "1";
        }
    }
}

int main() {
    int n;

    cin >> n;

    bool flag = true;
    int c;
    while ((n >= 0) && (cin >> c)) { // 注意逻辑短路
        print(flag, c, n--);
        if (c != 0) {
            flag = false;
        }
    }

    cout << endl;

    return 0;
}



/*
P1067 [NOIP 2009 普及组] 多项式输出
普及 -

看起来没有任何难度，但是这个

> upd 2022.8.1：新增加一组 Hack 数据。

是什么意思？别搞我啊

注意一下各种边界条件就好

1. 首项单独判断，系数正且不为首项则预先补 `+` 号
2. 正系数 +1 0 -1 负系数
3. 0次 1次 高次
4. 特别注意 0 和 1 两个零次多项式

Check 1: AC WA AC*8 + AC
Wrong Answer.wrong answer Too long on line 1.

Check 2: AC WA AC*8 + AC
删掉了 cout << endl; 结果没变
难道有多余数据吗？

Check 2: AC WA AC*8 + AC
加了 n >= 0 校验，结果没变

Check 3: 11 AC
唉唉，还得看对拍脚本
错误例：

```
2 1 1 0
```

预期输出

```
x^2+x
```

错误输出 

```
x^2+x0
```

MetaMiku 20250925 16:33
*/