//DFSで重複組合せを列挙する。
#include <bits/stdc++.h>
using namespace std;

vector<int> combination;
void dfs(int depth, int size, int min, int max){
    if(depth == size) {
        for(int i = 0; i < depth; i++){
            cout << combination[i] << " ";
        }
        cout << endl;
    }
    else {
        for(int i = min; i <= max; i++){
            combination[depth] = i;
            dfs(depth+1, size, i, max);
        }
    }
}

int main() {
    int size, min, max;
    cin >> size >> min >> max;
    cout << endl;

    combination.resize(size);
    dfs(0, size, min, max);
    return 0;
}