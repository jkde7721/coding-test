//크게 2가지 case로 나뉨 (완전순열, 교란순열)
//1. n에게 k의 모자가 할당되고, k에게 n의 모자가 할당되는 경우 (짝을 이루는 경우)
//2. n에게 k의 모자가 할당되고, k에게 i의 모자가 할당되는 경우 (짝을 이루지 못한 경우) → n의 모자는 k에게 할당되지 못하므로 n의 모자는 k의 모자처럼 간주
#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

long long n, dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; dp[2] = 1;
    for (int i = 3; i <= n; i++) {
        dp[i] = (i-1) * dp[i-2] + (i-1) * dp[i-1];
        dp[i] %= MOD;
    }
    cout << dp[n] << '\n';
    return 0;
}