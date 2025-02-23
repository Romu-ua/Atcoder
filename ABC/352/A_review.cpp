#include <bits/stdc++.h>
using namespace std;

int main() {
    /*
    方針：
    上りを使うのか、下を使うのかを決める
    上　x < y : x < z && z < y の時"yes"
    下　x > y : y < z && z < x の時"yes"
    */

//-----------------------------------------------
//    int n, x, y, z;
//    cin >> n >> x >> y >>z;
//    if(x < y) {
//     if(x < z && z < y) cout << "Yes" << endl;
//     else cout << "No" << endl;
//    } else {
//     if(y < z && z < x) cout << "Yes" << endl;
//     else cout << "No" << endl;
//    }
//-----------------------------------------------

   //これでも良いが、条件分岐を少なくできる。
    int n, x, y, z;
    cin >> n >> x >> y >>z;
    if(x > y) swap(x, y);

    if(x < z && z < y) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}