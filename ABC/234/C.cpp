#include <bits/stdc++.h>
using namespace std;

int main() {    
    long long k;
    cin >> k;
    bitset<64> bs(k);
    // cout << bs << endl;

    string bs_s = bs.to_string();
    size_t pos = bs_s.find('1');
    if (pos != string::npos) {
        bs_s = bs_s.substr(pos);
    } else {
        cout << '0' << endl;
        return 0;
    }

    for (char &ch : bs_s) {
        if (ch == '1'){
            ch = '2';
        }
    }
    cout << bs_s << endl;

    return 0;
}