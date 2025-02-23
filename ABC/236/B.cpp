#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < 4*n-1; i++) {
        int a;
        cin >> a;
        a--;
        mp[a] += 1;
    }

    for (int i = 0; i < n; i++) {
        if (mp[i] != 4) {
            cout << i+1 << endl;
            return 0;
        }
    }
    return 0;
}