#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

int main() {
    string s;

    cin >> s;
    string sub_s = s.substr(s.length()-3);

    int number = atoi(sub_s.c_str());

    if (number == 316) {
        cout << "No" << endl;
    } else if (number >= 1 && number <= 349) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
//15