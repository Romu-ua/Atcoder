#include <bits/stdc++.h>
using namespace std;

int main() {
    // 並び替えなので重複している文字がない、setで行うか
    int n, k; 
    cin >> n >> k;
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    set<int> st;
    for (int i = 0; i < k; i++) {
        st.insert(p[i]);
    }
    auto it = next(st.begin(), st.size()-k);
    cout << *it << endl;

    for (int i = k; i < n; i++) {
        // setの挿入はlog nでこのループがn-kかかるので(n-k)log nだけかかる。下のnextが結構掛かっている。
        // 大きいやつが入ってきた時だけ、itを右にずらせば良いのか。
        st.insert(p[i]); 
        // auto it = next(st.begin(), st.size()-k);
        if (p[i] > *it) {
            it++;
        }
        cout << *it << endl;
     }
    return 0;
}