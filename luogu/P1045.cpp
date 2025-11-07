#include <iostream>
#include <vector>
using namespace std;


#define N 500
const double log10_2 = 0.3010299956639812;


class BigNum {
private:
    vector<int> v;
public:
    BigNum() {
        v = vector<int>(2 * N + 1, 0);
    }
    void set(int i, int a) {
        v[i] = a;
    }
    int get(int i) {
        return v[i];
    }


    BigNum operator*(const BigNum other) {
        BigNum res;
        for (int i = 2 * N; i >= N; i--) {
            for (int j = 2 * N; j >= N; j--) {
                if (i + j - 2 * N >= N) {
                    res.v[i + j - 2 * N] += this->v[i] * other.v[j];
                }
            }
        }
        
        for (int i = 2 * N; i > N; i--) {
            res.v[i - 1] += res.v[i] / 10;
            res.v[i] %= 10;
        }
        
        return res;
    }

    static BigNum power(const BigNum& base, int exp) {
        BigNum result;
        result.set(2 * N, 1);
        
        BigNum current_base = base;
        
        while (exp > 0) {
            if (exp & 1) {
                result = result * current_base;
            }
            current_base = current_base * current_base;
            exp >>= 1;
        }
        
        return result;
    }

    void printLastN() {
        for (int i = N + 1; i <= 2 * N; i++) {
            cout << v[i];
            if (i % 50 == 0) {
                cout << endl;
            }
        }
        cout << endl;
    }

    ~BigNum() {}
};


int main() {
    int P;
    cin >> P;

    int len = (int)(log10_2 * P) + 1;
    cout << len << endl;


    BigNum a;
    a.set(2 * N, 2);

    a = BigNum::power(a, P);
    a.set(2 * N, a.get(2 * N) - 1);
    a.printLastN();

    return 0;
}


/*
P1045 [NOIP 2003 普及组] 麦森数
普及/提高−

计算 2^P - 1

还要求位数

位数直接 ceil(P \cdot log_{2}{10}) 就好

后五百位用快速幂 + 模意义即可

对于 -1，2的整次幂的十进制个位永远是 2 4 8 6 不涉及减法借位

TODO: 
另外有时间得写一个高精度数学板子了，大概
写完后重写这题

Check 1: 10AC

MetaMiku 20250926 10:52
*/