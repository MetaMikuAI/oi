#include <iostream>
#include <vector>
using namespace std;

#define lli long long int

int main() {
    vector<pair<lli, lli>> C11(1);
    vector<pair<lli, lli>> C21(1);

    char a;

    int index_11 = 0;
    int index_21 = 0;

    bool is_ended = false;

    while (!is_ended){
        cin >> a;
        
        switch (a) {
        case 'W':
            C11[index_11].first++;
            C21[index_21].first++;
            if (C11[index_11].first >= 11 && C11[index_11].first - C11[index_11].second >= 2) {
                index_11++;
                C11.push_back(pair<int, int>(0, 0));
            }
            if (C21[index_21].first >= 21 && C21[index_21].first - C21[index_21].second >= 2) {
                index_21++;
                C21.push_back(pair<int, int>(0, 0));
            }
            break;
        case 'L':
            C11[index_11].second++;
            C21[index_21].second++;
            if (C11[index_11].second >= 11 && C11[index_11].second - C11[index_11].first >= 2) {
                index_11++;
                C11.push_back(pair<int, int>(0, 0));
            }
            if (C21[index_21].second >= 21 && C21[index_21].second - C21[index_21].first >= 2) {
                index_21++;
                C21.push_back(pair<int, int>(0, 0));
            }
            break;
        case 'E':
            is_ended = true;
            break;
        default:
            break;
        }

    }
    
    for (auto& p : C11) {
        cout << (int)p.first << ":" << (int)p.second << endl; // . 先于 强制类型转换
    }
    cout << endl;
    for (auto& p : C21) {
        cout << (int)p.first << ":" << (int)p.second << endl;
    }
    

    return 0;
}

/*
P1042 [NOIP 2003 普及组] 乒乓球
普及−

check 1: 5AC 5WA
原来是漏条件了，“直到分差大于或者等于 2，才一局结束“
check 1: 5AC 5WA
怎么还是一模一样啊，ACM 改成 AC Missing 好了
check 3: 9AC 1WA
???
check 4: 10AC
改计分的数据类型 char -> long long int
真有人能打几百回乒乓球啊，搞不懂你们这群打 ACM 的

MetaMiku 20250924 19:23
*/