#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int ai;
        cin >> ai;
        sum += ai;
        if (sum >= 360) sum -= 360;
        a.emplace_back(sum);
    }
    a.emplace_back(0); // これがないと1WA
    a.emplace_back(360);
    sort(a.begin(), a.end());
    vector<int> b;
    for (int i = 0; i < a.size()-1; i++) {
        b.emplace_back(a[i+1]-a[i]);
    }


    sort(b.begin(), b.end());
    cout << b.back() << endl;
    return 0;
}