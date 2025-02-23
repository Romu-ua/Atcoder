#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    int n;
    cin >> x >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    map<char, char> f_map;
    for(int i = 0; i < 26; i++) {
        f_map['a' + i] = x[i];
    }
    
    map<char, char> g_map;
    for(int i = 0; i < 26; i++) {
        g_map[x[i]] = 'a' + i;
    }

    

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < s[i].length(); j++) {
            s[i][j] = g_map[s[i][j]];
        }
    }

    sort(s.begin(), s.end());

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < s[i].length(); j++) {
            s[i][j] = f_map[s[i][j]];
        }
    }
    
    for(int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }

    return 0;
}