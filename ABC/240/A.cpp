#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    if (b-1 == a) {
        cout << "Yes" << endl;
        return 0;
    } 
    if (a == 1 && b == 10) {
        cout << "Yes" << endl;
        return 0;
    }

    cout << "No" << endl;
    return 0;
}