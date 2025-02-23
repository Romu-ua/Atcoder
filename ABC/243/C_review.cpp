#include <bits/stdc++.h>
using namespace std;

/*
同じy座標において、xが小さい順に並べた時、
RLという部分文字列が存在しているとぶつかり、そうでないときはぶつからない。

y座標が同じ人をとる　→map<int, int>
x座標が小さい順にRLを並べる ->vector<pair<int, char>>
これがすぐ思いつくようになりたい。
*/

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }

    string s;
    cin >> s;

    // 人をy座標ごとに分類
    // これパッと思いつかなかったな。y座標、人の番号
    map<int, vector<int>> mp;
    for (int i = 0; i < n; i++) {
        mp[y[i]].push_back(i);
    }

    for (auto p : mp) {
        vector<int> ids = p.second;
        vector<pair<int, char>> ps;
        for (int i : ids) {
            // 人の番号を使って、その人のx座標と向きをpair型で持っておく。
            // x座標順にRLを持っておきたいから。これ思いつかん。実装が少し重いとACできんな。練習せんと。
            ps.emplace_back(x[i], s[i]);
        }
        sort(ps.begin(), ps.end());
        int len = ps.size();
        for (int i = 0; i < len-1; i++) {
            if (ps[i].second == 'R' && ps[i+1].second =='L'){
                cout << "Yes" << endl;
                return 0;
            }
        }
    }

    cout << "No" << endl;
    return 0;
}