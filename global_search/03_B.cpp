#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int counter = 0;
    int temp = 0;

    for (int i = 0; i < s.length(); i++ ){
        if((s[i] == 'A') or (s[i] == 'C') or (s[i] == 'G') or (s[i] == 'T')) {
            temp++;
            if(temp > counter) counter = temp;
        } else {
            temp = 0;
        }
    }

    cout << counter << endl;

    return 0;
}