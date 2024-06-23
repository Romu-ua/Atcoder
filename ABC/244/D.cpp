#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<char> s(3);
    vector<char> t(3);
    for (int i = 0; i < 3; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < 3; i++) {
        cin >> t[i];
    }

    int cnt = 0;
    for (int i = 0; i < 3; i++) {
        if (s[i] == t[i]) cnt++;
    }
    if (cnt == 1) {
        cout << "No" << endl;
    } else {
        cout << "Yes" << endl;
    }
    return 0;
}