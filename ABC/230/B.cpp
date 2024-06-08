#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    string t = "oxx";
    for(int i = 0; i < 3; i++) {
        t += t;
    }
    // cout << t << endl;

    if(t.find(s) == string::npos) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }

    return 0;
}

//15分でAB