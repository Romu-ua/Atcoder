#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, m, q;
	cin >> n >> m >> q;
	// vector<vector<int>> xy(n ,vector<int>(m, 0));
	vector<unordered_set<int>> xy(n);
	vector<int> row(n, 0);
	int qu, x, y;
	for (int i = 0; i < q; i++) {
		cin >> qu;
		if (qu == 1) {
			cin >> x >> y;
			x--;
			y--;
			xy[x].insert(y);
		} else if (qu == 2) {
			cin >> x;
			x--;
			row[x] = true;
		} else if (qu == 3) {
			cin >> x >> y;
			x--;
			y--;
			if (xy[x].count(y) || row[x])
				cout << "Yes" << endl;
			else
				cout << "No" << endl;
		}
	}
	return (0);
}