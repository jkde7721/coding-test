#include <iostream>
#define INF 987654321
using namespace std;

//dp 배열: 각 경찰차에 해당 번호의 사건이 배정된 경우 마지막 사건까지의 최소 이동거리 저장
int n, w, dp[1002][1002];
pair<int, int> pos[1002];

int getDist(int cur, int next) {
    return abs(pos[cur].first - pos[next].first) + abs(pos[cur].second - pos[next].second);
}

int go(int a, int b) {
    if (a == w + 1 || b == w + 1) return 0;
    int& ret = dp[a][b];
    if (ret == INF) {
        int next = max(a, b) + 1;
        ret = min(ret, go(next, b) + getDist(a, next)); //경찰차1 go
        ret = min(ret, go(a, next) + getDist(b, next)); //경찰차2 go
    }
    return ret;
}

void trace() {
    int a = 0, b = 1, next = 2;
    while (next <= w + 1) {
        if (dp[next][b] + getDist(a, next) < dp[a][next] + getDist(b, next)) {
            cout << "1\n";
            a = next++;
        }
        else {
            cout << "2\n";
            b = next++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(&dp[0][0], &dp[0][0] + 1002*1002, INF);
    cin >> n >> w;
    pos[0].first = pos[0].second = 1;
    pos[1].first = pos[1].second = n;
    for (int i = 2; i < w + 2; i++) cin >> pos[i].first >> pos[i].second;
    cout << go(0, 1) << '\n';
    trace();

    return 0;
}