#include <bits/stdc++.h>
using namespace std;

/*
方針がわからん。
ソートの仕方で(勝ち数、id)のpairがある。勝ち数が大き方順で並べるが、idは小さい順で並べたい時、-勝ち数を考えてあげることによって
勝ち数を小さい順で並べてあげればidも小さい順で並ぶ

*/

bool win(char a, char b) {
    if(a == 'G' && b == 'C') return true;
    if(a == 'C' && b == 'P') return true;
    if(a == 'P' && b == 'G') return true;
    return false;
}


int main() {
    int n, m;
    cin >> n >> m;
    int n2 = n*2;
    vector<string> a(n2);
    for(int i = 0; i < n2; i++) {
        cin >> a[i];
    }

    vector<pair<int, int>> d(n2);
    for(int i= 0; i < n2; i++) {
        d[i] = pair<int, int>(0, i);
    }

    for(int mi = 0; mi < m; mi++) {
        for(int ni = 0; ni < n; ni++) {
            int i = ni*2, j = ni*2+1;
            int ai = d[i].second, aj = d[j].second; //idを取っているだけ。
            if(win(a[ai][mi], a[aj][mi])) d[i].first--;
            if(win(a[aj][mi], a[ai][mi])) d[j].first--;
        }
        sort(d.begin(), d.end());
    }
    for(int i = 0; i < n2; i++) {
        cout << d[i].second+1 << endl;
    }
    return 0;
}