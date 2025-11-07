#include <iostream>
using namespace std;

char upper(char c) {
    if (c >= 'a' && c <= 'z') {
        return c - 'a' + 'A';
    }
    return c;
}
char lower(char c) {
    if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 'a';
    }
    return c;
}

char parse_p1(char c, int p1) {
    if (p1 == 1) { // 小写
        return lower(c);
    }
    if (p1 == 2) { // 大写
        return upper(c);
    }
    // if (p1 == 3) {
    return '*';
    // }
}

bool sameType(char a, char b) {
    return (isdigit(a) && isdigit(b)) || (islower(a) && islower(b));
}

string repeat(char c, int p2) {
    string str;
    for (int i = 0; i < p2; i++) {
        str.push_back(c);
    }
    return str;
}

int main () {
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    
    string str;
    cin >> str;

    int len = str.size();

    char c;
    char c2;

    for (int i = 0; i < len; i++) {
        if (str[i] == '-' && i >= 1) {
            c2 = str[i+1];
            if (!sameType(str[i-1], c2)) {
                cout << '-';
                continue;
            }
            if (c2 <= str[i-1]) { // 后小于等于前 -> 保留减号
                cout << '-';
                continue;
            }
            if (c2 == str[i-1] + 1) { // 后继 -> 去掉减号
                continue;
            }
            // 需要展开
            if (p3 == 1) { // 顺序
                for (char c3 = str[i-1] + 1; c3 < c2; c3++) {
                    cout << repeat(parse_p1(c3, p1), p2);
                }
            }
            if (p3 == 2) { // 逆序
                for (char c3 = c2 - 1; c3 > str[i-1]; c3--) {
                    cout << repeat(parse_p1(c3, p1), p2);
                }
            }
            continue;
        }
        cout << str[i];
    }


    return 0;
}

/*
P1098 [NOIP 2007 提高组] 字符串的展开
普及-

什么抽象题目，纯纯恶心人

Check 1: AC AC WA WA WA WA WA AC AC AC
有部分回显形如 Wrong Answer.wrong answer On line 1 column 1, read (ASCII 1), expected -.
看起来像又有遍历 ascii 字符表的问题
先加一个跳过首个 - 来看看

Check 2: AC AC WA AC WA WA AC AC AC AC
Wrong Answer.wrong answer On line 1 column 2, read `, expected -.
Wrong Answer.wrong answer On line 1 column 5, read 4, expected -.
Wrong Answer.wrong answer On line 1 column 2, read /, expected -.
推测是必须保持前后同类型，试一下

Check 3: 10AC
抽象题目

MetaMiku 20250925 17:17
*/