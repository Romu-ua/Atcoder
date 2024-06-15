#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }

    // 模範解答はunion-findを使っている。がやっていることはサイクル検知と辺が３つ以上でているのかのチェック。
    // DFSでやる。

    bool flag = true;
    unordered_map<int, int> countMap_a;
    for (int ai : a) {
        countMap_a[ai]++;
        if (countMap_a[ai] >= 3) flag = false;
    }
    unordered_map<int, int> countMap_b;
    for (int bi : b) {
        countMap_b[bi]++;
        if (countMap_b[bi] >= 3) flag = false;
    }






        
    return 0;
}