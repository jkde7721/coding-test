#include <iostream>
#include <stack>
using namespace std;

string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    while (1) {
        getline(cin, s);
        if (s == ".") break;

        stack<char> stk;
        for (char c : s) {
            if (c != '(' && c != ')' && c != '[' && c != ']') continue;
            if (stk.size() && (stk.top() == '(' && c == ')' || stk.top() == '[' && c == ']')) {
                stk.pop();
            }
            else stk.push(c);
        }
        if (stk.empty()) cout << "yes\n";
        else cout << "no\n";
    }

    return 0;
}