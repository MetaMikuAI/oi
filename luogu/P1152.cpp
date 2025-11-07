#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<bool> A(n, false); // 1 ... n-1 是需要的, 0 只占个位

    int r = 0, s = 0;
    cin >> s;
    while (cin >> r) {
        int t = abs(r - s);
        if (t >= n || A[t] == true) { // 应当严格无重复，若有重复则直接判定为 Not jolly // 加了个 t >= n || ，注意逻辑短路
            cout << "Not jolly" << endl;
            return 0;
        }
        A[t] = true;
        s = r;
    }

    cout << "Jolly" << endl; // n - 1 个元素各不重复则一定填满了 1 ... n-1 无需进一步校验

    return 0;
}

/*
P1152 欢乐的跳
入门

Check 1: 9AC RE
Runtime Error. Received signal 6: Aborted / IOT trap.
诶 SIGABRT 怎么这么坏
哦 A[t] == true 有越界，说得对

Check 2: AC AC RE AC AC AC RE AC RE RE
诶我靠，越来越离谱了，全是 SIGABRT 
我逻辑写反了呃呃

Check 3: 10AC
入门题不入门啊……

MetaMiku 20250926 21:19
*/