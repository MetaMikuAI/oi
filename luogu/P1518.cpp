#include <iostream>
#include <vector>
using namespace std;
#define WIDTH 10
#define HEIGHT 10



const int directions[4][2] {
    {-1, 0},
    {0, 1},
    {1, 0},
    {0, -1}
};


bool check(int x, int y, vector<pair<int, int>>& hinders) {
    if (x < 0 || x >= HEIGHT || y < 0 || y >= WIDTH) {
        return false;
    }
    for (auto& hinder : hinders) {
        if (x == hinder.first && y == hinder.second) {
            return false;
        }
    }
    return true;
}


class Player {
public:
    int dir;
    int x; // 懒得写 getter 了，就放 public 吧
    int y;

    Player(int x, int y) {
        this->x = x;
        this->y = y;
        this->dir = 0;
    }

    void step(vector<pair<int, int>>& hinders) {
        int x_ = x + directions[dir][0];
        int y_ = y + directions[dir][1];
        if (check(x_, y_, hinders)){
            x = x_;
            y = y_;   
        }
        else {
            dir = (dir + 1) % 4;
        }
    }

    ~Player(){}
};


vector<vector<int>> history(0, vector<int>(6, 0));


bool stuck(Player& p1, Player& p2) {
    vector<int> p(6, 0);
    p[0] = p1.x;
    p[1] = p1.y;
    p[2] = p1.dir;
    p[3] = p2.x;
    p[4] = p2.y;
    p[5] = p2.dir;


    for (auto& h : history) {
        if (h == p) {
            return true;
        }
    }
    history.push_back(p);
    return false;
}


int main() {
    vector<pair<int, int>> hinders;
    Player cow(0, 0);
    Player farmer(0, 0);


    string line;
    int i, j;
    for (i = 0; i < 10; i++) {
        cin >> line;
        for (j = 0; j < 10; j++) {
            // switch 真的好丑啊
            switch (line[j]) {
            case '*':
                hinders.push_back(pair<int, int>(i, j));
                break;
            case 'C':
                cow = Player(i, j);
                break;
            case 'F':
                farmer = Player(i, j);
                break;
            default:
                break;
            }
        }
    }
    
    for (int i = 1;; i++) {
        cow.step(hinders);
        farmer.step(hinders);
        if (cow.x == farmer.x && cow.y == farmer.y){
            cout << i << endl;
            return 0;
        }
        if (stuck(farmer, cow)) { // 死局
            cout << 0 << endl;
            return 0;
        }
    }
    return 0;
}


/*
P1518 [USACO2.4] 两只塔姆沃斯牛 The Tamworth Two
普及/提高-

终于有 `普及/提高-` 了说


一个 directions 记录四个方向
一个函数 step 用于模拟步进
只记录障碍物而非整个地图
三个运动物体应该不用抽象为 class
说是两头牛但实际上只模拟一个对象

难点可能是如何判断死局（？
一共有六个变量的状态机，看是否有重复状态即可

不知道会不会超时啊，一旦有的很离谱怎么办……

Check 1: 9AC
过了，而且都是 4ms，内存开销最大的测试例也只有 1.04MB，可能还是题简单不要求优化吧（？

睡觉！

MetaMiku 20250925 12:12
*/