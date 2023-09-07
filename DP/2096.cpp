//슬라이딩 윈도우 풀이
//메모리: 2020KB, 시간: 16ms
#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, dp[2][3], dp2[2][3];

//이전 행과 현재 행만 신경쓰면 됨
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        dp[1][0] = a + max(dp[0][0], dp[0][1]);
        dp[1][1] = b + max(max(dp[0][0], dp[0][1]), dp[0][2]);
        dp[1][2] = c + max(dp[0][1], dp[0][2]);
        memcpy(dp[0], dp[1], sizeof(dp[1]));
        dp2[1][0] = a + min(dp2[0][0], dp2[0][1]);
        dp2[1][1] = b + min(min(dp2[0][0], dp2[0][1]), dp2[0][2]);
        dp2[1][2] = c + min(dp2[0][1], dp2[0][2]);
        memcpy(dp2[0], dp2[1], sizeof(dp2[1]));
    }
    cout << max(max(dp[0][0], dp[0][1]), dp[0][2]) << ' ';
    cout << min(min(dp2[0][0], dp2[0][1]), dp2[0][2]) << '\n';
    return 0;
}

//일반 DP 풀이
//메모리: 3484KB, 시간: 8ms
/*
#include <bits/stdc++.h>
using namespace std;

//메모리 초과로 int형 2차원 배열 2개 선언 불가
int n, dp[100001][3];
char num[100001][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num[i][0] >> num[i][1] >> num[i][2];
        dp[i][0] = (num[i][0] - '0') + max(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = (num[i][1] - '0') + max(max(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
        dp[i][2] = (num[i][2] - '0') + max(dp[i-1][1], dp[i-1][2]);
    }
    cout << max(max(dp[n][0], dp[n][1]), dp[n][2]) << ' ';
    memset(dp, 0, sizeof(dp));
    for (int i = 1; i <= n; i++) {
        dp[i][0] = (num[i][0] - '0') + min(dp[i-1][0], dp[i-1][1]);
        dp[i][1] = (num[i][1] - '0') + min(min(dp[i-1][0], dp[i-1][1]), dp[i-1][2]);
        dp[i][2] = (num[i][2] - '0') + min(dp[i-1][1], dp[i-1][2]);
    }
    cout << min(min(dp[n][0], dp[n][1]), dp[n][2]) << '\n';
    return 0;
}
*/