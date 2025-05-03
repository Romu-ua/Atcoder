#include <bits/stdc++.h>
using namespace std;

int main() {
	string t, u;
	cin >> t >> u;

	int flag = false;
	for (int i = 0; i <= t.length() - u.length(); i++) {
		int cnt = 0;
		for (int j = 0; j < u.length(); j++) {
			if (t[i + j] == u[j] || t[i + j] == '?') {
				cnt++;
			}
			else
				break;
		}
		if (cnt == u.length())
			flag = true;
	}

	if (flag)
		cout << "Yes" << endl;
	else 
		cout << "No" << endl;
}