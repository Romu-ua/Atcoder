#include <bits/stdc++.h>
using namespace std;

class UnionFind{
    public:
        UnionFind() = default;
        explicit UnionFind(size_t n) : m_parents(n) {
            iota(m_parents.begin(), m_parents.end(), 0);
        }

        int find(int i) {
            //今見ているノードのルートを返す。
            if(m_parents[i] == i) return i;
            //経路圧縮
            return (m_parents[i] = find(m_parents[i]));
        }

        void merge(int a, int b) {
            //同じグループに属していない時に木を統合する
            a = find(a);
            b = find(b);
            if(a != b) {
                m_parents[b] = a;
            }
        }

        bool connected(int a, int b) {
            //aとbがつながっているのかを確かめる
            return (find(a) == find(b));
        }


    private:
        vector<int> m_parents;

};

struct Edge {
    int from;
    int to;
    int cost;

    //コストに基づく大小比較
    bool operator <(const Edge& other) const {
        return (cost < other.cost);
    }
};

/*
演算子オーバーロードを行なっているのはsort関数内で使いたいから。
これを行わずに、比較関数を定義してsort関数内で使うやり方もある
例えば、
bool compaerEdge(const Edge& a, const Edge& b) {
    return a.cost < b.cost
}
をグローバルで定義しておいて、main関数内で、
vector<Edge> edges = {{1, 2, 10}, {2, 3, 5}, {3, 4, 1}};
sort(edges.begin(), edges.end(), compareEdges);
としても良い。
*/

int main() {
    /*
    グラフは全て繋がっているから連結である。
    同じ連結成分に含まれていると閉路が作られ、異なる連結成分に含まれていると閉路はできない。
    このことから、異なる連結成分であるかどうかを判定することと、異なる連結成分であるノードを繋げることと、
    が求められているのでunionfind木を使う。

    クラスカル法がなぜ最小全域木を求められるのか？
    ->グリーディーの戦略と切断定理に基づいていて、各ステップでの局所的な最適選択が全体の最適選択に繋がることが証明されている。
    イメージとしては、最小全域木の部分木について、最小全域木を考えるとそれは局所的な最適によって求めることができるから。
    ここで、閉路ができないように作成していくべきだが、これはunionfind木の性質そのものである。
    */

    int V, E;
    cin >> V >> E;

    vector<Edge> edges(E);
    for(auto& edge : edges) {
        cin >> edge.from >> edge.to >> edge.cost;
    }
    sort(edges.begin(), edges.end());

    UnionFind uf(V);
    long long sum = 0;

    for(const auto& edge : edges) {
        if(!uf.connected(edge.from, edge.to)) {
            uf.merge(edge.from, edge.to);
            sum += edge.cost;
        }
    }

    cout << sum << endl;

    return 0;
}