#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class P {
public:
    string name;
    int y;
    int m;
    int d;
    int birthday;
    P() {
        name = "";
        y = 0;
        m = 0;
        d = 0;
    }
    ~P() {}
    void update() {
        birthday = y * 10000 + m * 100 + d * 1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<P> ps(n, P());

    for(int i = 0; i < n; i++) {
        cin >> ps[i].name >> ps[i].y >> ps[i].m >> ps[i].d;
        ps[i].update();
    }

    reverse(ps.begin(), ps.end());
    stable_sort(ps.begin(), ps.end(), [](const P& a, const P& b){
        return a.birthday < b.birthday;
    });

    for (auto& p : ps) {
        cout << p.name << endl;
    }


    return 0;
}

/*
P1104 生日
普及-

Check 1: 4AC WA AC
Wrong Answer.wrong answer On line 39 column 1, read L, expected X.
哦忘用 stable_sort 了，光寻思速通了

ChecK 2: 6AC

MetaMiku 20250926 21:55
*/