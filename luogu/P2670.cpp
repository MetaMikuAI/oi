#include <iostream>
#include <vector>
using namespace std;

int width, height;

int get_boom(vector<vector<int>>& gameMap, int x, int y) {
    if (x < 0 || x > width || y < 0 || y >= height) {
        return 0;
    }
    return gameMap[y][x] == -1;
}

inline int check_boom(vector<vector<int>>& gameMap, int x, int y) {
    return get_boom(gameMap, x - 1, y - 1) + 
           get_boom(gameMap, x - 1, y + 0) +
           get_boom(gameMap, x - 1, y + 1) +
           get_boom(gameMap, x + 0, y - 1) +
           get_boom(gameMap, x + 0, y + 1) +
           get_boom(gameMap, x + 1, y - 1) +
           get_boom(gameMap, x + 1, y + 0) +
           get_boom(gameMap, x + 1, y + 1);
}

int main() {
    cin >> height >> width;
    vector<vector<int>> gameMap(height, vector<int>(width, 0));

    char c;
    int x, y;

    int idx = 0;

    while (cin >> c) {
        switch (c) {
        case '?':
            idx++;
            break;
        case '*':
            y = idx / width;
            x = idx % width;
            gameMap[y][x] = -1;
            idx++;
            break;
        default:
            break;
        }

    }

    for (y = 0; y < height; y++) {
        for (x = 0; x < width; x++){
            if (gameMap[y][x] == -1) {
                cout << '*';
            }
            else {
                cout << check_boom(gameMap, x, y);
            }
        }
        cout << endl;
    }

    return 0;
}

/*
P2670 [NOIP 2015 普及组] 扫雷游戏

入门

check 1: 10 AC
一次通过，太不容易了
似乎输入截止会有 EOF，因此只要 while (cin >> c) 而不用手动控制输入接收量

MetaMiku 20250924 19:58
*/