//重複順列の列挙

#include <bits/stdc++.h>
using namespace std;

vector<int> permutation;
void dfs(int depth, int size, int min, int max) {
    if(depth == size) {
        for(int i = 0; i < depth; i++){
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
    else {
        for(int i = min; i <= max; i++){
            permutation[depth] = i;
            dfs(depth+1, size, min, max);
        }
    }
}

int main() {
    //max-min+1 個の整数から size 個選ぶ
    int size, min, max;
    cin >> size >> min >> max;
    cout << endl;

    permutation.resize(size);
    dfs(0, size, min, max);  
    return 0;
}