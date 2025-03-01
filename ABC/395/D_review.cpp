/*
操作２で中身の入れ替えを愚直に実装するとO(Q)になる
各クエリでどのような情報があればよいのかを列挙する
鳩：P　巣：H

op 1, 3について
- P->H 
	PからHが分かる情報が必要
（Pが与えられた元でHが分かることからop 3をやろうとすると上記のようにTLE）

発想：
中身を一つ一つ入れ替えるのではなく、Pのラッパー（袋）を考える

袋：B　を導入して以下の情報があればうまくいく
- P -> B
- B -> H
- H -> B

発想２：
ベクターのswap、先頭のポインタをスワップする
中身をごっそり入れ替えるのは無理なので、そのポインタををスワップする
*/


#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	// 0-based index
	vector<int> p2b(n);
	vector<int> b2h(n);
	vector<int> h2b(n);
	for (int i = 0; i < n; i++) {
		p2b[i] = i;
		b2h[i] = i;
		h2b[i] = i;
	}
	for (int qi = 0; qi < q; qi++) {
		int type;
		cin >> type;
		if (type == 1) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			p2b[a] = h2b[b];
		} else if(type == 2) {
			int a, b;
			cin >> a >> b;
			a--, b--;
			swap(h2b[a], h2b[b]);
			b2h[h2b[a]] = a;
			b2h[h2b[b]] = b;
		} else {
			int a;
			cin >> a;
			a--;
			int ans = b2h[p2b[a]];
			cout << ans + 1 << '\n';
		}
	}
	return 0;
}