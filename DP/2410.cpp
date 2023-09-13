//메모리: 5928KB, 시간: 44ms
#include <bits/stdc++.h>
#define MOD 1000000000
using namespace std;

int n, dp[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; 
    dp[0] = dp[1] = 1;
    for (int i = 1; i <= n; i *= 2) {
        for (int j = 2; j <= n; j++) {
            if (i > j) continue;
            dp[j] = (dp[j] + dp[j-i]) % MOD;
        }
    }
    //시간복잡도 감소
    /*
    dp[1] = 1;
    for(i = 2; i <= n; i++){
        if (i % 2) dp[i] = dp[i - 1]; //홀수
        else dp[i] = (dp[i - 1] + dp[i / 2]) % MOD; //짝수 (1이 포함되거나 포함되지 않거나)
    }
    */
    cout << dp[n] << '\n';
    return 0;
}