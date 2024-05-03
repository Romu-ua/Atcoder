#include <bits/stdc++.h>
using namespace std;

//再帰的？かと思った。



int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n ;i++){
        cin >> A[i];
    }
    
    bool merged = true;
    while(merged) {
        merged = false;
        for(int i = 0; i < A.size()-1; i++) {
            if(A[i] == A[i+1]) {
                A[i] += 1;
                A.erase(A.begin() + (i + 1));
                merged = true;
            }
        }
    }       
    cout << A.size() << endl;
    return 0;
}