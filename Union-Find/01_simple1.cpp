#include <iostream>
#include <vector>
#include <numeric>

//一番シンプルな実装

class UnionFind {
    public:
        UnionFind() = default;

        //m_parentsを全て０で初期化している。union-find木の初期化。
        //param n 要素数
        explicit UnionFind(size_t n)
                : m_parents(n){
                    std::iota(m_parents.begin(), m_parents.end(), 0);
                }
        
        int find(int i) {
            if (m_parents[i] == i) {
                return i;
            }
            //経路圧縮
            return (m_parents[i] == find(m_parents[i]));
        }

        void merge(int a, int b) {
            a = find(a);
            b = find(b);

            if (a != b) {
                m_parents[b] = a;
            }
        }

        bool connected(int a, int b) {
            return (find(a) == find(b));
        }
    
    private:
        std::vector<int> m_parents;
};

int main() {


    return 0;
}