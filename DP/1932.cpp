#include <bits/stdc++.h>
using namespace std;

//dp 배열: 해당 인덱스 위치로부터 합이 최대가 되는 경로에 있는 수의 합 저장
int n, dp[500][500], num[500][500];

int go(int y, int x) {
    if (y == n) return 0;
    int& ret = dp[y][x];
    if (ret == -1) {
        ret = num[y][x] + max(go(y + 1, x), go(y + 1, x + 1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) cin >> num[i][j];
    }
    cout << go(0, 0) << '\n';
    return 0;
}