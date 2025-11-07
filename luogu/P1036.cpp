#include <iostream>
#include <vector>
using namespace std;

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }

    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    
    return true;
}

int count;

void select(int k = 0, vector<int> selected = {}, vector<int> candidates = {}) {
    if (k == 0) {
        int sum = 0;
        for (int num : selected) {
            sum += num;
        }
        if (isPrime(sum)) {
            count++;
        }
        return;
    }
    
    for (int i = 0; i < candidates.size(); i++) {
        vector<int> new_selected = selected;
        vector<int> new_candidate = candidates;
        new_selected.push_back(candidates[i]);
        new_candidate.erase(new_candidate.begin(), new_candidate.begin() + i + 1);
        select(k - 1, new_selected, new_candidate);
    }
}

int main(){
    int n, k;
    cin >> n >> k;
    
    vector<int> candidates = vector<int>(n, 0);
    for (int i = 0; i < n; i++) {
        cin >> candidates[i];
    }

    count = 0;

    select(k, {}, candidates);

    cout << count << endl;
    return 0;
}

/*
P1036 [NOIP 2002 普及组] 选数
普及−

Check 1: 7AC
(?我还寻思得加一个素数缓存呢？难道太简单了不用？)

MetaMiku 20251107 21:48
*/