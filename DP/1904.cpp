//���̰� k�� ��� = ���̰� k-2���� 00�� ���� ��� + ���̰� k-1���� 1�� ���� ��� 
//��ȭ��: dp[1] = 1, dp[2] = 2�̸鼭 dp[k] = dp[k-1] + dp[k-2] �� �Ǻ���ġ ����
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