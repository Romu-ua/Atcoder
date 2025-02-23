#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N);

    for (int i = 0; i < N;i++) {
        cin >> a[i];
    }

    sort(a.rbegin(), a.rend());

    int Alice = 0, Bob = 0;
    bool alice_turn = true;
    for (int j = 0; j < N;j++) { 
        if(alice_turn) {
            Alice += a[j];
        } else {
            Bob += a[j];
        }
        alice_turn = !alice_turn;
    }

    cout << Alice - Bob << endl;

    return 0;
}