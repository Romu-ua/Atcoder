#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> field(n);
    for (int i = 0; i < n; i++) {
        cin >> field[i];
    }

    // ＃の場所を決めるn(n-1)の計算量
    // チェックする 横n^2, 縦n^2、斜めn^2
    // なので全て別々の処理をしてあげればおけ。
    vector<pair<int, int>> point;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (field[i][j] != '#') point.emplace_back((i, j));
        }
    }

    for (int i = 0; i < (int)point.size(); i++) {
        // 縦横斜めのチェック。だが、point.sizeが最大でn^2の計算量になってしまうからこのループはn^4の計算量になってしまう。無理ぽ。
        // 探索範囲をどのように絞るのか、わからん。
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {

            }
        }
    }




    return 0;
}