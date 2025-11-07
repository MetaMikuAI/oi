#include <iostream>
#include <vector>
using namespace std;


int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<char>> map = vector<vector<char>>(N, vector<char>(M, '\x00'));

    for (int n = 0; n < N; n++){
        for (int m = 0; m < M; m++) {
            cin >> map[n][m];
        }
    }

    int min = 0x7fffffff;

    for (int i = 1; i <= N - 2; i++) {
        for (int j = 1; j <= N - i - 1; j++) {
            // int k = N - i - j;
            int count = 0;

            for (int x = 0; x < i; x++) {
                for (int y = 0; y < M; y++) {
                    if (map[x][y] != 'W') {
                        count++;
                    }
                }
            }
            for (int x = i; x < i + j; x++) {
                for (int y = 0; y < M; y++) {
                    if (map[x][y] != 'B') {
                        count++;
                    }
                }
            }
            for (int x = i + j; x < N; x++) {
                for (int y = 0; y < M; y++) {
                    if (map[x][y] != 'R') {
                        count++;
                    }
                }
            }
            
            if (min > count) {
                min = count;
            }
        }
    }

    cout << min << endl;

    return 0;
}

/*
P3392 涂条纹
普及-

俄罗斯国旗说是）

这代码不想简化了，反正一小题

Check 1: AC WA WA 4AC

Check 2: 7AC

忘了 loop 从 1 起一般得以 <= 收尾

MetaMiku 20251107 23:36
*/