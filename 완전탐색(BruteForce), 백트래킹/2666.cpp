//완전탐색 풀이
//메모리: 2020KB, 시간: 8ms
#include <bits/stdc++.h>
using namespace std;

int n, a, b, m, num[20], ret = 1e9;

void go(int idx, int a, int b, int cnt) {
    if (idx == m) { ret = min(ret, cnt); return; }
    go(idx + 1, num[idx], b, cnt + abs(a-num[idx]));
    go(idx + 1, a, num[idx], cnt + abs(b-num[idx]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++) cin >> num[i];
    go(0, a, b, 0);
    cout << ret << '\n';
    return 0;
}

//DP 풀이
//메모리: 2056KB, 시간: 0ms
/*
#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;

//dp 배열: 현재 단계에서 해당 문이 열려있는 상태가 되기 위한 최소 문 이동 횟수 저장
int n, a, b, m, dp[21][21][21], num, ret = MAX;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b >> m;
    fill(&dp[0][0][0], &dp[0][0][0] + 21*21*21, MAX); dp[0][min(a,b)][max(a,b)] = 0; //초기 상태
    for (int k = 1; k <= m; k++) {
        cin >> num;
        for (int r = 1; r <= n; r++) { //현재 단계에서 가능한 열려있는 문의 상태는 (1, num), (2, num) ... (num, n) 
            //이전 단계에서 열려있는 문의 상태로부터 계산
            for (int i = 1; i <= n; i++) {
                for (int j = i + 1; j <= n; j++) {
                    if (r < num) dp[k][r][num] = min(dp[k][r][num], dp[k-1][i][j] + abs(r-i) + abs(num-j));
                    else if (r > num) dp[k][num][r] = min(dp[k][num][r], dp[k-1][i][j] + abs(num-i) + abs(r-j));
                    //r == num는 1개의 문만 열린 상태이므로 불가능
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (i < num) ret = min(ret, dp[m][i][num]);
        else if (i > num) ret = min(ret, dp[m][num][i]);
    }
    cout << ret << '\n';
    return 0;
}
*/