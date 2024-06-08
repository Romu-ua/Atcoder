#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> s(n);
    for(int i = 0; i < n; i++) {
        cin >> s[i];
    }

    int ans = 0;
    set<int> set;
    for(int a = 1; a < 143 - 1; a++){
        for(int b = a; b < 143; b++) {
            int si = 4*a*b + 3*a + 3*b;
            //siが同じ結果になる時があって、それが重複している。
            if(set.find(si) == set.end()) {
                for(int i = 0; i < n; i++){
                    if(si == s[i]){
                        // cout << si << " " << s[i] <<  endl;
                        ans++;
                        }
                }
            }
            set.insert(si);
        }
    }

    cout << n-ans << endl;
    return 0;
}