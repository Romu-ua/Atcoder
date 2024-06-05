#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> vec(n, vector<long long>(m));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin >> vec[i][j];
            vec[i][j] -= 1;
            vec[i][j] %= 7;
        }
    }

    

    bool flag = true;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m-1; j++) {
            if(vec[i][j] == vec[i][j+1] - 1) continue; //横方向の判定
            else flag = false;
        }
    }

    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < m; j++) {
            if(vec[i][j] == vec[i+1][j]) continue; //縦方向の判定
            else flag = false;
        }
    }

    if(m == 1) {
        for(int i = 0; i < n-1;i++) {
            if(vec[i][0] == vec[i+1][0]) continue;
            else flag = false;
        }
    } else if(n == 1) {
        for(int j = 0; j < m-1;j++) {
            if(vec[0][j] == vec[0][j+1] - 1) continue;
            else flag = false;
        }
    }

    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
//35: