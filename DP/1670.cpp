#include <bits/stdc++.h>
#define MOD 987654321
using namespace std;
typedef long long ll;

ll n, dp[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    dp[0] = dp[2] = 1; dp[4] = 2;
    for (int i = 6; i <= n; i += 2) {
        for (int j = 2; j <= i; j += 2) {
            dp[i] += (dp[j - 2] * dp[i - j]) % MOD;
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}