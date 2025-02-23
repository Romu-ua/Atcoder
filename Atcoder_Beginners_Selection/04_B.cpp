#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n);

    for (int i = 0; i < n ;i++) {
        cin >> a[i];
    }

    int count = 0;
    bool flag = true;
    while(flag) {
        for(int i = 0; i < n; i++){
            if(a[i] % 2 == 0) {
                a[i] /= 2;
            } else {
                flag = false;
                break;
            }
        }
        if(flag) {
            count++;
        }
    }
    cout << count << endl;

    return 0;
}