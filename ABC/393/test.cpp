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

    int double_cnt = 0;
    for (int i = 0; i < n; i++) {
        vector<int> to_erase;
        for (int elm : G[i]) {
            if (elm > i && G[elm].count(i)) {
                to_erase.push_back(elm);
            }
        }
        for (int elm : to_erase) {
            G[elm].erase(i);
            double_cnt++;
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
    return 0;
}
