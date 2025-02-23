// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     //方針：x+yがtより大きかったら無理。偶数秒の時はx+yが偶数のところに存在でき、奇数秒の時は奇数のところに存在できる
//     //その場にとどまることができない、を考慮する。
//     int n;
//     cin >> n;
//     bool flag = false;
//     for(int i = 0; i < n;i++) {
//         int t, x, y;
//         cin >> t >> x >> y;
//         if(t < x+y) {
//             // cout << "tよりx+yが大きいです。" << endl;
//             cout << "No" << endl;
//             return 0;
//         } else {
//             if((x+y) % 2 == 0 and t % 2 == 0) {
//                 flag = true;
//             } else if((x+y) % 2 == 1 and t % 2 == 1) {
//                 flag = true;
//             } else {
//                 // cout << "tとx+yの偶奇があっていません。" << endl;
//                 cout << "No" << endl;
//                 return 0;
//             }
//         }
//     }
//     cout << "Yes" << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int t[n+1], x[n+1], y[n+1];
    t[0] = x[0] = y[0] = 0; //初期化、リストの最初は0を入れておく
    for(int i = 0; i < n;i++) {
        cin >> t[i+1] >> x[i+1] >> y[i+1];
    } 

    bool flag = true;
    for(int i = 0; i < n; i++) {
        int dt = t[i+1] - t[i];
        int d = abs(x[i+1] - x[i]) + abs(y[i+1] - y[i]);
        if(dt < d) {
            flag = false;
        } else {
            if(d % 2 != dt % 2) {
                flag = false;
            }
        }
    }

    if(flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}