#include <bits/stdc++.h>
using namespace std;

int main(){
    double P;
    cin >> P;

    auto f = [P](double x) {
        return x + P / pow(2, x / 1.5);
    };

    double low = 0;
    double high = 1e9;

    int cnt = 500;
    while(cnt--){
        double c1 = (low * 2 + high) / 3;
        double c2 = (low + 2 * high) / 3;

        if(f(c1) > f(c2)) low = c1;
        else high = c2;
    }

    cout << fixed << setprecision(20) << f(low) << endl;

    return 0;
}