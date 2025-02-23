#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    int ans = 1;
    for (int i = 1; i < n.size(); i++) {
        if (n.at(i) == '1') {
            continue;
        } else if (n.at(i)  == '+') {
            ans++;
        } else if (n.at(i) == '-') {
            ans--;
        }
    }
    cout << ans << endl;
    return 0;
}