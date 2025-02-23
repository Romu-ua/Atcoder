#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<pair<string, string>> set_n;
    for(int i = 0; i < n; i++) {
        string s, t;
        cin >> s >> t;
        set_n.insert(make_pair(s, t));
    }
    if(set_n.size() != n) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
//10:05


// int main() {
//     int n;
//     cin >> n;
//     set<string> s;
//     set<string> t;
//     for (int i = 0; i < n; i++) {
//         string si, ti;
//         cin >> si >> ti;
//         s.insert(si), t.insert(ti);
//     }
//     if (s.size() != n && t.size() != n) {
//         cout << "Yes" << endl;
//     } else {
//         cout << "No" << endl;
//     }
//     return 0;
// }