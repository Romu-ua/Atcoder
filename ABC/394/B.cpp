#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;

    cin >> n;

    vector<pair<int, string>> input(n);

    for (int i = 0; i < n; i++) {
        cin >> input[i].second;
        input[i].first = input[i].second.length();
    }
    sort(input.begin(), input.end(),  [](const auto& a, const auto& b) {
        return a.first < b.first;
    });

    string output;

    for (int i = 0; i < n; i++) {
        output += input[i].second;
    }
    cout << output << endl;

    return (0);
}