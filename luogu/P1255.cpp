#include <iostream>
#include <vector>
#include <cstdint>
#include <iomanip>


class uBigInt {
    static const int _N = 1000;

    std::vector<uint32_t> v;

    uBigInt() {
        v.resize(_N, 0);
    }

public:
    uBigInt(int x) : uBigInt() {
        v[0] = x;
    }

    uBigInt operator+(const uBigInt& other) const {
        uBigInt result;
        uint32_t carry = 0;
        for (size_t i = 0; i < _N; ++i) {
            uint64_t sum = static_cast<uint64_t>(v[i]) + other.v[i] + carry;
            result.v[i] = sum % 1000000000;
            carry = sum / 1000000000;
        }
        return result;
    }

    friend std::ostream& operator<<(std::ostream& os, const uBigInt& num) {
        bool leading_zero = true;
        for (int i = _N - 1; i >= 0; --i) {
            if (leading_zero && num.v[i] == 0) {
                continue;
            }
            if (leading_zero) {
                os << num.v[i];
                leading_zero = false;
            } else {
                os << std::setw(9) << std::setfill('0') << num.v[i];
            }
        }
        if (leading_zero) {
            os << 0;
        }
        return os;
    }
};


using namespace std;

int main() {
    int n;
    cin >> n;

    uBigInt a(1);
    uBigInt b(1);
    uBigInt c(2);

    if (n == 1) {
        cout << b << endl;
        return 0;
    }
    if (n == 2) {
        cout << c << endl;
        return 0;
    }
    for (int i = 3; i <= n; ++i) {
        a = b;
        b = c;
        c = a + b;
    }
    cout << c << endl;

    return 0;
}



/*
P1255 数楼梯
普及-

Check 1: 3AC TLE 2AC 4TLE
哎现在出 TLE 了
得推导公式了吗

改成斐波那契了，要是再搞 TLE 就只能用矩阵快速幂了

Check 2: 3AC WA 2AC 4WA

坏了，得上高精度了

发烧了，太难搞了

ChecK 3: 10AC

MetaMiku 20251108 16:33
*/