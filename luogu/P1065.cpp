#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define N 999 // 懒得调了，999 能过就这样吧

class Machine {
private:
public:
vector<bool> timeline;
    Machine() {
        timeline = vector<bool>(N, false);
    }
    ~Machine() {}

    bool isSpace(int start, int last) {
        if (start < 0 || start + last > timeline.size()) { // 检查边界
            return false;
        }
        for (int i = start; i < start + last; i++) {
            if (timeline[i] == true) {
                return false;
            }
        }
        return true;
    }

    int regist(int start, int last) { // 注册工件工序，自动分配加工时间段，返回结束时间戳
        int i, j;
        for (i = start; i < N; i++) {
            if (isSpace(i, last)) { 
                break;
            }
        }
        for (j = i; j < i + last; j++) {
            timeline[j] = true;
        }
        return j - 1;
    }

    int getMaxTime() {
        for (int i = N - 1; i >= 0; i--) {
            if (timeline[i]) {
                return i;
            }
        }
        return 0;
    }
};

class WorkPiece {
private:
public:
    vector<int> timeCost;
    vector<int> mId;
    int stage;
    int timeIs;
    WorkPiece(int m) {
        timeCost = vector<int>(m, 0);
        mId = vector<int>(m, 0);
        stage = 0;
        timeIs = 0;
    }
    ~WorkPiece() {}
};


int main() {
    int m, n;
    cin >> m >> n; // 机器数，工件数
    
    vector<int> order(m * n, 0);
    for (int i = 0; i < m * n; i++) {
        cin >> order[i];
        order[i]--; // 注意输入 id 对应下标减 1
    }
    
    vector<Machine> machines(m);
    vector<WorkPiece> workPieces(n, WorkPiece(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> workPieces[i].mId[j];
            workPieces[i].mId[j]--; // 注意输入 id 对应下标减 1
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> workPieces[i].timeCost[j];
        }
    }
    
    
    for (int i = 0; i < m * n; i++) {
        int wId = order[i];
        auto& w = workPieces[wId];
        w.timeIs = 1 + machines[w.mId[w.stage]].regist(w.timeIs, w.timeCost[w.stage]);
        w.stage++;
    }

// // 注释版：
//     for (int i = 0; i < m * n; i++) {   // 遍历要求顺序
//         int wId = order[i]; // 取要求顺序的工件 id 记为 wId
//         auto& w = workPieces[wId];  // 引用该工件
//         w.timeIs = machines[w.mId[w.stage]].regist(w.timeIs, w.timeCost[w.stage]) + 1;
//         //                    -------------  // 取当前工件的工序数所指定的机器
//         //                                           -------- 从该工件加工完后的时间戳开始
//         //                                                     ------------------- 取当前工件的工序数所指定的加工时间
//         //                                                                       ---- 工件加工完的时间戳的下一刻进入待加工状态
//         w.stage++; // 当前工序完成，进入下一工序
//     }

    int maxTime = 0;
    for (auto& machine : machines) {
        maxTime = max(maxTime, machine.getMaxTime());
    }

    cout << maxTime + 1; // 题面时间戳从 1 开始

    return 0;
}

/*
P1065 [NOIP 2006 提高组] 作业调度方案
普及/提高-

怎么又是又臭又长的题目描述

Check 1: 10AC
一遍过

OOP 用的还挺密集的，补一个注释版

MetaMiku 20250925 22:11
*/