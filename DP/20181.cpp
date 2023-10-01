//DP + 투포인터 + 누적합
//메모리: 3192KB, 시간: 12ms
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//dp 배열: 해당 위치까지 이동했을때 축적된 탈피 에너지의 최대값
int n, k, sum, eat[100001];
ll dp[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int s = 1, e = 1; e <= n; e++) {
        cin >> eat[e]; sum += eat[e];
        dp[e] = dp[e-1]; //현재 위치에서 먹지 않은 경우(초기화)
        while (sum >= k) {
            dp[e] = max(dp[e], dp[s-1] + sum - k);
            sum -= eat[s++];
        }
    }
    cout << dp[n] << '\n';
    return 0;
}

//dp 배열을 너무 엄격하게 잡음
//메모리: 9320KB, 시간: 20ms
/*
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

//dp 배열: 해당 위치에서 먹지 않거나, 처음 먹었을 때 축적된 탈피 에너지 최대값 저장
int n, k, s, e, sum, sat[100000];
ll dp[100000][2];
pair<int, int> info[100000]; //해당 위치에서 먹기 시작했을 때 축적된 탈피 에너지의 값과 만족도가 0이 되는 다음 위치 저장

ll go(int idx, bool eat) {
    if (idx == n) return 0;
    ll& ret = dp[idx][eat];
    if (ret == -1) {
        if (eat) ret = info[idx].first + max(go(info[idx].second, 0), go(info[idx].second, 1));
        else ret = max(go(idx + 1, 0), go(idx + 1, 1));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> sat[i];
    while (s < n) {
        if (sum >= k) {
            info[s] = {sum - k, e};
            sum -= sat[s++];
        }
        else if (e >= n) info[s++] = {0, n}; 
        else sum += sat[e++]; 
    }
    cout << max(go(0, 0), go(0, 1)) << '\n';
    return 0;
}
*/