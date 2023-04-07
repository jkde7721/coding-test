/*
#include <iostream>
using namespace std;

int i;
string s, word[] = {"pi", "ka", "chu"}, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    while (i < 3) {
        auto it = s.find(word[i]);
        if (it == s.npos) { i++; continue; }
        s.replace(it, word[i].size(), " ");
        ret += " ";
    }
    if (s == ret) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}
*/

//�޸�, �ð��� ���� 2024KB, 0ms�� ���Ʒ� �ڵ� ��� ���������� �Ʒ� �ڵ尡 �� linear�ϰ� ����? O(n)
#include <iostream>
using namespace std;

string s;
bool yes = true;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s;
    for (int i = 0; i < s.size(); ) {
        if (i < s.size() - 1 && (s.substr(i, 2) == "pi" || s.substr(i, 2) == "ka")) i += 2;
        else if (i < s.size() - 2 && s.substr(i, 3) == "chu") i += 3;
        else { yes = false; break; }
    }
    if (yes) cout << "YES\n";
    else cout << "NO\n";

    return 0;
}