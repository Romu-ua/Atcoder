#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<int>> vec(n);
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;
        vec[a-1].emplace_back(b-1);
        vec[b-1].emplace_back(a-1);
    }

    bool flag = false;
    for(int i = 0; i < n; i++) {
        if(vec[i].size() == n-1) flag = true;
    }

    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}

//1:11:54
//スターの意味を取り違えてて大幅に遅れた。