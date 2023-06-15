//메모리: 2032KB, 시간: 0ms
/*
#include <iostream>
#include <queue>
using namespace std;

int n, ret;
string expr;

string biOp(string a, string b, string op) {
    if (op == "+") return to_string(stoi(a) + stoi(b));
    else if (op == "-") return to_string(stoi(a) - stoi(b));
    else return to_string(stoi(a) * stoi(b));
}

int calculate(string expr) {
    queue<string> q;
    string a, b, op, tmp;
    for (int i = 0; i < expr.size();) {
        tmp = expr.substr(i, 1);
        if (tmp == "(") {
            a = expr.substr(i + 1, 1);
            op = expr.substr(i + 2, 1);
            b = expr.substr(i + 3, 1);
            q.push(biOp(a, b, op));
            i += 5;
        }
        else {
            q.push(tmp);
            i++;
        }
    }
    
    tmp = q.front(); q.pop();
    while (q.size()) {
        op = q.front(); q.pop();
        b = q.front(); q.pop();
        tmp = biOp(tmp, b, op);
    }
    return stoi(tmp);
}

void bracket(int idx) {
    if (expr.size() < 5 && idx + 2 >= expr.size()) return;

    while (idx + 2 < expr.size()) {
        expr.insert(idx, "(");
        expr.insert(idx + 4, ")"); 
        ret = max(ret, calculate(expr));
        bracket(idx + 6);
        expr.erase(idx + 4, 1);
        expr.erase(idx, 1);

        idx += 2;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> expr;
    ret = calculate(expr);
    bracket(0);
    cout << ret << '\n';

    return 0;
}
*/

//메모리: 2024KB, 시간: 0ms
#include <iostream>
#include <vector>
using namespace std;

int n, ret = -987654321;
string expr;
vector<int> nums;
vector<char> ops;

int calcul(char op, int a, int b) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    return a * b; 
}

void go(int num, int idx) {
    if (idx >= ops.size()) {
        ret = max(ret, num);
        return;
    }

    go(calcul(ops[idx], num, nums[idx + 1]), idx + 1);
    if (idx + 2 <= nums.size() - 1) {
        int tmp = calcul(ops[idx + 1], nums[idx + 1], nums[idx + 2]);
        go(calcul(ops[idx], num, tmp), idx + 2);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> expr;
    for (char c : expr) {
        if (c >= '0' && c <= '9') nums.push_back(c - '0');
        else ops.push_back(c);
    }
    go(nums[0], 0);
    cout << ret << '\n';

    return 0;
}