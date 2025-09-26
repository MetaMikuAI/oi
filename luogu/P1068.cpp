#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class A { // 命名摆烂了
public:
    int id;
    int score;
    A() {
        id = 0;
        score = 0;
    }
    ~A() {}
};


int main() {
    int n, m;
    cin >> n >> m;
    m = m * 3 / 2;

    vector<A> a(n, A());

    int id, score;
    int i;
    for (i = 0; i < n; i++) {
        cin >> id >> score;
        a[i].id = id;
        a[i].score = score;
    }

    stable_sort(a.begin(), a.end(), [](const A& a, const A& b){
        return a.id < b.id;
    });

    stable_sort(a.begin(), a.end(), [](const A& a, const A& b){
        return a.score > b.score;
    });

    for (; a[m-1].score == a[m].score; m++);

    cout << a[m-1].score << ' ' << m << endl;
    
    for (i = 0; i < m; i++) {
        cout << a[i].id << ' ' << a[i].score << endl;
    }

    return 0;
}


/*
P1068 [NOIP 2009 普及组] 分数线划定
普及−

注意并列卡线的一并录取

Check 1: 10WA
我是sb

Check 2: 9WA 1AC
诶？？？
哦哦 我还没按报名号排

我怎么敢没看完样例就敢交的

Check 3: 10AC

MetaMiku 20250926 21:36
*/