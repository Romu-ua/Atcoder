#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    for (int i = 0; i < n; ++i) {
        cin >> a[i+1];
    }

    //配列を保存しておくやつ
    vector<int> pos(n+1);
    for (int i = 1; i <= n; ++i) pos[a[i]] = i; //3はindex 1 にある。という情報を保存している。

    vector<pair<int, int>> ans;
    for (int i = 1; i <= n; ++i) {
        while(a[i] != i) {
            int j = pos[i]; //a[i] == iがjになる。これで単純にfor文を回して、正しい位置jを見つけてくる必要がなくなった。
            swap(a[i], a[j]);

            swap(pos[a[i]], pos[a[j]]); //注意！！posの方も入れ替える。

            ans.emplace_back(i, j);
        }
    }
    cout << ans.size() << endl; 

    for (auto [i, j] : ans) cout << i << " " << j << endl;
    
    return 0;
}
