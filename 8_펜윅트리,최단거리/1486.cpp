//메모리: 3548KB, 시간: 252ms
//최대 정점 개수가 625로 크지만 O(n^3)의 플로이드-워셜 알고리즘 사용 가능 (시간초과 안남)
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int N, M, T, D, mt[625], dist[625][625], ret;
char c;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> T >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) { 
            cin >> c;
            if (c < 'a') mt[i*M+j] = c - 'A';
            else mt[i*M+j] = c - 'a' + 26;
        }
    }

    int dv[] = {-M, M, -1, +1}, nv;
    fill(&dist[0][0], &dist[0][0] + 625*625, INF);
    for (int i = 0; i < N*M; i++) dist[i][i] = 0;
    for (int i = 0; i < N*M; i++) {
        for (int k = 0; k < 4; k++) {
            if ((k == 2 && i % M == 0) || (k == 3 && i % M == M - 1)) continue;
            nv = i + dv[k];
            if (nv < 0 || nv >= N*M || abs(mt[nv] - mt[i]) > T) continue;
            dist[i][nv] = (mt[nv] > mt[i] ? (int)pow(mt[nv] - mt[i], 2) : 1);
        }
    }
    for (int k = 0; k < N*M; k++) {
        for (int i = 0; i < N*M; i++) {
            for (int j = 0; j < N*M; j++) {
                if (i == j) continue;
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    ret = mt[0];
    for (int i = 1; i < N*M; i++) {
        if (dist[0][i] + dist[i][0] <= D) ret = max(ret, mt[i]);
    }
    cout << ret << '\n';

    return 0;
}