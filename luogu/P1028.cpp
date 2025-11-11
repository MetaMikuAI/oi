#include <iostream>
#include <vector>

using namespace std;

#define lli long long int

int main() {
    int n;
    cin >> n;

    vector<lli> vec = vector<lli>(n + 1, 0);

    vec[1] = 1;

    for (int i = 2; i <= n; i++) {
        lli sum = 0;
        for (int j = 1; j <= i / 2; j++) {
            sum += vec[j];
        }
        vec[i] = 1 + sum;
    }

    cout << vec[n] << endl;

    return 0;
}

/*
P1028 [NOIP 2001 普及组] 数的计算
普及-

f(1) = 1
f(n) = 1 + \sum_{r = 1}^{\floor(r / 2)} f(r)

Check 1: 20AC

MetaMikU 20251111 18:12
*/