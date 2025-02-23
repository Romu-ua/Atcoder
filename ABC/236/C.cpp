#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    vector<string> t(m);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> t[i];
    }
    sort(t.begin(), t.end());
    int j = 0;
    bool flag = false;
    // Nlognであれば間に合うので2文探索する。
    for (int i = 0; i < n; i++) {
        flag = binary_search(t.begin(), t.end(), s[i]);
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}