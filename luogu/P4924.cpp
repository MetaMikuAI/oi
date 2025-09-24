#include <iostream>
#include <vector>
using namespace std;

int n, m; // 方阵大小 和 魔法施法次数

void rot_0(vector<vector<int>>& M, int x, int y, int r) { // 0 = 顺时针 即 (y, N - 1 - x) <- (x, y)
    int i, j;
    vector<vector<int>> N = M;

    for (i = -r; i <= r; i++) {
        for (j = -r; j <= r; j++) {
            M[x + j][y - i] = N[x + i][y + j];
        }
    }
}

void rot_1(vector<vector<int>>& M, int x, int y, int r) { // 1 = 逆时针 即 (x, y) <- (y, N - 1 - x)
    int i, j;
    vector<vector<int>> N = M;

    for (i = -r; i <= r; i++) {
        for (j = -r; j <= r; j++) {
            M[x + i][y + j] = N[x + j][y - i];
        }
    }
}


int main() {

    cin >> n >> m;

    vector<vector<int>> M(n, vector<int>(n, 0));


    // init matrix
    int i, j;
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            M[i][j] = i * n + j + 1;
        }
    }

    // input and rotate
    int x, y, r, z;
    while (cin >> x >> y >> r >> z) {
        if (z == 0) {
            rot_0(M, x - 1, y - 1, r);
        }
        else { // z == 1
            rot_1(M, x - 1, y - 1, r);
        }
    }

    // output
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            cout << M[i][j] << ' ';
        }
        cout << endl;
    }

    return 0;
}


/*
P4924 [1007] 魔法少女小Scarlet
普及-

旋转？这咋搞
我能想到的就是下标转置了
顺时针即 (y, N - 1 - x) <- (x, y)
逆时针即 (x, y) <- (y, N - 1 - x)

数据范围：
方阵最大 500*500 = 250000

注意：x 和 y 不是按下标 0 开始的

Check 1: 10AC

MetaMiku 20250924 22:17
*/