#include <bits/stdc++.h>
using namespace std;

int main( ){
    int n, k;
    cin >> n >> k;
    k -= 1;
    vector<int> p(n);
    for(int& x : p) {
        int a, b, c;
        cin >> a >> b >> c;
        x = a + b + c;
    }

    vector<int> q = p;
    sort(q.begin(), q.end(), greater<>()); //降順に変更している
    for(int x : p) {
        cout << (x + 300 >= q[k] ? "Yes" : "No") << endl;
    }

    return 0;
}