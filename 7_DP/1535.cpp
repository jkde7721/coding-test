//�޸�: 2020KB, �ð�: 0ms
#include <bits/stdc++.h>
using namespace std;

//dp �迭: �ش� �ε��� ü������ ���� �� �ִ� ����� �ִ� ����
int n, l[20], j[20], dp[100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 0; i < n; i++) cin >> j[i];
    for (int i = 0; i < n; i++) {
        for (int k = 99; k >= l[i]; k--) {
            dp[k] = max(dp[k], dp[k - l[i]] + j[i]);
        }
    }
    cout << dp[99] << '\n';

    return 0;
}