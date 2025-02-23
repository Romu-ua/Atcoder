#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string a, b;
    cin >> a >> b;

    bool flag = false;
    ll i = a.length()-1, j = b.length()-1;
    while(true) {
        if(a[i] - '0' + b[j] - '0' >= 10) {
            // cout << a[i] << " " << b[j] << endl;
            flag = true;
        }
        if(i == 0 or j == 0) break;
        i--, j--;
    }

    if(flag) {
        cout << "Hard" << endl;
    } else {
        cout << "Easy" << endl;
    }

    return 0;
}
//20分でAB