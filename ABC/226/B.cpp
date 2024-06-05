#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    set<vector<int>> a;

    for(int i = 0; i < n; i++) {
        int l;
        cin >> l;
        vector<int> sample_a(l);
        for(int j = 0; j < l; j++) {
            cin >> sample_a[j];
        }

        a.insert(sample_a);
    }

    cout << a.size() << endl;
    return 0;
}

//18:00 ~ 0:00 25:00 ~ 15:00ギブ。時間かかりすぎ。方針合ってるやん。