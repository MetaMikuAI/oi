#include <iostream>
#include <vector>
using namespace std;

int main() {
    int r, c, k;
    cin >> r >> c >> k;

    vector<vector<char>> map = vector<vector<char>>(r, vector<char>(c, '\x00'));
    for (int n = 0; n < r; n++){
        for (int m = 0; m < c; m++) {
            cin >> map[n][m];
        }
    }

    int count = 0;

    for (int x = 0; x < r; x++) {
        for (int y = 0; y < c; y++) {
            // direction: +x
            if (x + k <= r) {
                bool flag = true;
                for (int dx = 0; dx < k; dx++) {
                    if (map[x + dx][y] == '#') {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    count++;
                }
            }

            if (k == 1) { // 这太抽象了
                continue;
            }

            // direction: +y
            if (y + k <= c) {
                bool flag = true;
                for (int dy = 0; dy < k; dy++) {
                    if (map[x][y + dy] == '#') {
                        flag = false;
                        break;
                    }
                }
                if (flag) {
                    count++;
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}

/*
P3654 First Step (ファーストステップ)
普及-

Check 1: 2AC 2WA 6AC
看讨论说 k = 1 的特殊情况，确实是我考虑不周了
CHeck 2: 10AC

MetaMiku 20251107 23:58
*/