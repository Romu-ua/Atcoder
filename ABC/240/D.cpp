#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    stack<int> st;
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;

        if (st.size() > 0 && st.top() == a) {
            cnt++;
        }
        if (st.size() > 0 && st.top() != a) {
            cnt = 0;
        }

        st.push(a);
        if (cnt == a-1) {
            for (int j = 0; j < a; j++) {
                st.pop();
            }
            // 消した時にしか発動しない。
            while(!st.empty()) {
                int temp = st.size();
                stack<int> tempst;
                for (int i = 0; i < st.top(); i++) {
                    tempst.push(st.top());
                    st.pop();
                    if (st.top() != tempst.top()) break;
                }
                for (int i = 0; i < tempst.size(); i++) {
                    st.push(tempst.top());
                    tempst.pop();
                }
                // 変化がなかったらおしまい。
                if (temp == st.size()) break;
            }
        }
        cout << st.size() << endl;
    }
    return 0;
}