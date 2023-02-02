#include <iostream>

using namespace std;
int alpha[26];
string s;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        alpha[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        cout << alpha[i] << " ";
    }
    
    return 0;
}