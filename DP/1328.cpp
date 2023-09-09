//가장 낮은 높이의 빌딩의 위치 고려: 양끝, 가운데(해당 빌딩은 무시됨)
//메모리: 10068KB, 시간: 4ms
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

int n, l, r;
long long dp[101][101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l >> r;
    dp[1][1][1] = 1;
    for (int k = 2; k <= n; k++) {
        for (int i = 1; i <= k; i++) {
            for (int j = 1; j <= k; j++) {
                //가장 낮은 높이의 빌딩이 맨 앞에 있는 경우 + 맨 뒤에 있는 경우 + 가운데 있는 경우(n-2개)
                dp[k][i][j] = (dp[k-1][i-1][j] + dp[k-1][i][j-1] + dp[k-1][i][j] * (k-2)) % MOD;
            }
        }
    }
    cout << dp[n][l][r] << '\n';
    return 0;
}

//재귀 풀이
//메모리: 10068KB, 시간: 8ms
/*
#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;
typedef long long ll;

int n, l, r;
ll dp[101][101][101];

ll go(int n, int l, int r) {
    if (n == 1 && l == 1 && r == 1) return 1;
    if (n == 0 || n == 1) return 0;
    ll& ret = dp[n][l][r];
    if (ret == -1) ret = (go(n-1, l-1, r) + go(n-1, l, r-1) + go(n-1, l, r) * (n-2)) % MOD;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n >> l >> r;
    cout << go(n, l, r) << '\n';
    return 0;
}
*/