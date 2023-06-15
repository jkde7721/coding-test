//메모리: 6116KB, 시간: 28ms
/*
그냥 완전탐색으로 풀면 시간복잡도 (N - 1)!(N은 도시의 수로 2이상 16이하)으로 시간초과 발생
Top-Down DP로 메모이제이션 필요 
→ 어디어디를 방문했을 때 현재 위치에서 목적지(원래의 출발지)까지 가는 최소 비용 저장
이때 출발지는 0번 도시로 고정 → 순회이기 때문에 출발지 상관X ex. 0 → 1 → 2 → 0 / 2 → 0 → 1 → 2 모두 same
*/
#include <bits/stdc++.h>
#define INF 987654321
#define MAX_N 16
using namespace std;

int n, w[MAX_N][MAX_N], cost[MAX_N][(1 << MAX_N)];

//cur → 0번 도시(출발지)까지 순회하는데 드는 최소 비용 반환
int go(int cur, int visited) {
    if (visited == ((1 << n) - 1)) { //모두 방문
        //맨 마지막으로 방문한 도시에서 0번 도시로 이동가능해야 순회 가능
        return (w[cur][0] ? w[cur][0] : INF);
    }
    int &ret = cost[cur][visited];
    if (ret == -1) {
        ret = INF;
        for (int i = 0; i < n; i++) {
            if (!w[cur][i] || visited & (1 << i)) continue;
            ret = min(ret, go(i, visited | (1 << i)) + w[cur][i]);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(cost, -1, sizeof(cost));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> w[i][j];
    }
    cout << go(0, 1) << '\n';

    return 0;
}