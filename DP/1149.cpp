#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

//dp 배열: 이전 집의 색이 R, G, B 중 하나일 때, 현재 집 이후의 모든 집을 색칠하는 최소 비용 저장
int n, dp[1000][3], rgb[1000][3];

int go(int idx, int color) {
    if (idx == n) return 0;
    int& ret = dp[idx][color];
    if (ret == INF) {
        for (int i = 0; i < 3; i++) {
            if (idx > 0 && i == color) continue;
            ret = min(ret, rgb[idx][i] + go(idx + 1, i));
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(&dp[0][0], &dp[0][0] + 1000*3, INF);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> rgb[i][0] >> rgb[i][1] >> rgb[i][2];
    cout << go(0, 0) << '\n';
    return 0;
}