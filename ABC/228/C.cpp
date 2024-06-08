#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    for(int i = 0; i < n; i++) {
        int sum = 0;
        for(int j = 0; j < 3; j++) {
            int pi;
            cin >> pi;
            sum += pi;
        }
        p[i] = sum;
    }

    //k番目より大きいことを示す。
    //=>大き順からk番目を取り出す.
    sort(p.begin(), p.end());
    set<int> set_p;
    for(int i = 0; i < n; i++) {
        set_p.insert(p[i]);
    }

    int p_k = p[k-1];
    for(int i = 0; i < n; i++) {
        if(p_k <= p[i] + 300) {
            cout << p_k << " " << p[i] << endl;
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}