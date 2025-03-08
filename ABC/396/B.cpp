#include <bits/stdc++.h>
using namespace std;

int main() {
	int q;
	cin >> q;
	vector<int> input(q);
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a;
		if (a == 1) {
			cin >> b;
			input.insert(input.begin(), b);
		}
		else {
			if (input.size() == 0)
				cout << 0 << endl;
			else {
				cout << input.front() << endl;
				input.erase(input.begin());
			}
		}
	}
	return 0;
}