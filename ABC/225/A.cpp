#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;
    sort(s.begin(), s.end());
    set<string> st;
    do{
        st.insert(s);
    } while(next_permutation(s.begin(), s.end()));

    cout << st.size() << endl;

    return 0;
}
//1:37:00