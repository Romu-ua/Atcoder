#include <bits/stdc++.h>
using namespace std;


/*
方向性を持たせて、点を見た時に、角度が全て同じ方向になっていたら成立する。
それか、
一直線乗に並ぶものを弾く。
斜めの判定はベクトルが同じかどうかを使って判定する。
高校数学の判定法はkが存在するかどうか、だったな、懐かしい。
*/

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);

    for(int i = 0; i < n; i++) {
        cin >> vec[i].first >> vec[i].second;
    }

    int ans = 0;
    for(int i = 0; i < n-2; i++) {
        for(int j = i+1; j < n-1; j++) {
            for(int k = j+1; k < n; k++) {
                pair<int, int> vec_a, vec_b;
                vec_a.first = vec[i].first - vec[j].first;
                vec_a.second = vec[i].second - vec[j].second;
                vec_b.first = vec[i].first - vec[k].first;
                vec_b.second = vec[i].second - vec[k].second;
                //外積が0でベクトルは並行。
                if(vec_a.first*vec_b.second - vec_a.second*vec_b.first != 0){
                    ans++;
                }
            }

        }
    }

    cout << ans << endl;


    return 0;
}