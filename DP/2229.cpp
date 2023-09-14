#include <bits/stdc++.h>
using namespace std;

//dp 배열: n명의 학생들에 대해 조를 나누었을 때 조가 잘 짜여진 정도의 최대값 저장
//전체 경우는 맨 마지막 학생 포함 1명으로 구성된 경우, 2명 ... n명으로 구성된 경우로 나뉨 → 전체 경우를 단순화해서 보기
int n, score[1001], dp[1001], mx, mn;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> score[i];
    for (int i = 2; i <= n; i++) { //i번째가 맨 마지막 학생
        mx = mn = score[i];
        for (int j = 1; j <= i; j++) { //맨 마지막 학생 포함 j명
            dp[i] = max(dp[i], dp[i-j] + mx - mn);
            mx = max(mx, score[i-j]);
            mn = min(mn, score[i-j]);
        }
    }
    cout << dp[n] << '\n';
    return 0;
}