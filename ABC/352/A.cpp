#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < n; i++)
using namespace std;

int main() {
    int n, x, y , z;
    cin >> n >> x >> y >> z;
    bool flag = false;
    if (x <= y) {
        for(int i = x; i < y+1; i++) {
            if(i == z){
                cout << "Yes" << endl;
                flag = true;
            }
        }
    } else if (y <= x) {
        for(int i = y; i < x+1; i++) {
            if(i == z){
                cout << "Yes" << endl;
                flag = true;
            }
        }
    }

    if(!flag) {
        cout << "No" << endl;
    }


    return 0;
}