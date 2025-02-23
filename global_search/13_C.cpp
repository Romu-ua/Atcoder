#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; ++i)
using namespace std;

int main () {
    int n;
    cin >> n;
    vector<int> p(n), q(n);
    rep(i,n) {
        cin >> p[i];
    }
    rep(i,n) {
        cin >> q[i];
    }

    //pとqが辞書順で何番目かを計算する。辞書順を作成した配列を作成して、その配列の要素と比較。
    vector<int> init_dict(n);
    rep(i,n) init_dict[i] = i+1; //辞書を昇順にした。ここが = i　になっていたから出来なかっただけ。考え方はあっていた。
    // vector<vector<int>> dict; 模範解答とここが違う。
    map<vector<int>, int> mp;
    int i = 0;
    do {
        mp[init_dict] = mp.size();
    } while(next_permutation(init_dict.begin(), init_dict.end()));
    cout << abs(mp[p]-mp[q]) << endl;
    return 0;
}