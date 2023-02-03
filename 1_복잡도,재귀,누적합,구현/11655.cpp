#include <iostream>

using namespace std;
string s;
int tmp;

int main() {
    getline(cin, s);
    for (int i = 0; i < s.size(); i++) {
        if (s[i] >= 'A' && s[i] <= 'Z' || s[i] >= 'a' && s[i] <= 'z') {
            tmp = s[i] + 13;
            if (tmp > 'Z' && tmp <= 'Z' + 13 || tmp > 'z') {
                tmp -= 26;
            }
            s[i] = char(tmp);
        }
    }
    cout << s << "\n";

    return 0;
}