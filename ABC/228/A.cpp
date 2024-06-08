#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, t, x;
    cin >> s >> t >> x;
    if(s < t){
        if(s < x && x < t) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }

    } else {
        if(s <= x or x < t) { //左側だけ＝が入るのいやらしいな。
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
    return 0;
}