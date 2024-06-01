#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i].first;
        p[i].second = i;
    }

    sort(p.begin(), p.end());

    for(int i = 0; i < n; i++) {
        cout << p[i].second + 1 << endl;
    }

    return 0;
}

//6:00 ~ 0:01