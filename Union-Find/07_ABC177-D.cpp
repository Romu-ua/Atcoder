#include <bits/stdc++.h>
using namespace std;

class UnionFind {
    public: 
        UnionFind() = default;
        explicit UnionFind(size_t n) : m_parents(n), m_sizes(n, 1) {
            iota(m_parents.begin(), m_parents.end(), 0);
        }

        int find(int i) {
            //親の要素を取得する関数
            if(m_parents[i] == i) return i;
            return (m_parents[i] = find(m_parents[i]));
        } 

        void merge(int a, int b) {
            //木を統合する関数
            a = find(a);
            b = find(b);

            if(a != b) {
                // m_parents[b] = a;今回は木のサイズが深い方に浅い方をつなげる。
                //小さい方が必ずbに来るようにする。
                if(m_sizes[a] < m_sizes[b]) {
                    swap(a,b);
                }

                //小さい方の木のrootを大きい方の木のrootであるaにしている。
                m_parents[b] = a;
                //木を統合したのでサイズを大きくする。
                m_sizes[a] += m_sizes[b];
            }

        }

        bool connected(int a, int b) {
            //つながっているかどうかを判定する関数
            return (find(a) == find(b));
        }

        int size(int i) {
            //iグループの要素数を取得する関数
            return m_sizes[find(i)];
        }


    private:
        //m_parents[i] のrootのノード
        vector<int> m_parents;
        //グループの要素数
        vector<int> m_sizes;

};

int main() {
    //同じグループに属しているかどうかを判定するときはUnionFind木のデータ構造を使う
    
    //出力が入力の前にフラッシュされなくなるらしい。
    cin.tie(0)->sync_with_stdio(0);

    int N, M;
    cin >> N >> M;

    //UnifonFindの初期化。
    UnionFind uf(N);

    //UnionFindを作成。
    //UnionFindは作成したm_parentsの配列が本質。
    while(M--) {
        int A, B;
        cin >> A >> B;
        --A, --B;
        uf.merge(A, B);
    }

    int answer = 0;
    for(int i = 0; i < N; ++i) {
        answer = max(answer, uf.size(i));
    }

    cout << answer << endl;
    return 0;
}