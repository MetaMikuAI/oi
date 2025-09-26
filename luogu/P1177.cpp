#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<int> numbers(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> numbers[i];
    }

    sort(numbers.begin(), numbers.end(), [](const int a, const int b) {
        return a < b;
    });
    
    for (int i = 0; i < N; i++) {
        cout << numbers[i] << ' ';
    }
    cout << endl;
}

/*
P1177 【模板】排序
普及-

虽说是模板题，但是我觉得还是要用 sort 好一点
毕竟我还不是只要会怎么注入 lambda 不就好了（？

Check 1: WA WA WA WA AC
哎哎忘改 short 为 int 了

Check 2: 5AC

MetaMiku 20250926 11:06
*/