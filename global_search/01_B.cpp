#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    bool flag = false;
    for(int i = 1; i <= 9; i++) {
        for (int j = 1; j <= 9 ; j++) {
            if(i*j == n) flag = true;
        }
    }

    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}