#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    public:
        UnionFind() = default;
        explicit UnionFind(size_t n) : m_parents(n) {
            iota(m_parents.begin(), m_parents.end(), 0);
        }

        int find(int i) {
            //今見ているノードがrootならその番号を返す。
            if(m_parents[i] == i) return i;

            //経路圧縮
            //今見ているノードのrootをm_parents配列に入れている。
            return (m_parents[i] = find(m_parents[i]));
        } 

        void merge(int a, int b) {
            //aとbのrootを取ってきている。
            //これが同じ時mergeしない。違う時mergeする
            a = find(a);
            b = find(b);

            //rootを同じにすることでmergeする作業を再現している。
            if(a != b) m_parents[b] = a;
        }

        bool connected(int a, int b) {
            return (find(a) == find(b));
        }

    private:
        vector<int> m_parents;
};


int main() {
    int N, M;
    cin >> N >> M;

    vector<int> A(M), B(M);

    for(int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        A[i] = --a;
        B[i] = --b;
    }

    int ans = 0;

    for(int i = 0; i < M; i++) {
        //各辺について一つずつunionfind木を作成する。
        //unionfindの初期化。
        UnionFind uf(N); 

        for(int k = 0; k < M; ++k) {
            //各辺について i の辺を除いたunionfind木を作成する
            if(i != k) {
                uf.merge(A[k], B[k]);
            }
        }

        int count = 0;

        //各頂点について、自身がrootであるものが２つあれば非連結になっている。
        for(int k = 0; k < N; k++) {
            if(k == uf.find(k)) {
                ++count;
            }
        }

        if(1 < count) {
            //削除した辺は橋であった
            ++ans;
        }
    }

    cout << ans << endl;;
    return 0;
}