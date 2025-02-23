#include <bits/stdc++.h>
using namespace std;

/*
方針：幅優先探索
グラフはノードの間に重みが存在し、これがTにあたる。
最小の時間を最短の経路の問題として捉えることができそう。
*/

int main() {
    int n;
    cin >> n;
    vector<int> k(n);
    vector<int> t(n);
    vector<vector<int>> a(n);
    int sum_k;

    for(int i = 0; i < n; i++) {
        int ti, ki;
        cin >> ti >> ki;
        sum_k += ki;
        t[i] = ti;
        k[i] = ki;
        a[i].resize(ki);
        for(int j = 0; j < ki; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> G(n);
    for(int i = 0; i < sum_k; i++) {
        int a;
        a = a[i][j];

    }




    
    vector<vector<int>> G(n);
    for(int i = 0; i < n; i++) {
        cin >> 
    }

    return 0;
}
//10:00 ~ 0:00 25:00 ~ 9:44時間がかかりすぎ
//方針はグラフを使った最短経路問題にした。