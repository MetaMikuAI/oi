#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

void select(int r = 0, vector<int> selected = {}, vector<int> candidates = {}) {
    if (r == 0) {
        for (int num : selected) {
            cout << setw(3) << num;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < candidates.size(); i++) {
        vector<int> new_selected = selected;
        vector<int> new_candidate = candidates;
        new_selected.push_back(candidates[i]);
        new_candidate.erase(new_candidate.begin(), new_candidate.begin() + i + 1);
        select(r - 1, new_selected, new_candidate);
    }
}


int main() {
    int n, r;
    cin >> n >> r;

    vector<int> candidates = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        candidates[i] = i + 1;
    }

    select(r, {}, candidates);

    return 0;
}

/*
P1157 组合的输出
普及-

莫名其妙的题目，hyw

Check 1: 10AC

MetaMiku 20251107 22:02
*/