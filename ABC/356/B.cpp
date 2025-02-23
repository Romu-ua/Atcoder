#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for(int i = 0; i < m; i++) {
        cin >> a[i];
    }

    vector<int> y(m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {
            int x;
            cin >> x;
            y[j] += x;
        }
    }

    bool flag = true;
    for(int i = 0; i < m; i++) {
        if(y[i] < a[i]) {
            flag = false;
        }
    }

    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}