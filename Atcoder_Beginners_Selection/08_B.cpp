#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    set<int> d;

    for(int i = 0; i < N; i++) {
        int sub_d;
        cin >> sub_d;
        d.insert(sub_d);
    }

    // sort(d.rbegin(), d.rend());setってソートされた状態で出力される。

    // for(auto it = d.begin(); it != d.end(); it++) {
    //     cout << *it << " ";
    // }

    cout << d.size() << endl;
    return 0;
}