#include <bits/stdc++.h>
using namespace std;
using Graph = vector<set<int>>;

int main() {
    int n, m;

    cin >> n >> m;
    Graph G(n);
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        G[a].insert(b);
    }

    // for (int i = 0; i < n; i++) {
    //     for (int elm : G[i]) {
    //         cout << elm;
    //     }
    //     cout << endl;
    // }

    int double_cnt = 0;
    vector<int> to_erase;
    for (int i = 0; i < n; i++) {
        for (int elm : G[i]) {
            if (G[elm].count(i)) {
                double_cnt++;
                to_erase.push_back(i);
            }
        }
        for (int v: to_erase) {
            G[v].erase(i);
        }
    }
    int next_cnt = 0;
    for (int i = 0; i < n; i++) {
        if (G[i].count(i)) {
            next_cnt++;
            G[i].erase(i);
        }
    }
    cout << next_cnt + double_cnt << endl;
}