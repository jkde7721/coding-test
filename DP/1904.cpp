//길이가 k인 경우 = 길이가 k-2에서 00을 더한 경우 + 길이가 k-1에서 1을 더한 경우 
//점화식: dp[1] = 1, dp[2] = 2이면서 dp[k] = dp[k-1] + dp[k-2] → 피보나치 수열
#include <bits/stdc++.h>
#define MOD 15746
using namespace std;

int n, dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    dp[1] = 1; dp[2] = 2;
    for (int i = 3; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
    }
    cout << dp[n] << '\n';
    return 0;
}