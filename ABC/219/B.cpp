#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2, s3, t;
    cin >> s1 >> s2 >> s3 >> t;

    string ans;
    for(int i = 0; i < t.length(); i++) {
        if(t[i] == '1') {
            ans += s1;
        } else if(t[i] == '2') {
            ans += s2;
        } else {
            ans += s3;
        }
    }
    cout << ans << endl;
    return 0;
}
//1:33:13