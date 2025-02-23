#include <iostream>
#include <vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    vector<pair<int, int>> swapPairs;

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
            swapPairs.push_back(make_pair(i, minIndex));
        }
    }

    cout << count << endl;
    for (const auto& pair : swapPairs) {
        // インデックスを元の値に変換して出力
        cout << arr[pair.first] << " " << arr[pair.second] << endl;
    }
}

int main() {
    int n;
    cin >> n;

    vector<int> A(n);
    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    selectionSort(A);

    return 0;
}
