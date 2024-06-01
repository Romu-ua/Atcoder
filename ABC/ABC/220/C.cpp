#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long x;
    cin >> x;

    int sum_vec = reduce(a.begin(), a.end());

    int l = x/2;
    while(true) {
        long double x_div;
        


        x_div = x/l;
        if(sum_vec > x_div) {
            l--;
            break;
        }
        l++;
    }

    int sum = l*sum_vec;
    for(int i = 0; i < n; i++) {
        sum += a[i];
        if(sum > x) {
            cout << l*a.size() + i+1 << endl;
            return 0;
        }
    }
}
//