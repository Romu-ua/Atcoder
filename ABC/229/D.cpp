#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    int k;
    cin >> s >> k;

    //bit全探索っぽい。
    for(int i = 0; i < (1 << s.length()); i++) {
        vector<int> S;
        for(int j = 0; j < s.length(); j++) {
            if(i & (1 << j)) {
                S.emplace_back(j);
            }
        }
        int cnt = 0;
        string s_sample = s;
        for(auto si : S) {
            if(s_sample[si] == 'X') {
                continue;
            } else {
                s_sample[si] = 'X';
                cnt++;
            }
        }

        if(cnt > k) {
            continue;
        } else {
            //確認してみる
            cout << s_sample << endl;
        }
    }


    return 0;
}
//Xが連続しているところを数えようとするとさらにfor文を書く必要があるから無理だと判断。
//bit全探索じゃないのかも知れない。