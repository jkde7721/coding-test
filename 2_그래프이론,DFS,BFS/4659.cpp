#include <iostream>
using namespace std;

string s;
int vo, co;
bool isVo, isAccept;

int main() {
    while (1) {
        cin >> s;
        if (s == "end") return 0;

        int pre = 'A';
        vo = 0; co = 0;
        isVo = false; isAccept = true;
        for (char c : s) {
            if (string("aeiou").find(c) != string::npos) {
                isVo = true;
                vo++;
                co = 0;
            }
            else {
                co++;
                vo = 0;
            }
            
            if (vo >= 3 || co >= 3 || (c == pre && c != 'e' && c != 'o')) {
                isAccept = false;
                break;
            }
            pre = c;
        }
        if (isAccept && isVo) cout << "<" << s << "> is acceptable.\n";
        else cout << "<" << s << "> is not acceptable.\n";
    }

    return 0;
}