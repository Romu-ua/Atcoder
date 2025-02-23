#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, A, B;
    cin >> N >> A >> B;

    int counter = 0;

    for (int i = 0; i <= N; i++) {
        int sum = 0;
        int temp = i; //以下でiを使って計算を進めているからiを保存するために。
        while(temp > 0) { 
            int over;
            over = temp % 10;
            sum += over;
            temp /= 10;
        }

        if(A <= sum && sum <= B) counter += i;
    }

    cout << counter << endl;


    return 0;
}