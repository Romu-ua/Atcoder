#include <bits/stdc++.h>
using namespace std;

int main() {
    //実際に両方から燃やしていくシュミレーション型の実装
    int n;
    cin >> n;
    vector<double> a(n), b(n);
    for(int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i];
    }

    int li = 0, ri = n-1; //燃えている場所を表してる。
    //切れ目までどちらが先につくかを計算して、そこまで燃やす。
    double lx = 0, rx = 0; //どこまで燃えているのか。
    double ans = 0;
    
    //同じ導火線まで行ったら止める。
    while(lx < ri) {
        double lt = (a[li]-lx)/b[li]; //左側に置いて、導火線が切れ目まで燃え切る時間。
        double rt = (a[ri]-rx)/b[ri]; //右側に置いて、の導火線が切れ目まで燃え切る時間。
        if(lt < rt) {
            ans += a[li]-lt;
            lx = 0;
            rx = b[ri]*lt;
            li++;
        } else {
            ans += b[li]*rt;
            rx = 0;
            lx += b[li]*rt;
            ri--;
        }
    }

    ans += (a[li]-lx-rx)/2;
    printf("%.10f\n", ans);
    return 0;
}