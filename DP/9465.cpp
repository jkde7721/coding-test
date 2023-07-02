//Top-Down 방식 풀이 
//메모리: 8536KB, 시간: 108ms
/*
#include <bits/stdc++.h>
using namespace std;

//dp 배열: 해당 열 이전에 0행 선택, 1행 선택, 아무것도 선택X 경우에, 해당 열로부터 얻을 수 있는 최대 스티커 점수 저장
int t, n, _map[2][100000], dp[3][100000];

int go(int ch, int idx) {
    if (idx >= n) return 0;
    int& ret = dp[ch][idx];
    if (ret == -1) {
        ret = max(ret, go(2, idx + 1));
        if (ch != 1) ret = max(ret, go(1, idx + 1) + _map[1][idx]);
        if (ch != 0) ret = max(ret, go(0, idx + 1) + _map[0][idx]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        memset(dp, -1, sizeof(dp));
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) cin >> _map[i][j];
        }
        cout << go(2, 0) << '\n';
    }
    return 0;
}
*/

//Bottom-Up 풀이
//메모리: 3972KB, 시간: 112ms
#include <bits/stdc++.h>
using namespace std;

//dp 배열: 해당 열에서 0행 선택, 1행 선택, 아무것도 선택X 경우에, 해당 열까지 얻을 수 있는 최대 스티커 점수 저장
int t, n, _map[2][100000], dp[3][100000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < n; j++) cin >> _map[i][j];
        }
        dp[0][0] = _map[0][0]; dp[1][0] = _map[1][0];
        for (int i = 1; i < n; i++) {
            dp[0][i] = max(dp[1][i-1], dp[2][i-1]) + _map[0][i];
            dp[1][i] = max(dp[0][i-1], dp[2][i-1]) + _map[1][i];
            dp[2][i] = max(max(dp[0][i-1], dp[1][i-1]), dp[2][i-1]);
        }
        cout << max(max(dp[0][n-1], dp[1][n-1]), dp[2][n-1]) << '\n';
    }
    return 0;
}