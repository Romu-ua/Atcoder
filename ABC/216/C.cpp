#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;

    vector<char> v;

    while(true) {
        if(n == 0) break;

        if(1 == n%2) {
            n -= 1;
            v.emplace_back('A');
        } else {
            n /= 2;
            v.emplace_back('B');
        }
    }

    // cout << v.size() << endl;
    for(int i = v.size()-1; i >= 0; i--) {
        cout << v[i];
    }
    cout << endl;
    return 0;
}
//21分