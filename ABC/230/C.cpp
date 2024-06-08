#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    ll n, a, b, p, q, r, s;
    cin >> n >> a >> b >> p >> q >> r >> s;
    a--, b--, p--, q--, r--, s--;

    //メモリが多すぎるって怒られる。
    // vector<vector<char>> field(n, vector<char>(n));
    // for(int i = p; i <= q; i++) {
    //     for(int j = r; j <= s; j++) {
    //         ll xi = i-a, yi = j-b;
    //         // cout << xi << " " << yi << endl;
    //         if(xi == -yi) {
    //             field[i][j] = '#';
    //             continue;
    //         }
    //         if(xi == yi) {
    //             field[i][j] = '#';
    //             continue;
    //         }
    //         field[i][j] = '.';
    //     }
    // }

    // vector<vector<char>> ans(q-p+1, vector<char>(s-r+1, '.'));
    // ll xi = p - a, yi = r - b;
    // for(int i = 0; i < q-p+1; i++) {
    //     for(int j = 0; j < s-r+1; j++) {
    //         if(xi = -yi || xi == yi) {
    //             ans[i][j] = '#';
    //         }
    //         yi++;    
    //     }
    //     xi++;
    // }

    // //フィールドは作成できているから正しい。
    // for(int i = 0; i < q-p+1; i++) {
    //     for(int j = 0; j < s-r+1; j++) {
    //         cout << field[i][j];
    //     }
    //     cout << endl;
    // }

    // for(int i = p; i <= q; i++) {
    //     for(int j = r; j <= s; j++) {
    //         cout << field[i][j];
    //     }
    //     cout << "\n";
    // }
    return 0;
}