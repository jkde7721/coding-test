#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

//dp �迭: ���̰� n�� ��� ���� ��� ��쿡�� n��° ���� 0~9�� ����� �� ���� ����
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