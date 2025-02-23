/*メモ
文字列の変換が問われている
下3桁を取り出して数字に変える

c++ならstioを使う

文字列のままでやってもよい、今回は0で埋められていて順番が崩れないから。
*/

#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int id = stoi(s.substr(3)); //str.substr(開始位置, 取り出す長さ)
    if (1 <= id && id <= 349 && id != 316) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
