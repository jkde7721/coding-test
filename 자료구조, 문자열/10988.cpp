#include <iostream>
#include <algorithm>

using namespace std;
string s, tmp;

int main() {
    cin >> s;
    tmp = s;
    reverse(s.begin(), s.end());

    if (s == tmp) {
        cout << "1\n";
    }
    else {
        cout << "0\n";
    }
    
    return 0;
}