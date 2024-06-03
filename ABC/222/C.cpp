#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<char>> vec(2*n, vector<char>(m));

    for(int i = 0; i < 2*n; i++) {
        for(int j = 0; j < m ; j++) {
            cin >> vec[i][j];
        }
    }

    // 転置行列を作成
    vector<vector<string>> transposed(m, vector<string>(2*n));
    for(int i = 0; i < 2*n; i++) {
        for(int j = 0; j < m ; j++) {
            transposed[j][i] = vec[i][j];
        }
    }

    // 転置行列を出力
    // for(int i = 0; i < m; i++) {
    //     for(int j = 0; j < 2*n; j++) {
    //         cout << transposed[i][j] << " ";
    //     }
    //     cout << endl;
    // }


    vector<int> score(2*n);
    for(int i = 0; i < 2*n; i++) {
        for(int j = 0; j < m; j++) {
            vec[i][j]
        }
    }


    return 0;
}
