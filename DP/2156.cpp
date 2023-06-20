#include <bits/stdc++.h>
using namespace std;

//dp �迭: ���� ������ ���� �������� �󸶳� ���̴����� ���� �ش� ������ �����κ��� ���� �� �ִ� �������� �ִ� �� ����
int n, g[10000], dp[3][10000];

int go(int cnt, int idx) {
    if (idx == n) return 0;
    int& ret = dp[cnt][idx];
    if (ret == -1) {
        ret = go(0, idx + 1);
        if (cnt < 2) ret = max(ret, go(cnt + 1, idx + 1) + g[idx]);
    }
    return ret;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) cin >> g[i];
    cout << go(0, 0) << '\n';
    return 0;
}