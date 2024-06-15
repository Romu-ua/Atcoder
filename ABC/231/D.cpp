#include <bits/stdc++.h>
using namespace std;

int main() {
    // 配置しておいて、それが答えに適しているのかを確かめる。
    // 配列が取りうる状態は、N! なので答えの決めうちは工夫する必要がある。
    // sortアルゴリズムの亜種的な？
    // BをAの右隣に持ってくるっていうプログラム？
    // Bだけを入れていくソートなら高速化かも。
    int N, M;
    cin >> N >> M;
    vector<int> a(N), b(N);
    for (int i = 0; i < M; i++) {
        cin >> a[i] >> b[i];
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    

    bool flag = true;
    auto it = a.begin();
    for (int i = 0; i < M; i++) {
        if (find(it+1, a.end(), a[i]) != a.end()) {
            auto it = find(a.begin(), a.end(), b[i]) + 1;
            a.insert(it, b[i]);
        } else {
            flag = false;
        }
    }   

    for (int i = 0; i < N; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    if (flag) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    
    return 0;
}