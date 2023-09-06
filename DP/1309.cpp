//메모리: 3192KB, 시간: 0ms
#include <bits/stdc++.h>
#define MOD 9901
using namespace std;

//우리의 3가지 상태: 모두 사자 없음, 왼쪽에 사자 있음, 오른쪽에 사자 있음
int n, dp[100001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; dp[1][0] = dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i <= n; i++) {
        dp[i][0] = dp[i-1][0] + dp[i-1][1] + dp[i-1][2];
        dp[i][1] = dp[i-1][0] + dp[i-1][2]; //현재 왼쪽에 사자가 있으려면, 앞에서는 사자가 없거나 오른쪽에 사자가 있어야 함
        dp[i][2] = dp[i-1][0] + dp[i-1][1];
        dp[i][0] %= MOD; dp[i][1] %= MOD; dp[i][2] %= MOD;
    }
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD << '\n';
    return 0;
}