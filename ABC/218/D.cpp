#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<pair<int, int>> vec(n);
    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        vec[i].first = x;
        vec[i].second = y;
    }
    
    vector<pair<int, int>> vertical;
    vector<pair<int, int>> horizontal;

    for(int i = 0; i < n-1; i++) {
        for(int j = i+1; j < n; j++) {
            if(vec[i].first == vec[j].first) {
                if(vec[i].second > vec[j].second) {
                    swap(i, j);
                }
                vertical.emplace_back(make_pair(i, j));
            }
            if(vec[i].second == vec[j].second) {
                if(vec[i].first > vec[j].first) {
                    swap(i, j);
                }
                horizontal.emplace_back(make_pair(i, j));
            }
        }
    }

    if(vertical.size() == 0 or horizontal.size() == 0) {
        cout << 0 << endl;
        return 0;
    } 

    // for(int i = 0; i < vertical.size(); i++){
    //     cout << "(" << vertical[i].first << ", " << vertical[i].second << ") "; 
    // }
    // cout << endl;
    // for(int i = 0; i < horizontal.size(); i++){
    //     cout << "(" << horizontal[i].first << ", " << horizontal[i].second << ") "; 
    // }
    // cout << endl;
    
    int ans = 0;
    for(int i = 0; i < horizontal.size()-1; i++) {
        for(int j = i+1; j < horizontal.size(); j++) {
            pair<int, int> sample_first = make_pair(horizontal[i].first, horizontal[j].first);
            pair<int, int> sample_second = make_pair(horizontal[i].second, horizontal[j].second);
            for(int k = 0; k < vertical.size()-1; k++) {
                for(int l = k+1; l < vertical.size(); l++) {
                    if(sample_first == vertical[k] && sample_second == vertical[l]){
                        ans++;
                    }
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}
//11:00 ~ 25:00 + 25 + 6分