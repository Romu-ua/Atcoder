#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class UnionFind {
    public:
        UnionFind() = default;
        explicit UnionFind(size_t n) : m_parents(n) {
            iota(m_parents.begin(), m_parents.end(), 0);
        }

        int find(int i) {
            if(m_parents[i] == i) return i;

            //経路圧縮
            return (m_parents[i] = find(m_parents[i]));
        }

        void merge(int a, int b) {
            a = find(a);
            b = find(b);

            if(a != b) {
                m_parents[b] = a;
            }
        }

        bool connected(int a, int b) {
            return (find(a) == find(b));
        }


    private:
        vector<int> m_parents;

};


int main() {
    int N, Q;
    cin >> N >> Q;

    UnionFind uf(N);

    while(Q--) {
        int t, u, v;
        cin >> t >> u >> v;

        if(t == 0) {
            uf.merge(u,v);
        } else {
            cout << (uf.connected(u, v) ? "Yes\n" : "No\n");
        }
    }
    return 0;
}