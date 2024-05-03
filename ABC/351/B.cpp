#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<vector<char>> A(n, vector<char>(n));
    vector<vector<char>> B(n, vector<char>(n));

    for (int i = 0; i < n;i++){
        for (int j = 0;j < n;j++){
            cin >> A[i][j];
        }
    }

    for (int i = 0; i < n;i++){
        for (int j = 0;j < n;j++){
            cin >> B[i][j];
        }
    }

    // for (int i = 0; i < n;i++){
    //     for (int j = 0;j < n;j++){
    //         cout <<  A[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    // for (int i = 0; i < n;i++){
    //     for (int j = 0;j < n;j++){
    //         cout <<  B[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    //入力が正しいのかを確認


    for (int i = 0; i < n; i++){
        for (int j = 0;j < n; j++) {
            if(A[i][j] != B[i][j]){
                cout << i+1 << " " << j+1 << endl;
            }
        }
    }
    return 0;
}