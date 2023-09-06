#include <bits/stdc++.h>
#define MOD 1000000
using namespace std;

//현재 숫자는 앞의 숫자와 같이 해석되거나 혼자 해석됨
int dp[5000][2], n, num;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> s; n = s.size(); 
    if (s[0] != '0') dp[0][0] = 1;
    for (int i = 1; i < n; i++) {
        num = (s[i-1] - '0') * 10 + (s[i] - '0');
        if (s[i] != '0') { dp[i][0] = dp[i-1][0] + dp[i-1][1]; dp[i][0] %= MOD; }
        if (num >= 10 && num <= 26) dp[i][1] = dp[i-1][0];
    }
    cout << (dp[n-1][0] + dp[n-1][1]) % MOD << '\n';
    return 0;
}