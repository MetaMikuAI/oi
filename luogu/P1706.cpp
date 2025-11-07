#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;


void select(vector<int> selected = {}, vector<int> candidates = {}) {
    if (candidates.size() == 0) {
        for (int num : selected) {
            cout << setw(5) << num;
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < candidates.size(); i++) {
        vector<int> new_selected = selected;
        vector<int> new_candidate = candidates;
        new_selected.push_back(candidates[i]);
        new_candidate.erase(new_candidate.begin() + i, new_candidate.begin() + i + 1);
        select(new_selected, new_candidate);
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> candidates = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        candidates[i] = i + 1;
    }

    select({}, candidates);

    return 0;
}
/*
P1706 全排列问题
普及-

Check 1: 10WA
哎我去 smqk
哦宽 5

Check 2: 10AC

MetaMiku 20251107 10:06
*/