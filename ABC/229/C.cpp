#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, w;
    cin >> n >> w;
    vector<pair<long long,long long>> vec(n);

    // vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        vec[i].first = a, vec[i].second = b;
    }

    //vec[i].firstの要素でソートされる。降順にした。
    sort(vec.begin(), vec.end(), greater<>());

    // for(auto v : vec) {
    //     cout << v.first << " " << v.second << endl;
    // }

    long long ans = 0, w_sum = 0;
    for(auto v : vec) {
        if(v.second + w_sum > w) {
            long long r = w - w_sum;
            // cout << r << endl;
            ans += r * v.first;
            break;
        }
        w_sum += v.second;
        ans += v.second * v.first;
    }

    cout << ans << endl;

    return 0;
}
//40でABC