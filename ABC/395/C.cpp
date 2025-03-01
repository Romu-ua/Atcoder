#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    unordered_map<int, int> freq;
    int left = 0, min_length = n + 1;

    for (int right = 0; right < n; right++) {
        freq[A[right]]++;

        while (freq[A[right]] > 1) {
            min_length = min(min_length, right - left + 1);
            freq[A[left]]--;
            left++;
        }
    }
    if (min_length == n + 1) cout << -1 << endl;
    else cout << min_length << endl;

    return 0;
}
