//메모리: 108548KB, 시간: 64ms
#include <bits/stdc++.h>
using namespace std;

//dp 배열: 해당 시각에 파티장에 있는 영선이 친구들, 남은 친구들 몇명일 때 욱제가 파티에 머무르는 최대 시간 저장
int N, M, K, T, a, b, pt[301], dp[301][301][301];

int go(int time, int cur_fri, int left_fri) {
    if (time == N + 1) return 0;
    int& ret = dp[time][cur_fri][left_fri];
    if (ret == -1) {
        if (pt[time] <= 0) ret = max(ret, go(time + 1, 0, left_fri) + 1);
        else if (pt[time] <= cur_fri) ret = max(ret, go(time + 1, cur_fri, left_fri) + 1);
        else if (pt[time] - cur_fri > left_fri) ret = max(ret, go(time + 1, cur_fri, left_fri));
        else {
            ret = max(ret, go(time + 1, pt[time], left_fri - (pt[time] - cur_fri)) + 1); //친구들 go O
            ret = max(ret, go(time + 1, cur_fri, left_fri)); //친구들 go X
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K >> T;
    fill(pt, pt + 301, T);
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        for (int j = a; j < b; j++) pt[j]--;
    }
    memset(dp, -1, sizeof(dp));
    cout << go(1, 0, K) << '\n';

    return 0;
}