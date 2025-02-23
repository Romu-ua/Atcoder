#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int counter = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i]=='A'){
            if(s[i+1]=='B') {
                if(s[i+2]=='C'){
                    counter++;
                }
            }
        }
    }
    cout << counter << endl;

    return 0;
}