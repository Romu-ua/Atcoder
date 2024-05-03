#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n;
    cin >> n;
    //nが０の時弾けないと思うので先に処理しておく
    if(n == 0) {
        cout << 1 << endl; 
        return 0;
    }

    //AとBの対称性から,√N回でいい。
    float min_digits = INFINITY;
    for (long long a = 1; a <= sqrt(n); a++) {
        if(n % a == 0) {
            long long b = 0;
            b = n / a;
            
            string a_str = to_string(a);
            string b_str = to_string(b);
            int temp_min_digits = max(a_str.length(), b_str.length());
            //これminにmaxを代入してて、キモいが、求めたいことが、「大きい方(最大)の約数の中での「最小」値」なのでこれで考えたいことと合致している。
            if(min_digits > temp_min_digits) {
                min_digits = temp_min_digits;
            }
            // cout << "処理中です" << endl;
        } 
    }

    cout << min_digits << endl;
    return 0;
}