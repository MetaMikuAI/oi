#include <iostream>
#include <vector>
using namespace std;

int index(int x, const vector<bool>& fingers) {
    int idx = 0;
    for (int i = 0; i < x; i++) {
        if (fingers[i]) {
            idx++;
        }
    }
    return idx;
}


int main() {
    int N, M;
    cin >> N >> M;

    vector<int> src = vector<int>(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> src[i];
        src[i]--;
    }

    vector<bool> fingers = vector<bool>(N, true); // 空闲`手指`表
    vector<int> number = vector<int>(N, 0); // 变进制数
    
    // decode
    for (int i = 0; i < N; i++) {
        number[i] = index(src[i], fingers);
        fingers[src[i]] = false;  // 标记为 已使用
    }
    
    // add M
    number[N - 1] += M;
    int c = 0;
    for (int i = 1; i <= N; i++) {
        number[N - i] += c;
        c = number[N - i] / i;
        if (c == 0) {
            break;
        }
        number[N - i] = number[N - i] % i;
    }


    // encode
    vector<int> candidates = vector<int>(N, 0); // 候选数
    vector<int> ans = vector<int>(N, 0); // answer
    for (int i = 0; i < N; i++) {
        candidates[i] = i;
    }

    for (int i = 0; i < N; i++) {
        int x = number[i];
        ans[i] = candidates[x];
        candidates.erase(candidates.begin() + x, candidates.begin() + x + 1);
    }

    // print
    for (int i = 0; i < N - 1; i++) {
        cout << ans[i] + 1 << ' ';
    }
    cout << ans[N - 1] + 1 << endl;

    return 0;
}

/*
P1088 [NOIP 2004 普及组] 火星人
普及-

好长的题目！

本题重点是如何把 `数` 编码为 `排列`，以及如何将 `排列 解码为 `数` 

对于序列 $(x_1, x_2, \cdots. x_n)$

可以如此解码：

$$
D_{ecode}(x_1, x_2, \cdots. x_n) = 1 + \sum I_{ndex}(x_i) * (n-i)!
$$

其中 $I_{ndex}(x_i)$ 表示从 $\{1, 2, \cdots, N\}$ 中去除 $\{x_1, x_2, \cdots, x_{i_1}\}$ 后 $x_i$ 在其中的第 $I_ndex(x_i)$ 小 (从 0 计数)

由于 $N_{max} = 10000$

无需给出绝对的解码值，给出中间量即可

但是社区的 `next_permutation` 是什么玩意，还有这种东西


Check 1: AC 9WA
?
true false 没统一
那我怎么过的样例hhh

Check 2: 10AC

MetaMiku 20251107 23:01
*/