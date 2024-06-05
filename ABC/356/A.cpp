#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, l, r;
    cin >> n >> l >> r;

    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        a[i] = i+1;
    }

    reverse(a.begin()+l-1, a.begin()+r);

    for(int i : a) {
        cout << i << " ";
    }

    return 0;
}