#include <bits/stdc++.h>
using namespace std;

string rotatestrings(string& s) {
    char lastchar = s.back();
    s.pop_back();
    s.insert(s.begin(), lastchar);
    return s;
}

int main() {
    string s;
    cin >> s;

    vector<string> vec;
    vec.emplace_back(s);

    for(int i = 0; i < s.length(); i++) {
        rotatestrings(s);
        vec.emplace_back(s);
    }

    sort(vec.begin(), vec.end());

    cout << *vec.begin() << endl;
    cout << *(vec.end()-1) << endl;

    return 0;
}