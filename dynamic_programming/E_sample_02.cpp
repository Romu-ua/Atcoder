#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i] >> b[i];
    } 
    // DPの中身を最大のファーストアセプタンスを要素にするのではなくて、
    // ファーストアセぷタンスを獲得できる最小の時間？にする。
    vector<vector<int>> dp(N, vector<int>());
    
    

    return 0;
}