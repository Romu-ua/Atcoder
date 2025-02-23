#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int cnt = 0;

    cin >> s;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'B') {
            for (int j = 0; j < s.length(); j++) {
                if (i - j < 0 || i + j > s.length())
                    break;
                char j_i = s[i - j];
                char k_j = s[i + j];
                if (j_i == 'A' && k_j == 'C')
                    cnt++;
            }
        }
    }
    cout << cnt << endl;
}