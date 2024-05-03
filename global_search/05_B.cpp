#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int counter = 0;

    for(int i = 1; i <= n; i++) {
        if((i % 2) == 1) {
            int facotr_num = 0;
            for(int j = 1; j <= i; j++) {
                if(i % j == 0) facotr_num++;
            }
            
            if(facotr_num == 8) {
                // cout << "約数が8個あるのは " << i << endl;
                counter++;
            }
        } 
    }

    cout << counter << endl;
    return 0;
}