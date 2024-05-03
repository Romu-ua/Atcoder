#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    int counter = 0;
    
    for(int i =1; i <= n; i++) {
        string I = to_string(i);
        if(I.length() % 2 == 1) counter++;
    }

    cout << counter << endl;
    return 0;
}