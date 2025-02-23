#include <bits/stdc++.h>
using namespace std;

int main() {
    string x;
    cin >> x;
    if(x.length() >= 3){
        if(x[x.length()-1] == '0' && x[x.length() - 2] == '0') {
            cout << "Yes" << endl;
            return 0;
        } else {
            cout << "No" << endl;
            return 0;
    }
    } else {   
        cout << "No" << endl;
        return 0;
    }

    return 0;
}