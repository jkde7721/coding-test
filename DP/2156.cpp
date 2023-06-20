#include <bits/stdc++.h>
using namespace std;

//dp 배열: 직전 포도주 잔을 연속으로 얼마나 마셨는지에 따라 해당 포도주 잔으로부터 마실 수 있는 포도주의 최대 양 저장
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