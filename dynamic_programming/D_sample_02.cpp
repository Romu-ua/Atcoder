#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 問題文から「縦」と「横」、「要素が何を表しているのか」、を何にすれば良いのかがわからん。
// あと添字を使ってDPを使っているときに、表を思い浮かべるのは悪手かもしれない。

constexpr int dx[6] = {0, 1, 0, 2, 0, 1};
constexpr int dy[6] = {0, 0, 1, 0, 0, 1};
constexpr int dz[6] = {0, 0, 0, 0, 1, 0};

int main() {
    cout << fixed << setprecision(10);

    ll n, d;
    cin >> n >> d;

    vector<int> cnt;
    for(auto const v : {2, 3, 5}) {
        int c = 0;
        while(d % v == 0) {
            d /= v;
            c++;
        }
        cnt.push_back(c);
    }

    //因数分解した結果が2,3,5以外の倍数が存在してる時は無理。
    if(d != 1) {
        cout << 0 << endl;
        return 0;
    }

    // 配列はiがi+1を表しているからプラス１している。
    int x_size = cnt[0] + 1;
    int y_size = cnt[1] + 1;
    int z_size = cnt[2] + 1;
    vector<vector<vector<long double>>> dp(x_size, vector<vector<long double>>(y_size, vector<long double>(z_size, 0.0)));
    dp[0][0][0] = 1.0;

    for(int lp = 0; lp < n; lp++) {
        vector<vector<vector<long double>>> nxt(x_size, vector<vector<long double>>(y_size, vector<long double>(z_size, 0.0)));
        for(int x = 0; x <= cnt[0]; x++) {
            for(int y = 0; y <= cnt[1]; y++) {
                for(int z = 0; z <= cnt[2]; z++) {
                    for(int i = 0; i < 6; i++) {
                        const int nx = min(cnt[0], x + dx[i]);
                        const int ny = min(cnt[1], y + dy[i]);
                        const int nz = min(cnt[2], z + dz[i]);
                        nxt[nx][ny][nz] += dp[x][y][z] / 6;
                    }
                }
            }
        }
        // nxtの配列をnpに移動している。moveをすると空の配列になる。
        dp = move(nxt);
    }

    cout << dp[cnt[0]][cnt[1]][cnt[2]] << endl;
    return 0;
}