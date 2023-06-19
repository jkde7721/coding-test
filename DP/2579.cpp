#include <bits/stdc++.h>
#define MIN -987654321
using namespace std;

//dp �迭: �ش� ��� �ε����κ��� ���� �� �ִ� �� ������ �ִ� (�������� ���/���� ��� �� �ش� ���)
int n, step[300], dp[2][300];

int go(bool pre, int idx) {
    if (idx >= n) return MIN;
    if (idx == n - 1) return step[n - 1];
    int& ret = dp[pre][idx];
    if (!ret) {
        if (pre) ret = step[idx] + go(0, idx + 2);
        else ret = step[idx] + max(go(1, idx + 1), go(0, idx + 2));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> step[i];
    cout << max(go(0, 0), go(0, 1)) << '\n';
    return 0;
}