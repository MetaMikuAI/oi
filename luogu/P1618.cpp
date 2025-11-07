#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


bool check(int a, int b, int c) {
    vector<bool> flag(10, false);
    
    flag[a/100] = true;
    flag[(a/10)%10] = true;
    flag[a%10] = true;

    flag[b/100] = true;
    flag[(b/10)%10] = true;
    flag[b%10] = true;

    flag[c/100] = true;
    flag[(c/10)%10] = true;
    flag[c%10] = true;

    if (flag [0]) { // 保证 不可取 0
        return false;
    }

    if (count(flag.begin(), flag.end(), true) != 9) { // 保证 全命中
        return false;
    }
    
    return true;
}

int main () {
    int A, B, C;
    cin >> A >> B >> C;

    if (A == 0) {
        cout << "No!!!" << endl; // 我觉得这可能是 Hack 数据
        return 0;
    }

    bool good = false;

    for (int a = 1; a <= 999; a++) {
        if (a % A != 0) {
            continue;
        }
        int b = a / A * B;
        int c = a / A * C;

        if (b > 999 || c > 999) {
            continue;
        }
        if (check(a, b, c)) {
            good = true;
            printf("%03d %03d %03d\n", a, b, c);
        }
    }

    if (!good) {
        cout << "No!!!" << endl;
    }

    return 0;
}


/*
P1618 三连击（升级版）

题目描述怪怪的，读了好几遍才懂

Check 1: 7AC

MetaMiku 20251107 21:06
*/