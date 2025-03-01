#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	vector<int> cnt(100000005);
	int mult = 0;
	const int INF = 1000000000;
	int ans = INF;
	int r = 0;
	for (int l = 0; l < n; l++) {
		while (r < n && mult == 0) {
			cnt[a[r]]++;
			if (cnt[a[r]] == 2) mult++;
			r++;
		}
		if (r == n) break;
		ans = min(ans, r-l);
		if (cnt[a[l]] == 2) mult--;
		cnt[a[l]]--;
	}
	if (ans == INF) ans = -1;
	cout << ans << endl;
	return 0;
}