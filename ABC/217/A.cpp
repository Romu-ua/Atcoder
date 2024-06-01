#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    int size = min(s.length(), t.length());
    for(int i = 0; i < size; i++) {
        if(s[i] <= t[i]) continue;
        else {
            cout << "No" << endl; 
            return 0;
        }
    }
    
    if(s.length() <= t.length()) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}

//25:00 ~ 15: