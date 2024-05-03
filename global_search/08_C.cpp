#include <bits/stdc++.h>
using namespace std;

int main() {
    long long a, b, c, x, y;
    cin >> a >> b >> c >> x >> y;

    long long sum_money = 0;
    long long min_number = min(x, y);
    long long number_remaining = abs(x - y);

    if(2*c < a + b) {
        for(long long i = 1; i <= min_number; i++) {
            sum_money += c*2;
        }
        if(min(x, y) == x) {
            //aの枚数の方が小さいなら、残っているのはbの枚数。
            //bが残っている->bよりabが安いなら全部abを買う
            if(2*c < b) {
                sum_money += c*2 * number_remaining;
            } else {
                sum_money += b * number_remaining;
            }
        } else {
            if(2*c < a) {
                sum_money += 2*c * number_remaining;
            } else {
                sum_money += a * number_remaining;
            }
        }

    } else {
        sum_money = a * x + b * y;
    }

    cout << sum_money << endl;

    return 0;
}