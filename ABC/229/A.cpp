#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<string> s(2);
    for(int i = 0; i < 2; i++) {
        cin >> s[i];
    }

    for(int i = 0; i < 2; i++) {
        if(s[i][0] == '#' && s[i][1] == '#'){
            cout << "Yes" << endl;
            return 0;
        } 
    }
    if(s[0][0] == '#' && s[1][0] == '#'){
        cout << "Yes" << endl;
        return 0;
    }
    if(s[0][1] == '#' && s[1][1] == '#'){
        cout << "Yes" << endl;
        return 0;
    }
    
    cout << "No" << endl;
    return 0;
}