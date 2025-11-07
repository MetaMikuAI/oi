#include <iostream>
#include <vector>

using namespace std;

#define N 10
#define lli long long int


void rec(bool only_count, int target_total, int* count_ptr, int depth = 0, vector<int> sel = {}) {
    if (depth == N) {
        int sum = 0;
        for (int x : sel){
            sum += x;
        }
        if (sum != target_total) {
            return;
        }

        if (only_count) {
            (*count_ptr)++;
            return;
        }

        for (int x : sel) {
            cout << x << " ";
        }
        cout << endl;
        
        return;
    }
    sel.push_back(0);
    for (int i = 1; i <= 3; i++) {
        sel[depth] = i;
        rec(only_count, target_total, count_ptr, depth + 1, sel);
    }
}


int main() {
    int n;
    cin >> n;


    if (n < N || n > 3 * N) {
        cout << 0 << endl;
        return 0;
    }

    int count = 0;
    rec(true, n, &count);
    cout << count << endl;

    rec(false, n, &count);

    return 0;
}

/*
P2089 烤鸡
普及−

好久没玩了，有点手生
编译时有几点出错，递归忘记闭合，数组越界，修好就 ok

Check 1: 10AC

MetaMiku 20251107 20:49
*/