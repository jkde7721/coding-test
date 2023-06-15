#include <iostream>
#include <algorithm>
using namespace std;

int alpha[26];
string s, ret, odd;

int main() {
    cin >> s;
    for (char c : s) {
        alpha[c - 'A']++;
    }

    for (int i = 0; i < 26; i++) {
        ret += string(alpha[i] / 2, i + 'A');
        if (alpha[i] % 2 == 1) {
            odd += i + 'A';
        }
    }
    if (odd.size() > 1 || s.size() % 2 == 0 && !odd.empty()) {
        cout << "I'm Sorry Hansoo\n";
    }
    else {
        string tmp = ret;
        reverse(tmp.begin(), tmp.end());
        ret += odd + tmp;
        cout << ret << '\n';
    }
    
    return 0;
}