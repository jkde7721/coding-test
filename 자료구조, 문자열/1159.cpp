#include <iostream>

using namespace std;
int n, alpha[26];
string s;
bool isPredaja = true;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        alpha[s[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++) {
        if (alpha[i] >= 5) {
            cout << char(i + 'a');
            isPredaja = false;
        }
    }
    if (isPredaja) cout << "PREDAJA";
    
    return 0;
}