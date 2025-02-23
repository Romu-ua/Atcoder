#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    map<string, int> mp;
    string s;
    for (int i = 0; i < N; i++) {
        cin >> s;
        mp[s]++;
    }

    // valueでソートする方法を知っておく必要があるな。
    vector<pair<int, string>> v;
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        v.push_back({ it ->second, it->first});
    }
    sort(v.rbegin(), v.rend());
    cout << v[0].second << endl;
    return 0;
}