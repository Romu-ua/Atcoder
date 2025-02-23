#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for(int i = 0; i < n; i++) { 
        cin >> vec[i].first >> vec[i].second;
    }

    //x座標にてソート。
    sort(vec.begin(), vec.end());

    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(vec[i].first < vec[j].first && vec[i].second < vec[j].second) {
                if(binary_search(vec.begin(), vec.end(), make_pair(vec[i].first, vec[j].second)) && 
                    binary_search(vec.begin(), vec.end(), make_pair(vec[j].first, vec[i].second))) {
                        ans++;
                    }
            }
        }
    }

    cout << ans << endl;

    return 0;
}