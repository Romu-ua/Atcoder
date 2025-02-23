#include <bits/stdc++.h>
using namespace std;

bool compare(string& a, string& b, unordered_map<char, int>& map) {
    for(int )
}

int main() {
    string x;
    int n;
    cin >> x >> n;
    vector<string> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    } 

    unordered_map<char, int> x_map;
    for(int i = 0; i < 26; i++) {
        x_map[x[i]] = i;
    }

    for(int i = 0; i < 26; i++) {
        cout << x_map['a' + i] << endl;
    }


    sort(s.begin(), s.end())


    return 0;
}