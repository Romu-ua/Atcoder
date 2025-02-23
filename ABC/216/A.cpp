#include <bits/stdc++.h>
using namespace std;

int main() {
        int x, y;
        char z;
        cin >> x >> z >> y;

        if(0 <= y && y <= 2) {
            cout << x << "-" << endl;
        } else if(3 <= y && y <= 6) {
            cout << x << endl;
        } else {
            cout << x << "+" << endl;
        }
    return 0;
}
//5