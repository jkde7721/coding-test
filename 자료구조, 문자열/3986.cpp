#include <iostream>
#include <stack>
using namespace std;

int n, ret;
string s;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s;
        stack<char> stk;
        
        for (char c : s) {
            if (!stk.empty() && stk.top() == c) stk.pop();
            else stk.push(c);
        }
        if (stk.empty()) ret++;
    }
    cout << ret << '\n';

    return 0;
}