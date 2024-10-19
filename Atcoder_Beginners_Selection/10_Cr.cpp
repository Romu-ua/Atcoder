#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    vector<string> ref = {"maerd", "remaerd", "esare", "resare"};
    reverse(s.begin(), s.end());
    while (true) {
        if (s.substr(0, 5) == ref[0]) {
            s.erase(s.begin(), s.begin() + 5);
        } else if (s.substr(0, 7) == ref[1]) {
            s.erase(s.begin(), s.begin() + 7);
        } else if (s.substr(0, 5) == ref[2]) {
            s.erase(s.begin(), s.begin() + 5);
        } else if (s.substr(0, 6) == ref[3]) {
            s.erase(s.begin(), s.begin() + 6);
        } else {
            cout << "NO" << endl;
            return 0;
        }
        if (s.size() == 0) {
            cout  << "YES" << endl;
            return 0;
        }
    }
    return 0;
}