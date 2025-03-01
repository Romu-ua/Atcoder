#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;
    
    vector<int> ball_location(n);
    for (int i = 0; i < n; i++) {
        ball_location[i] = i;
    }
    vector<int> box_label(n);
    for (int i = 0; i < n; i++) {
        box_label[i] = i;
    }
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[i] = i;
    }
    
    vector<int> output;
    for (int i = 0; i < q; i++) {
        int op;
        cin >> op;
        if (op == 1) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            ball_location[a] = pos[b];
        } else if (op == 2) {
            int a, b;
            cin >> a >> b;
            a--; b--;
            int pa = pos[a], pb = pos[b];
            swap(box_label[pa], box_label[pb]);
            swap(pos[a], pos[b]);
        } else if (op == 3) {
            int a;
            cin >> a;
            a--;
            int physical = ball_location[a];
            int label = box_label[physical];
            output.push_back(label + 1);
        }
    }
    
    for (int x : output) {
        cout << x << "\n";
    }
    return 0;
}
