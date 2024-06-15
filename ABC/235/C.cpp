#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> k(q), x(q);
    for (int i = 0; i < q; i++) {
        cin >> k[i] >> x[i];
    }
    
    // 何の数字が、何番目までで、何個出現しているのか。のテーブル
    vector<map<int, int>> table(n);
    for (int i = 0; i < n; i++) {
        if (i > 0) {
            table[i] = table[i-1];
        }
        table[i][a[i]]++;
    }

    for (int i = 0; i < n; i++) {
        cout << "table[" << i << "]: ";
        for (auto& pair : table[i]) {
            cout << "{" << pair.first << ": " << pair.second << ")";
        }
        cout << endl;
    }

    for (int i = 0; i < q; i++) {
    }

    return 0;
}