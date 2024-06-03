#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    if(n.size() < 1) {
        n = "0000" + n;
    } else if(n.size() < 2) {
        n = "000" + n;
    } else if(n.size() < 3) {
        n = "00" + n;
    } else if(n.size() < 4) {
        n = "0" + n;
    } else {
    }
    cout << n << endl;

    return 0;
}