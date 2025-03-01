#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	int input[n];
	for (int i = 0; i < n; i++) {
		cin >> input[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (input[i] >= input[i + 1])
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	return 0;
}