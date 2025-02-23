#include <bits/stdc++.h>
using namespace std;

/*
回文の判定
reverseした文字列の比較。かカーソルをつけて進める。

左につける　＝　右から消す。

1.両端にカーソルをつけて、両端がaなら内側に進める。
2.右がaなら右側を進める。
3.両端が同じなら進める。
1~3はl < rの時、
l >= rとなればok

例えばabcaの時、一緒じゃないので止まる。また2でも左にaが余ってたら進まない。のでl < rならNo
*/

int main() {
    string s;
    cin >> s;
    int n = s.length();
    int l = 0, r = n-1;
    while (l < r && s[l] == 'a' && s[r] == 'a') {
        ++l, --r;
    }
    while (l < r && s[r] == 'a') --r;
    while (l < r && s[l] == s[r]) {
        ++l, --r;
    }

    if (l >= r) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}