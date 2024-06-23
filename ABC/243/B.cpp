#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    unordered_map<int, int> b_map;
    for (int i = 0; i < n; i++) {
        b_map[b[i]] = i;
    }

    int ans_1 = 0, ans_2 = 0;
    for (int i = 0; i < n; i++){
        if (b_map.find(a[i]) != b_map.end()) {
            int j = b_map[a[i]];
            if (j == i) {
                ans_1++;
            } else {
                ans_2++;
            }
        }
    }

    cout << ans_1 << endl;
    cout << ans_2 << endl;
    return 0;
}