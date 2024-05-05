#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i < n; i++)
using namespace std;

int main() {
    int n,k;
    cin >> n >> k;
    // int p[n];
    map<int, int> p[n];

    int temp;
    rep(i, n) {

    }

    /*
    方針；
    連続するk個の２次元配列を作成する。
    その配列の要素にあったpのインデックスをsetで取得する。
    そのセットで最大値と最小値の差を計算したものを逐次的に比較し、差の最小値を出力する
    */
    

    // 連続するk個の組みを格納するベクター
    vector<vector<int>> sequences;

    // 連続する3つの数の組みを生成する
    for (int i = 0; i <= n - k; ++i) {
        vector<int> sequence;
        for (int j = i; j < i + k; ++j) {
            sequence.push_back(j);
        }
        sequences.push_back(sequence);
    }

    // 結果を出力する
    cout << "連続する3つの数の組み：" << endl;
    for (const auto& seq : sequences) {
        cout << "[";
        for (int num : seq) {
            cout << num << " ";
        }
        cout << "]" << endl;
    }

    for(const auto& seq : sequences) {
        for(int num : seq) {
            //pの要素とnum+1が一致しているもののインデックスを取得(setで)

        }
    }

    //setの最初の要素とsetの最後の要素の差を計算
    //逐次的に差の最小値を比較して、答えを出す。

    return 0;
}