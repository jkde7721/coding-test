#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

//dp 배열: 0부터 N까지의 정수 K개를 더해서 그 합이 N이 되는 경우의 수 저장
int n, k, dp[201][201];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 1; i <= n; i++) dp[i][1] = 1;
    for (int i = 1; i <= k; i++) dp[0][i] = 1;
    for (int i = 1; i <= k; i++) dp[1][i] = i;

    //점화식: dp[N][K] = dp[0][K-1] + dp[1][K-1] + ... + dp[N][K-1] (K개의 숫자 중 처음 하나를 0 ... N이라고 가정)
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            for (int m = 0; m <= i; m++) {
                dp[i][j] += dp[m][j-1];
                dp[i][j] %= MOD;
            }
        }
    }
    
    //또는 dp 배열에 특정 규칙 존재하기 때문에 다음과 같은 풀이 가능
    /*
    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= k; j++) {
            dp[i][j] = (dp[i-1][j] + dp[i][j-1]) % MOD;
        }
    }
    */
    cout << dp[n][k] << '\n';
    return 0;
}