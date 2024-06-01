#include <bits/stdc++.h>
using namespace std;

int main() {
    string s1, s2, s3;
    cin >> s1 >> s2 >> s3;
    set<string> s;
    s.insert(s1);
    s.insert(s2);
    s.insert(s3);

    set<string> ans = {"ABC" , "ARC" , "AGC" , "AHC"};
    set<string> result;

    set_difference(ans.begin(), ans.end(), s.begin(), s.end(), inserter(result, result.end()));

    cout << *result.begin() << endl;

    return 0;
}

//14:00 ~ 6:20