// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     int n;
//     string s;
//     cin >> n >> s;
//     set<array<int, 3>> numbers;

//     //sいらんくね？って思ったけど、重複は許されてないのね。
//     array<int, 3> temp_number;
//     for(int i = 0; i < n-2; i++) {
//         for(int j = i+1; j < n-1; j++) {
//             for (int k = j+1; k < n; k++) {
//                 cout << "保存される値は(" << s[i] << "," << s[j] << "," << s[k]<< ")" << endl;
//                 temp_number = {s[i] - '0', s[j] - '0', s[k] - '0'};
//                 numbers.insert(temp_number);
//             }
//         }
//     }
//     for (const auto& temp_number : numbers) {
//         cout << "(" << temp_number[0] << "," << temp_number[1] << "," << temp_number[2] << ")" << endl;
//     }

//     cout << numbers.size() << endl;

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main() {
    //暗証番号は000から999までの1000通りなので、「ラッキーナンバーSからN-3桁を消して、暗証番号Vを作ることはできるのか？」という問題を解く。
    //V＿1はSの一番小さいインデックスのやつにする。
    //上のような作業をv_2とv_3にもやる。
    string S;
    int N, cnt = 0;

    cin >> N >> S;
    for(int i = 0; i < 1000; i++) {
        int c[3] = {i/100, (i/10) % 10, i % 10};
        int f = 0;
        for(int j = 0; j < N; j++) {
            if(S[j] == ('0' + c[f])) f++;
            if(f == 3) break;
        }
        if (f == 3) cnt++;
    }
    cout << cnt << endl;
    return 0;
}