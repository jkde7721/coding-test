#include <iostream>
#include <stack>
using namespace std;

int t;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> s;
        stack<char> stk;
        for (char c : s) {
            if (stk.size() && stk.top() == '(' && c == ')') stk.pop();
            else stk.push(c);
        }
        if (stk.empty()) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}