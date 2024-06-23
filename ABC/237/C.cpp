#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    int start = 0;
    while(start < s.size() && s[start] == 'a') {
        start++;
    }
    string s_trimmed = s.substr(start);

    int last = s_trimmed.length();
    while (last > 0 && s_trimmed[last-1] == 'a') {
        last--;
    }
    string middle = s_trimmed.substr(0, last);


    string s_reverse = middle;
    reverse(s_reverse.begin(), s_reverse.end());

    if (middle == s_reverse){
        int end_a_count = s_trimmed.size() - last;
        if (start > end_a_count) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    } else {
        cout << "No" << endl;
        return 0;
    }
    return 0;
}