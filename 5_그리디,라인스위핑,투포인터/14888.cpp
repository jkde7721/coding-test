//메모리: 2024KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;

int n, num[11], op[4], mx = -1000000000, mn = 1000000000;
stack<int> stk;

int cal(int a, int b, int op) {
    if (op == 0) return a + b;
    if (op == 1) return a - b;
    if (op == 2) return a * b;
    return a / b;
}

void go(int idx) {
    if (idx == n) {
        mx = max(mx, stk.top());
        mn = min(mn, stk.top());
        return;
    }
    for (int i = 0; i < 4; i++) {
        if (!op[i]) continue;
        op[i]--;
        stk.push(cal(stk.top(), num[idx], i));
        go(idx + 1);
        stk.pop();
        op[i]++;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> num[i];
    for (int i = 0; i < 4; i++) cin >> op[i];
    stk.push(num[0]);
    go(1);
    cout << mx << '\n' << mn << '\n';

    return 0;
}