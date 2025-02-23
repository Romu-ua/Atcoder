#include <bits/stdc++.h>
using namespace std;

int main() {
    int A[9] = {0};
    int B[9] = {0};

    for (int i = 0; i < 9;i++){
        cin >> A[i];
    }
    for (int i = 0; i < 8;i++){
        cin >> B[i];
    }

    int sum_a  = 0;
    for (int i = 0; i < 9; i++) {
        sum_a += A[i];
    }

    int sum_b  = 0;
    for (int i = 0; i < 8; i++) {
        sum_b += B[i];
    }

    cout << sum_a - sum_b + 1 << endl;

    return 0;
}