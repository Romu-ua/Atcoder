#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, Y;
    cin >> N >> Y;
    for(int i = 0; i <= N; i++) {
        for (int j = 0; j<= N; j++) {
            if(N-i-j >= 0) {
                if(10000*(N-i-j) + 5000*j + 1000*i == Y) {
                    cout << N-i-j << " " << j << " " << i << endl;
                    return 0;
                }
            }
        }
    } 

    cout << "-1 -1 -1" << endl;
    return 0;
}