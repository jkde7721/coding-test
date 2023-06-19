#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

//dp 배열: 길이가 n인 계단 수의 모든 경우에서 n번째 수가 0~9인 경우의 수 각각 저장
int n, dp[101][10], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    dp[1][0] = 0;
    for (int i = 1; i < 10; i++) dp[1][i] = 1;
    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < 10; j++) {
            dp[i][j] = ((j-1 < 0 ? 0 : dp[i-1][j-1]) + (j+1 > 9 ? 0 : dp[i-1][j+1])) % MOD;
        }
    }
    for (int i = 0; i < 10; i++) {
        ret += dp[n][i];
        ret %= MOD;
    }
    cout << ret << '\n';
    return 0;
}