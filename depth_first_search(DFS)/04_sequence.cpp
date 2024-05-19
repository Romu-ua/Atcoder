//DFSで順列を列挙する
#include <bits/stdc++.h>
using namespace std;

vector<int> permutation;
vector<bool> used; //すでに使用した数字かを判定する配列。
void dfs(int depth, int size, int min, int max){
    if(depth == size){
        for(int i = 0; i < depth; i++){
            cout << permutation[i] << " ";
        }
        cout << endl;
    }
    else {
        for(int i = min; i <= max; i++){
            if(!used[i]){
                permutation[depth] = i;
                used[i] = true;
                dfs(depth+1, size, min, max);
                used[i] = false;
            }
        }
    }
}


int main() {
    int size, min, max;
    cin >> size >> min >> max;
    cout << endl;

    permutation.resize(size);
    used.resize(size);
    dfs(0, size, min, max);
    return 0;
}