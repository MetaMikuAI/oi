#include <iostream>
#include <vector>

using namespace std;

#define lli long long int

#include <bits/stdc++.h>

class BigNum {
public:
	using i64 = long long;
	static const int base = 1000000000; // 1e9
	static const int base_digits = 9;

	std::vector<int> a; // little-endian limbs
	int sign; // 1 or -1

	BigNum(): sign(1) {}

	BigNum(i64 v) { *this = v; }

	BigNum& operator=(i64 v) {
		sign = 1;
		if (v < 0) { sign = -1; v = -v; }
		a.clear();
		while (v > 0) {
			a.push_back(static_cast<int>(v % base));
			v /= base;
		}
		return *this;
	}

	BigNum(const std::string& s) { read(s); }

	BigNum& read(const std::string& s) {
		sign = 1;
		a.clear();
		int pos = 0;
		while (pos < (int)s.size() && isspace((unsigned char)s[pos])) ++pos;
		if (pos < (int)s.size() && (s[pos] == '-' || s[pos] == '+')) {
			if (s[pos] == '-') sign = -1;
			++pos;
		}
		for (int i = (int)s.size()-1; i >= pos; i -= base_digits) {
			int x = 0;
			int l = std::max(pos, i - base_digits + 1);
			for (int j = l; j <= i; ++j) x = x*10 + (s[j]-'0');
			a.push_back(x);
		}
		trim();
		return *this;
	}

	std::string toString() const {
		if (a.empty()) return "0";
		std::string s = (sign == -1 ? "-" : "");
		s += std::to_string(a.back());
		char buf[32];
		for (int i = (int)a.size()-2; i >= 0; --i) {
			// pad with zeros
			snprintf(buf, sizeof(buf), "%09d", a[i]);
			s += buf;
		}
		return s;
	}

	friend std::ostream& operator<<(std::ostream& os, const BigNum& v) {
		os << v.toString();
		return os;
	}

	bool isZero() const { return a.empty(); }

	void trim() {
		while (!a.empty() && a.back() == 0) a.pop_back();
		if (a.empty()) sign = 1;
	}

	// absolute comparison
	static int cmp_abs(const BigNum& a_, const BigNum& b_) {
		if (a_.a.size() != b_.a.size()) return a_.a.size() < b_.a.size() ? -1 : 1;
		for (int i = (int)a_.a.size()-1; i >= 0; --i)
			if (a_.a[i] != b_.a[i]) return a_.a[i] < b_.a[i] ? -1 : 1;
		return 0;
	}

	friend int cmp(const BigNum& a, const BigNum& b) {
		if (a.sign != b.sign) return a.sign < b.sign ? -1 : 1;
		int res = cmp_abs(a, b);
		return a.sign == 1 ? res : -res;
	}

	friend bool operator<(const BigNum& a, const BigNum& b) { return cmp(a,b) < 0; }
	friend bool operator>(const BigNum& a, const BigNum& b) { return cmp(a,b) > 0; }
	friend bool operator<=(const BigNum& a, const BigNum& b) { return cmp(a,b) <= 0; }
	friend bool operator>=(const BigNum& a, const BigNum& b) { return cmp(a,b) >= 0; }
	friend bool operator==(const BigNum& a, const BigNum& b) { return cmp(a,b) == 0; }
	friend bool operator!=(const BigNum& a, const BigNum& b) { return cmp(a,b) != 0; }

	BigNum operator-() const { BigNum res = *this; if (!res.isZero()) res.sign = -sign; return res; }

	// addition and subtraction helpers on absolute values
	static std::vector<int> add_abs_vec(const std::vector<int>& a, const std::vector<int>& b) {
		std::vector<int> res(std::max(a.size(), b.size()) + 1);
		long long carry = 0;
		for (size_t i = 0; i < res.size(); ++i) {
			long long sum = carry;
			if (i < a.size()) sum += a[i];
			if (i < b.size()) sum += b[i];
			res[i] = static_cast<int>(sum % base);
			carry = sum / base;
		}
		while (!res.empty() && res.back() == 0) res.pop_back();
		return res;
	}

	static std::vector<int> sub_abs_vec(const std::vector<int>& a, const std::vector<int>& b) {
		// assume |a| >= |b|
		std::vector<int> res(a);
		long long carry = 0;
		for (size_t i = 0; i < res.size(); ++i) {
			long long cur = res[i] - carry - (i < b.size() ? b[i] : 0);
			if (cur < 0) { cur += base; carry = 1; } else carry = 0;
			res[i] = static_cast<int>(cur);
		}
		while (!res.empty() && res.back() == 0) res.pop_back();
		return res;
	}

	BigNum operator+(const BigNum& v) const {
		if (sign == v.sign) {
			BigNum res;
			res.sign = sign;
			res.a = add_abs_vec(a, v.a);
			res.trim();
			return res;
		}
		if (cmp_abs(*this, v) >= 0) {
			BigNum res;
			res.sign = sign;
			res.a = sub_abs_vec(a, v.a);
			res.trim();
			return res;
		} else {
			BigNum res;
			res.sign = v.sign;
			res.a = sub_abs_vec(v.a, a);
			res.trim();
			return res;
		}
	}

	BigNum operator-(const BigNum& v) const { return *this + (-v); }

