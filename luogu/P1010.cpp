#include <iostream>
#include <vector>

using namespace std;

void print(int n, bool isPow = true) {
    if (isPow) {
        if (n == 0) {
            cout << "2(0)";
            return;
        }

        if (n == 1) {
            cout << "2";
            return;
        }
    }
    else {
        if (n == 0) {
            cout << "0";
            return;
        }
        if (n == 1) {
            cout << "2(0)";
            return;
        }
    }

    vector<int> bin;
    for (int i = 0; i < 16; i++) {
        if (n & 0x1) {
            bin.push_back(i);
        }
        n >>= 1;
    }
    
    if (isPow) {
        cout << "2(";
    }

    int hw = bin.size();    // Hamming Weight

    for (int i = 0; i < hw - 1; i++) {
        print(bin[hw - i - 1]);
        cout << "+";
    }
    print(bin[0]);
    
    if (isPow) {
        cout << ")";
    }
}

int main() {
    int n;
    cin >> n;
    
    print(n, false);
    cout << endl;

    return 0;
}

/*
P1010 [NOIP 1998 普及组] 幂次方
普及-

max 20000
32768 = (1 << 15)

这个我写的是真的乱死了，没心情改
说起来 P1010 也真有二进制的感觉hh

Check 1: 5AC

MetaMiku 20251114 16:58
*/