#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a;

	int ans = 0;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (i % 2 == 0) 
			ans += a;
	}	
	cout << ans << endl;
}