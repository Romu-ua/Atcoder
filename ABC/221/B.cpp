#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    
    if(s == t) {
        cout << "Yes" << endl; 
        return 0;
    }

    int miss = 0;
    int pair = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != t[i] && s[i+1] != t[i+1] && s[i] == t[i+1] && s[i+1] == t[i]) pair++;
        if(s[i] != t[i]) miss++;
    }
    if(pair == 1 && miss == 2) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}