#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<string> s(n, string(n, '?'));
	
	for (int i = 0; i < n; i++) {
		int j = n - 1 - i;
		if (i > j) continue;
		for (int x = i; x <= j; x++) {
			for (int y = i; y <= j; y++) {
				if (i % 2 == 0)
					s[x][y] = '#';
				else
					s[x][y] = '.';
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << s[i] << endl;
	}
}

// 外側からの距離でも出来る