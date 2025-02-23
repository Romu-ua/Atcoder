#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, t;
    cin >> s >> t;

    set<int> num_set;
    for (int i = 0; i < s.length(); i++) {
        int s_num = s[i] - 'a';
        int t_num = t[i] - 'a';
        int distance = (s_num-t_num + 26) % 26;
        num_set.insert(distance);
    }

    if (num_set.size() == 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}
// ABで分