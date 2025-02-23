#include <bits/stdc++.h>
using namespace std;

int main() {
    double h;
    cin >> h;

    double result = (12800000 + h)*h;
    result = sqrt(result);

    cout << fixed << setprecision(10) << result << endl;

    return 0;
}