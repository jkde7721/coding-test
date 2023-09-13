//메모리: 3040KB, 시간: 40ms
#include <bits/stdc++.h>
#define MIN -1e9
using namespace std;

//dp 배열: 1번 도시에서 해당 도시까지 해당 개수의 도시를 지나갔을 때 기내식 점수의 총 합의 최대값 저장
int n, m, k, a, b, c, dp[301][301], ret = MIN;
vector<pair<int, int>> adj[301];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b >> c;
        if (a < b) adj[a].push_back({b, c});
    }
    fill(&dp[0][0], &dp[0][0] + 301*301, MIN);
    dp[1][1] = 0;
    for (int i = 1; i < n; i++) {
        for (int j = 2; j <= m; j++) {
            for (auto it : adj[i]) {
                if (dp[i][j-1] == MIN) continue;
                dp[it.first][j] = max(dp[it.first][j], dp[i][j-1] + it.second);
            }
        }
    }
    for (int i = 1; i <= m; i++) ret = max(ret, dp[n][i]);
    cout << ret << '\n';
    return 0;
}