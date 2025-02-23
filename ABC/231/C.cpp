#include <bits/stdc++.h>
using namespace std;

int main() {
    //２分探索
    int N, Q;
    cin >> N >> Q;
    vector<long long> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());
    for (int i = 0; i < Q; i++) {
        int x;
        cin >> x;
        cout << a.end() - lower_bound(a.begin(), a.end(), x) << endl;
    }
    return 0;
}