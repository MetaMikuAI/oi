#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int maxId = 0; // start from 0
    string maxVote = "0";

    for (int i = 0; i < n; i++) {
        string vote;
        cin >> vote;
        if (maxVote.size() < vote.size() ||
            (maxVote.size() == vote.size() && maxVote < vote)
        ){
            maxVote = vote;
            maxId = i;
        }
    }

    cout << maxId + 1 << endl << maxVote << endl;

    return 0;
}



/*
P1781 宇宙总统
普及−

直接利用字符串比较即可

Check 1: 5AC

MetaMiku 20250926 18:28
*/