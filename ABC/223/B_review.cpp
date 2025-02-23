#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    string mn = s, mx = s;
    for(int i = 0; i < n; i++) {
        mn = min(mn, s);
        mx = max(mx, s);
        //shiftする。
        // s += s[0]; s.erase(s.begin())
        //後ろにもう一個つなげて、substrでとる。でもいい。
        rotate(s.begin(), s.begin()+1, s.end()); //先頭、区切る位置、最後
    }

    cout << mn << endl;
    cout << mx << endl;

    return 0;
}