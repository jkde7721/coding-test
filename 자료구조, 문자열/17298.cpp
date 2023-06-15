#include <iostream>
#include <stack>
using namespace std;

int n, num[1000001], ret[1000001];
stack<int> stk;

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        while (stk.size() && num[stk.top()] < num[i]) {
            ret[stk.top()] = num[i]; stk.pop();
        }
        stk.push(i);
    }
    while (stk.size()) {
        ret[stk.top()] = -1; stk.pop();
    }
    for (int i = 1; i <= n; i++) {
        cout << ret[i] << ' ';
    }

    return 0;
}