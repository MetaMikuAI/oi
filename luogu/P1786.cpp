#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

string positionTable[] = {
    "BangZhu",      // 0
    "FuBangZhu",    // 1
    "HuFa",         // 2
    "ZhangLao",     // 3
    "TangZhu",      // 4
    "JingYing",     // 5
    "BangZhong"     // 6
};

int getPosition(int rank) { // 从 0 数
    if (rank < 2) {
        return 2;
    }
    if (rank < 2 + 4) {
        return 3;
    }
    if (rank < 2 + 4 + 7) {
        return 4;
    }
    if (rank < 2 + 4 + 7 + 25) {
        return 5;
    }
    return 6;
}

class Player {
public:
    string name;
    int position;
    int banggong; // 帮贡 是啥玩意啊……
    int level; // 和 getPosition 的入参区分一下，没用 rank
    int id; // PK 说是））

    Player(int id, string name, int position, int banggong, int level): 
        id(id), name(name), position(position), banggong(banggong), level(level) {

    }
    ~Player() {}
    void print() {
        cout << name << ' ' << positionTable[position] << ' ' << level << endl;
    }
};

int main() {
    int n;
    cin >> n;

    vector<Player> players;
    vector<Player> fnckPlayers; // 有仨人搞特殊

    

    for (int i = 0; i < n; i++) {
        Player tmpPlayer(i, "", 0, 0, 0);
        string positionName;
        cin >> tmpPlayer.name >> positionName >> tmpPlayer.banggong >> tmpPlayer.level;
        if (tmpPlayer.name == "absi2011" || positionName == "BangZhu" || positionName == "FuBangZhu") {
            if (positionName == "BangZhu") {
                tmpPlayer.position = 0;
            }
            else {
                tmpPlayer.position = 1;
            }
            fnckPlayers.push_back(tmpPlayer);
        }
        else {
            players.push_back(tmpPlayer);
        }
    }
    int fnckNum = fnckPlayers.size(); // 谁知道哪个到时候会有问题……
    
    for (auto& p : fnckPlayers) { // 这仨应该可以直接打印了，不过不知道会不会帮主在其他人后面，看会不会爆 WA 吧
        p.print();
    }


    // ORDER BY players.banggong DESC
    stable_sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.banggong > b.banggong;
    });

    // UPDATE players.position
    for (int rank = 0; rank < n - fnckNum; rank++) {
        players[rank].position = getPosition(rank);
    }

    // ORDER BY players.id ASC
    stable_sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.id < b.id;
    });

    // ORDER BY players.level DESC
    stable_sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.level > b.level;
    });

    // ORDER BY players.position ASC
    stable_sort(players.begin(), players.end(), [](const Player& a, const Player& b) {
        return a.position < b.position;
    });

    for (auto& p : players) {
        p.print();
    }

    return 0;
}


/*
P1786 帮贡排序
普及/提高−

总是能在奇怪的地方怀念 sql 说是

需要一个稳定的排序，从后往前的关键字进行排序
sort 好像是快排，应该不太行，试试 stable_sort

对那几个特殊的人要特调，不进行排序，最后还得插进去，哎，真麻烦，这章就剩四道题了赶紧完事算了

用了三个 stable_sort

Check 1: AC AC AC AC WA AC WA WA AC WA
看有限的报错回显，那三个搞特殊的应该是没问题，是后面有问题

Check 2: 10AC
加了个主键(假的)，用于记录原始顺序
原先的输入顺序在按帮贡排序后被打乱了

MetaMiku 20250925 23:12
*/
