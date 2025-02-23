#include <bits/stdc++.h>
using namespace std;

vector<int> seen;

void dfs(vector<vector<int>> &G, int v) {
    seen[v] = true;
    for(auto next_v : G[v]) {
        if(seen[next_v]) continue;
        dfs(G, next_v);
    }
}

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        a[i]--;
    }

    vector<vector<int>> G(n);
    for(int i = 0; i < n; i++) {
        G[i].emplace_back(a[i]);
    }

    // for(int i = 0; i < n;i++) {
    //     for(auto next_v : G[i]) {
    //         cout << next_v << " ";
    //     }
    //     cout << endl;
    // }

    seen.assign(n, false);
    dfs(G, x-1);

    int ans = 0;
    for(int i = 0; i < n; i++) {
        if(seen[i]) ans++;
    }
    cout << ans << endl;

    return 0;
}