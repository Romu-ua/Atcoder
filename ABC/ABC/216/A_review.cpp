#include <bits/stdc++.h>
using namespace std;

int main () {
    string s;
    cin >> s;

    int n = s.size();
    int y = s[n-1] - '0';

    s = s.substr(0, n-2);

    if(y <= 2) {
        s+='-';
    } else if(y >= 7) {
        s+='-';
    }
    cout << s << endl;
    
    return 0;
}