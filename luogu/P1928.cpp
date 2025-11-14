#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <string>

using namespace std;
unordered_map<string, string> cache;

inline bool isDigest(char c) {
    return c >= '0' && c <= '9';
}

inline string repeat(string& x, int rep) {
    string res;
    for (int i = 0; i < rep; i++) {
        res += x;
    }
    return res;
}

string xzvf(const string& str, int rep = 1) {

    auto it = cache.find(str);
    if (it != cache.end()) {
        return repeat(it->second, rep);
    }
    
    string res;
    int len = str.size();
    for (size_t i = 0; i < len; i++) {
        char c = str[i];
        if (c == '[') {
            size_t start = i + 1;
            size_t end;
            // for (end = len - 1; end >= 0 && str[end] != ']'; end--); // one past the end
            int depth = 1;
            for (end = start; depth != 0; end++) {
                if (str[end] == '[') {
                    depth++;
                    continue;
                }
                if (str[end + 1] == ']') {
                    depth--;
                    continue;
                }
            }
            int r = 0;
            for (; isDigest(str[start]); start++) {
                r = r * 10 + str[start] - '0';
            }
            
            string s = str.substr(start, end - start);

            i = end;
            res += xzvf(s, r);
            continue;
        }
        res.push_back(c);
    }

    cache[str] = res;
    return repeat(res, rep);
}

int main() {
    cache.reserve(1024);

    string str;
    cin >> str;

    cout << xzvf(str) << endl;

    return 0;
}

/*
P1928 外星密码
普及/提高−

Check 1: AC MLE AC AC AC MLE MLE AC MLE AC

哦哦匹配搞错了

Check 2: 10AC

MetaMiku 20251114 11:57
*/