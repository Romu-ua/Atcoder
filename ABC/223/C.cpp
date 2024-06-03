#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for(int i = 0; i < n; i++) {
        cin >> a[i] >> b[i];
    }
    vector<long double> time(n);
    long double sum_time = 0.0;
    for(int i = 0; i < n; i++) {
        time[i] = static_cast<long double>(a[i])/b[i];
        sum_time += time[i];
    }
    long double mid_s = sum_time/2;
    long double start = mid_s;
    long double sum_dist = 0.0;
    for(int i = 0; i < n; i++) {

        if(start - time[i] < 0){
            for(int j = 0; j < n; j++) {
                long double dist = start*b[i];
                sum_dist += dist;
                cout << sum_dist << endl;
                return 0;
            }
        } else {
            sum_dist += (long double)a[i];
            start -= time[i];

        }
    }
    return 0;
}