	BigNum operator*(const BigNum& v) const {
		if (isZero() || v.isZero()) return BigNum(0);
		BigNum res;
		res.sign = sign * v.sign;
		std::vector<long long> prod((size_t)a.size() + v.a.size());
		for (size_t i = 0; i < a.size(); ++i) {
			long long carry = 0;
			for (size_t j = 0; j < v.a.size() || carry; ++j) {
				long long cur = prod[i+j] + carry + 1ll * a[i] * (j < v.a.size() ? v.a[j] : 0);
				prod[i+j] = cur % base;
				carry = cur / base;
			}
		}
		res.a.resize(prod.size());
		for (size_t i = 0; i < prod.size(); ++i) res.a[i] = static_cast<int>(prod[i]);
		res.trim();
		return res;
	}

	// divmod: returns (quotient, remainder) where both are non-negative and sign is handled outside
	static std::pair<BigNum, BigNum> divmod(const BigNum& a1, const BigNum& b1) {
		if (b1.isZero()) throw std::runtime_error("division by zero");
		BigNum a = a1.abs();
		BigNum b = b1.abs();
		if (cmp_abs(a, b) < 0) return {BigNum(0), a};

		// normalize
		int n = a.a.size();
		int m = b.a.size();
		int shift = 0;
		long long f = base / (static_cast<long long>(b.a.back()) + 1);
		a = a.abs_mul_small(f);
		b = b.abs_mul_small(f);

		BigNum q;
		q.a.assign(n - m + 1, 0);
		BigNum r;
		r.a.assign(a.a.begin() + (n - (n - m + 1)), a.a.end());
		// We'll implement a simpler but reliable algorithm: long division by estimating quotient digits
		r.a.clear();
		for (int i = n - 1; i >= 0; --i) {
			r.a.insert(r.a.begin(), a.a[i]);
			if (!r.a.empty() && r.a.back() == 0) r.trim();
			int x = 0, l = 0, h = base-1;
			if (cmp_abs(r, b) >= 0) {
				// binary search quotient digit
				while (l <= h) {
					int mid = (l + h) >> 1;
					BigNum prod = b.abs_mul_small(mid);
					if (cmp_abs(prod, r) <= 0) { x = mid; l = mid + 1; }
					else h = mid - 1;
				}
				BigNum prod = b.abs_mul_small(x);
				r = r - prod;
			}
			if (i - (m - 1) >= 0) {
				q.a[i - (m - 1)] = x;
			} else if (i == 0 && q.a.empty()) {
				q.a.push_back(x);
			}
		}
		q.trim();
		// remainder: divide by f
		BigNum rem = r.abs_div_small(f);
		rem.trim();
		return {q, rem};
	}

	BigNum operator/(const BigNum& v) const {
		if (v.isZero()) throw std::runtime_error("division by zero");
		auto res = divmod(*this, v);
		BigNum q = res.first;
		q.sign = sign * v.sign;
		q.trim();
		return q;
	}

	BigNum operator%(const BigNum& v) const {
		if (v.isZero()) throw std::runtime_error("modulo by zero");
		auto res = divmod(*this, v);
		BigNum r = res.second;
		r.sign = sign;
		r.trim();
		return r;
	}

	// helpers: multiply by small int, divide by small int (absolute value)
	BigNum abs_mul_small(long long m) const {
		if (m == 0 || isZero()) return BigNum(0);
		BigNum res;
		long long carry = 0;
		res.a.resize(a.size());
		for (size_t i = 0; i < a.size(); ++i) {
			long long cur = carry + 1ll * a[i] * m;
			res.a[i] = static_cast<int>(cur % base);
			carry = cur / base;
		}
		while (carry) { res.a.push_back(static_cast<int>(carry % base)); carry /= base; }
		res.trim();
		return res;
	}

	BigNum abs_div_small(long long m) const {
		if (m == 0) throw std::runtime_error("division by zero");
		BigNum res;
		res.a.resize(a.size());
		long long carry = 0;
		for (int i = (int)a.size()-1; i >= 0; --i) {
			long long cur = a[i] + carry * base;
			res.a[i] = static_cast<int>(cur / m);
			carry = cur % m;
		}
		res.trim();
		return res;
	}

	BigNum abs() const { BigNum t = *this; t.sign = 1; return t; }

	// convenience operators with i64
	friend BigNum operator+(BigNum a, i64 b) { return a + BigNum(b); }
	friend BigNum operator-(BigNum a, i64 b) { return a - BigNum(b); }
	friend BigNum operator*(BigNum a, i64 b) { return a * BigNum(b); }
	friend BigNum operator/(BigNum a, i64 b) { return a / BigNum(b); }

private:
	// NOTE: The divmod implementation above is a simplified schoolbook estimator using binary search per digit.
	// It is easy to understand and robust for contest sizes, but not optimal for extremely large numbers.
};



int main() {
    int m, n;
    cin >> m >> n;

    vector<BigNum> vec = vector<BigNum>(n + 2, BigNum());

    vec[n] = 1;
    vec[n + 1] = 0;

    for (int i = n - 1; i >= m; i--) {
        vec[i] = vec[i + 1] + vec[i + 2];
    }

    cout << vec[m] << endl;

    return 0;
}

/*
P2437 蜜蜂路线
普及-

Check 1: AC AC WA WA WA
tmd 高精度

Check 1： 5AC

MetaMiku 20251114 12:25
*/