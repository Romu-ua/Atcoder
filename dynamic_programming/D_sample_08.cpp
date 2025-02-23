#include <bits/stdc++.h>
using namespace std;

//実装の内容がむずいのでパス。説明を作る時に戻ってくる。






int main() {
    string A, B, C;
    while(cin >> A) {
        if (A == "0") break;
        cin >> B >> C;
        cout << solve(A, B, C) << endl;
    }

    return 0;
}