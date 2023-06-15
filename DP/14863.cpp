//메모리: 41084KB, 시간: 80ms
#include <iostream>
#include <cstring>
#define MIN -987654321
using namespace std;

int n, k, dp[100][100001];
pair<int, int> walk[100], bike[100];

//해당 idx 위치에서 t 시간이 남았을 때 모금할 수 있는 최대 금액 반환 (경산까지 갈 수 없는 경우에는 아주 작은 값 반환)
int go(int idx, int t) {
    if (idx == n) return 0;
    int& ret = dp[idx][t];
    if (ret == -1) {
        ret = MIN;
        if (t >= walk[idx].first) ret = max(ret, go(idx + 1, t - walk[idx].first) + walk[idx].second);
        if (t >= bike[idx].first) ret = max(ret, go(idx + 1, t - bike[idx].first) + bike[idx].second);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> walk[i].first >> walk[i].second >> bike[i].first >> bike[i].second;
    }
    cout << go(0, k) << '\n';

    return 0;
}

//재귀 사용하지 않고 1차원 배열만으로 풀어보기