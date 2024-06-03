#include <bits/stdc++.h>
using namespace std;

/*
方針として
分離、max計算。
この２つをすることは理解できている。
で分離の仕方だが、私はなぜが9!ではなくて10^9!だと勘違いしていた。確かに桁数の階乗なので9!だな。
で分離の仕方でnext_permutaitonも思いついていたのにーー！！
*/

int main() {
    string N;
    cin >> N;
    sort(N.begin(),N.end());
    int ans = 0;
    do {
        for(int i = 1; i < N.size(); i++) {
            string l = "", r = "";
            for(int j = 0; j < i; j++) l += N[j];
            for(int j = i; j < N.size(); j++) r += N[j];
            if(l[0] == '0' || r[0] == '0') continue;
            ans = max(ans, stoi(l) * stoi(r));
        }
    } while(next_permutation(N.begin(), N.end()));

    cout << ans << endl;
    return 0;
}