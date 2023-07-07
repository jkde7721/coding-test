//중위 표기식 → 후위 표기식 변환
#include <bits/stdc++.h>
using namespace std;

char tmp;
string expr, ret;
stack<char> stk;

int getPrior(char c) {
    if (c == '+' || c == '-') return 1;
    else if (c == '*' || c == '/') return 2;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> expr;
    for (char c : expr) {
        if (c >= 'A' && c <= 'Z') ret.push_back(c);
        else {
            while (c != '(' && stk.size() && getPrior(stk.top()) >= getPrior(c)) {
                tmp = stk.top(); stk.pop();
                if (tmp == '(' && c == ')') break;
                ret.push_back(tmp);
            }
            if (c != ')') stk.push(c);
        }
    }
    while (stk.size()) { ret.push_back(stk.top()); stk.pop(); }
    cout << ret << '\n';
    return 0;
}