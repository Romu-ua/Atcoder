#include <bits/stdc++.h>
using namespace std;

int main() {
    string n;
    cin >> n;

    long long max;
    //多分半分に分割してソートしたもの同士をかけるのが最大っぽい。
    //偶数桁の時はそのまま半分にできるけど、奇数の時は2回試す必要がある？
    sort(n.rbegin(), n.rend());
    if(n.length() % 2 == 0) {
        string left = n.substr(0, n.length() / 2);
        string right = n.substr(n.length() / 2, n.length());
        cout << left << " " << right << endl;
        int num_left = stoi(left);
        int num_right = stoi(right);
        cout << num_left * num_right << endl;
    } else {
        string left = n.substr(0, n.length()/2); //割り算は切り捨てなのでこれでいいのか。
        string right = n.substr(n.length()/2, n.length());
        cout << left << " " << right << endl;
        int num_left = stoi(left);
        int num_right = stoi(right);
        cout << num_left * num_right << endl;
    }   
    return 0;
}
