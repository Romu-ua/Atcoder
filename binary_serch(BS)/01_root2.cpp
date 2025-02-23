//2分探索を用いて√2を求めています。

#include <iostream>
using namespace std;

int main() {
    double l = 1.0, r = 2.0;
    for(int i = 1; i <= 35; i++){
        double m = (l+r)/2;
        if(m * m <= 2.0) { l = m; }
        else { r = m; }
    }

    printf("%.9lf\n", l);
    return 0;
}