#include <bits/stdc++.h>
using namespace std;

int main() {
    int a, b, k;
    cin >> a >> b >> k;
    int min_num = min(a, b);
    vector<int> common_divisor;

    for(int i = min_num; i >= 1 ;i--) {
        if((a % i) == 0 and (b % i) == 0) {
            common_divisor.emplace_back(i);
        }
    }

    cout << common_divisor[k-1] << endl;

    return 0;
}