#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y[i];
    }
    string s;
    cin >> s;

    // 同じy座標にいる人を取り出して、その人が全て同じ方向を向いていたらセーフ、
    // また、左に行く人が左側にいて右に行く人が右側に行く場合もセーフ
    // 左に行く人が右側にいて、右に行く人が左側にいる場合だけアウト。

    // 初めて出現するインデックスをmpに追加して、2回目の出現ではvecに代入する
    // 書き方がわからない。
    unordered_map<int, int> mp;
    vector<pair<int, pair<int, int>>> vec;

    for (int i = 0; i < n; i++) {
        int y_value = y[i];
        if ()
    }







    return 0;
}