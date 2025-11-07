#include <iostream>
#include <vector>
using namespace std;

const int table[5][5] = {
    { 0, -1, +1, +1, -1},
    {+1,  0, -1, +1, -1},
    {-1, +1,  0, -1, +1},
    {-1, -1, +1,  0, +1},
    {+1, +1, -1, -1,  0}
};

int main() {
    int n, na, nb;
    cin >> n >> na >> nb;    

    vector<int> aList(na, 0);
    vector<int> bList(nb, 0);
    
    int aScore = 0;
    int bScore = 0;

    int i;
    for (i = 0; i < na; i++) {
        cin >> aList[i];
    }
    for (i = 0; i < nb; i++) {
        cin >> bList[i];
    }

    for (i = 0; i < n; i++) {
        int a = aList[i % na];
        int b = bList[i % nb];
        switch (table[a][b]) {
        case +1:
            aScore++;
            break;
        case -1:
            bScore++;
        case 0:
            break;
        default:
            break;
        }
    }

    cout << aScore << ' ' << bScore << endl;
    
    return 0;
}


/*
P1328 [NOIP 2014 提高组] 生活大爆炸版石头剪刀布
普及-

直接开一个二维数组记录所有对局状态
循环还是用模运算来模拟
感觉可以秒

N 最大也 200，不太用考虑使用最小公倍数来优化

Check 1: 10AC
秒了

MetaMiku 20250924 22:34
*/