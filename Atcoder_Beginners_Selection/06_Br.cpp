#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, a, b;
    cin >> n >> a >> b;

    int ans = 0;
    for (int i = 0; i <= n; i++){
        string s = to_string(i);
        int sum = 0;
        for (int j = 0; j < s.size(); j++) {
            sum += int(s[j] - '0');
        }

        if (a <= sum && sum <= b) {
            ans += i;
        }
    }

    cout << ans << endl;
    return 0;
}