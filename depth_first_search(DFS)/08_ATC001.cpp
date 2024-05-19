#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

//入力
int H, W;
vector<string> field;
int seen[500][500];//これは条件から設定した値。

void dfs(int h, int w){
    seen[h][w] = true;

    for(int dir = 0; dir < 4; ++dir) {
        int nh = h + dx[dir];
        int nw = w + dy[dir];

        if(nh < 0 || nh >= H || nw <0 || nw >= W) continue;
        if(field[nh][nw] == '#') continue;

        if(seen[nh][nw]) continue;

        dfs(nh, nw);
    }
}


int main() {
    cin >> H >> W;
    field.resize(H);
    for(int h = 0; h < H; h++) cin >> field[h]; //行を文字列として受け取っているのか。賢いな。

    //sとgを特定する
    int sh, sw, gh, gw;
    for(int h = 0; h < H; h++){
        for(int w = 0; w < W; w++){
            if(field[h][w]=='s'){
                sh = h;
                sw = w;
            } 
            if(field[h][w]=='g'){
                gh = h;
                gw = w;
            }
        }
    }

    //捜索開始
    memset(seen, 0, sizeof(seen));
    dfs(sh, sw);

    //結果
    if(seen[gh][gw]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}