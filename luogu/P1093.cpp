#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Student {
public:
    int id;
    int chinese;
    int math;
    int english;
    int total;

    Student(int id, int chinese, int math, int english) {
        this->id = id;
        this->chinese = chinese;
        this->math = math;
        this->english = english;
    }

    int calcTotal() {
        total = chinese + math + english;
        return total;
    }
    
    ~Student() {}
    
};

int main() {
    int n;
    cin >> n;
    
    vector<Student> students;

    for (int i = 0; i < n; i++) {
        Student tmp(i + 1, 0, 0, 0);
        cin >> tmp.chinese >> tmp.math >> tmp.english;
        tmp.calcTotal();
        students.push_back(tmp);
    }

    // 默认已按学号排序

    stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b){
        return a.chinese > b.chinese;
    });

    stable_sort(students.begin(), students.end(), [](const Student& a, const Student& b){
        return a.total > b.total;
    });

    for (int i = 0; i < 5; i++) {
        cout << students[i].id << ' ' << students[i].total << endl;
    }
    
    return 0;
}

/*
P1093 [NOIP 2007 普及组] 奖学金
普及−

最多三百人，直接排就好了，和帮贡那题(P1786)一样的多重排序

Check 1: 10AC

MetaMiku 20250926 18:45
*/