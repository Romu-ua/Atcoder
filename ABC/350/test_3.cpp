#include <iostream>
#include <vector>
using namespace std;


void selectionSort(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    vector<pair<int, int>> sqapPaires;

    for (int i = 0; i < n - 1; ++i) {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
            count++;
            sqapPaires.push_back(make_pair(arr[i], arr[minIndex]));
        }
    }

    //実際に入れ替えた回数を出力
    cout << "入れ替えの回数" << count << endl;
    cout << "入れ替えた組" << endl;
    for (const auto& pair : sqapPaires) {
        cout << "(" << pair.first << ", " << pair.second << ")" << endl;
    }
}


int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    cout << "入力された文字は ";
    for (int i = 0; i < n; ++i) {
        cout << " " << A[i];
    }
    cout << endl;

    //順序が逆の時、その２つの数字を選択するってこと？
    //最小を含むやつを持ってくる?
    //選択ソートが入れ替え回数がnのオーダーで最小

    selectionSort(A);

    cout << "ソートされた後は ";
    for (int i = 0; i < n; ++i) {
        cout << " " << A[i];
    }
    cout << endl;


    return 0;
}