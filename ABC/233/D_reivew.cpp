#include <bits/stdc++.h>
using namespace std;

/*
区間の問題は累積和を考えると見通しが良くなる。
区間の和は区間の上から下を引いてあげれば良い。
区間の和が２ヶ所の差で求められる。
*/

int main() {
    int n;
    long long k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // s はindexの位置にあると思えばわかりやすい。一番最後は超えちゃってるけど。
    vector<long long> s(n+1);
    for (int i = 0; i < n; i++) {
        s[i+1] = s[i] + a[i];
    }

    map<long long, int> mp;
    long long ans = 0;
    for (int i = 0; i < n+1; i++) {
        ans += mp[s[i]];
        mp[s[i]+k]++;
    }
    cout << ans << endl;
    return 0;
}