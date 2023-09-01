#include <bits/stdc++.h>
using namespace std;

int n, dp[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    //n이 홀수일 때 경우의 수는 0
    //ex. n이 8인 경우, (3x6,3x2), (3x4,3x4), (3x2,3x6) 각 경우의 수의 합
    //(3x4,3x4), (3x2,3x6)인 경우는 앞의 (3x6,3x2)와 중복되는 경우가 존재하므로 유일한 패턴만 고려
    cin >> n; dp[2] = 3;
    for (int i = 4; i <= n; i += 2) {
        dp[i] += dp[i-2] * dp[2];
        for (int j = 4; j < i; j += 2) dp[i] += dp[i-j] * 2; //이때 2는 3*j 벽에서만 발생하는 유일한 패턴 개수
        dp[i] += 2; //3xi 벽에서만 발생하는 유일한 패턴 2개
    }
    cout << dp[n] << '\n';
    return 0;
}