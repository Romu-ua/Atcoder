#include <bits/stdc++.h>
using namespace std;

class UnionFind
{
    public:
        UnionFind() = default;
        explicit UnionFind(size_t n) : m_parents(n), m_sizes(n, 1) {
            iota(m_parents.begin(), m_parents.end(), 0);
        }

        int find(int i) {
            //ノードiのrootを返す
            if(m_parents[i] == i) return i;
            return (m_parents[i] = find(m_parents[i]));
        }

        void merge(int a, int b) {
            a = find(a);
            b = find(b);

            if(a != b) {
                if(m_sizes[a] < m_sizes[b]) {
                    swap(a, b);
                }
                m_sizes[a] += m_sizes[b];
                m_parents[b] = a;
            }
        }

        bool connected(int a, int b) {
            return (find(a) == find(b));
        }

        int size(int i) {
            return m_sizes[find(i)];
        }


    private:
        vector<int> m_parents;
        vector<int> m_sizes;

};

int main() {
    return 0;
}