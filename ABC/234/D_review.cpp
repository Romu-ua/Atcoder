#include <bits/stdc++.h>
using namespace std;

// 汎用的〜実装が楽

// 平衡２分探索木 : setを使うが、これにはk番目の要素を取る機能がついていない。強いけど実装が重い。

// segtree 実装が楽、定数倍で早い。制約、値の範囲が狭い時向け。
// 平衡２分探索木は回転という操作をする必要があるから、めんどくさい。
// segtreeは完全２分木の形を作っておいてあげて、マス目のような感じでやってあげる。
// ある区間内でk番目の値が取れる。
// segtreeのノードを２進数で表すと実装が楽。しかし、これを１から実装するのは厳しい。

// priority queue 2個
// kが固定の時。

// 線型でも解ける。(ならし)
// 私はこれで解いた。
// 答えが単調増加なのでオーターNにしかならない。

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 0; i < k-1; i++) {
        q.push(p[i]);
    }

    for (int i = k-1; i < n; i++) {
        while(q.size() > k) q.pop();
        cout << q.top() << endl;
    }
    return 0;
}