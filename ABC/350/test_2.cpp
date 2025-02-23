#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;


void toggleValue(unordered_map<int, int>& dictionary, const vector<int>& keys) {
    for (int key : keys) {
        if (dictionary.find(key) != dictionary.end()) {
            // キーが存在する場合、値を反転（0を1に、1を0に）
            dictionary[key] = (dictionary[key] == 1) ? 0 : 1;
        }
        // もしキーが存在しない場合は何もしない
    }
}

int sumdic(const unordered_map<int, int>& dictionary) {
    int sum = 0;
    for (const auto& pair : dictionary) {
        sum += pair.second;
    }
    return sum;
}


int main() {
    int n, q;
    cin >> n >> q;
    vector<int> numbers(q);

    for (int i = 0; i < q; ++i) {
        cin >> numbers[i];
    }

    // cout << "入力された文字は ";
    // for (int i = 0; i < q; ++i) {
    //     cout << " " << numbers[i];
    // }

    // cout << endl;

    //配列に1と0を割り当てた辞書型みたいなものを作成して,配列に入っている数字をkeyにして01部分を変更する。

    //初期化する
    unordered_map<int, int> dictionary;
    for (int i = 1; i <= n; i++) {
        dictionary[i] = 1;
    }

    //dictionaryのvalueを変化させるのは関数で処理しよう。
    toggleValue(dictionary, numbers);

    // cout << "辞書の内容" << endl;
    // for (int i = 1; i <= n; i++) {
    //     cout << i << ":" << dictionary[i] << endl;
    // }

    int sum = sumdic(dictionary);
    // cout << "sum;" <<sum << endl;

    cout << sum << endl;

    return 0;
}