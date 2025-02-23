#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string a = "";
    a = a + s[1] + s[2] + s[0];
    string b = "";
    b = b + s[2] + s[0] + s[1];

    int a_n = stoi(a);
    int b_n = stoi(b);
    int c_n = stoi(s);

    cout << a_n + b_n + c_n << endl;

    return 0;
}