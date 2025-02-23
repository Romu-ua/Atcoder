#include <bits/stdc++.h>
using namespace std;

vector<string> field;
int maxDepth = 0;
int h, w;

void dfs(int x, int y, int depth) {
    field[y][x] = '#';  // 現在の位置を訪問済みとする
    maxDepth = max(maxDepth, depth);  // 深さを更新

    // 下方向に進める場合
    if (y + 1 < h && field[y + 1][x] == '.') {
        dfs(x, y + 1, depth + 1);
    }

    // 右方向に進める場合
    if (x + 1 < w && field[y][x + 1] == '.') {
        dfs(x + 1, y, depth + 1);
    }
}

int main() {
    cin >> h >> w;
    field.resize(h);
    for (int i = 0; i < h; i++) {
        cin >> field[i];
    }

    int depth = 0;
    dfs(0, 0, depth);

    cout << maxDepth+1 << endl;
    return 0;
}
