#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    set<int> set;
    int e;
    for (int i = 0; i < n; i++){
        cin >> e;
        set.insert(e);
    }

    cout << set.size() << endl;
    return 0;
}