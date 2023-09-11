#include <bits/stdc++.h>
#define MIN -1e9
using namespace std;

//dp 배열: N개의 수로 이루어진 1차원 배열에서 M개의 구간에 속한 수들의 총 합의 최대값 저장 (이전 수 포함 여부 관리)
int N, M, num[101], dp[101][51][2];

int go(int n, int m, bool inc) {
    if (n == 0) {
        if (m == 0) return 0;
        return MIN + MIN; //아래 if문 조건식과 다르도록
    }
    int& ret = dp[n][m][inc];
    if (ret == MIN) {
        //이전 수가 구간에 포함된 경우, 현재 수 구간에 포함하지 않거나 포함하거나
        if (inc) ret = max(go(n-1, m, false), go(n-1, m, true) + num[n]);
        //이전 수가 구간에 포함되지 않은 경우, 현재 수 구간에 포함하지 않거나 포함하거나
        else ret = max(go(n-1, m, false), go(n-1, m-1, true) + num[n]);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(&dp[0][0][0], &dp[0][0][0] + 101*51*2, MIN);
    cin >> N >> M;
    for (int i = 1; i <= N; i++) cin >> num[i];
    cout << go(N, M, 0) << '\n';
    return 0;
}