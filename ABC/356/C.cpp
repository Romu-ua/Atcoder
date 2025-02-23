#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> a(m);
    vector<char> r(m);
    for(int i = 0; i < m; i++) {
        int c;
        cin >> c;
        a[i].resize(c);
        for(int j = 0; j < c; j++) {
            cin >> a[i][j];
        }
        cin >> r[i];
    }

    //bit全探索かもしれない。
    int ans = 0;
    for(int bit = 0; bit < (1 << n); bit++){

        vector<int> subset;
        for(int i = 0; i < n; i++) {
            if(bit & (1 << i)) {
                subset.push_back(i);
            }
        }
        //これでbitがどこに立っているのかを取得した。
        //bitが立っている場所を正しい鍵の位置だとする。
        //正しい鍵の数がkより小さい時は答えにならない。
        if(subset.size()  < k) continue;

        bool flag = true;
        for(int i = 0; i < m; i++) {
            if(r[i] == 'x'){
                bool set_flag = true;
                set<int> setvec(a[i].begin(), a[i].end());
                for(int& elem : subset) {
                    if(setvec.find(elem+1) == setvec.end()) {
                        set_flag = false;
                    }
                }
                if(set_flag) {
                    flag = true;
                } else {
                    flag = false;
                }
            }
        }
        
        if(flag) {
            ans++;
        } else {
            continue;
        }
    }

    cout << ans << endl;

    return 0;
}