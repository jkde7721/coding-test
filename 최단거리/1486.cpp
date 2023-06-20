//메모리: 3548KB, 시간: 252ms
//최대 정점 개수가 625로 크지만 O(n^3)의 플로이드-워셜 알고리즘 사용 가능 (시간초과 안남)
/*
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
*/

//메모리: 2036KB, 시간: 0ms
//다익스트라 풀이
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int N, M, T, D, m[25][25], m2[25][25], dist[25][25], dist2[25][25], ret;
char c;

void dijkstra(int m[25][25], int dist[25][25]) {
    int y, x, ny, nx, d, w;
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
    fill(&dist[0][0], &dist[0][0] + 25*25, INF);
    dist[0][0] = 0; pq.push({0, 0, 0});
    while (pq.size()) {
        tie(d, y, x) = pq.top(); pq.pop();
        if (d > dist[y][x]) continue;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 0 || ny >= N || nx < 0 || nx >= M || abs(m[ny][nx] - m[y][x]) > T) continue;
            w = (m[ny][nx] <= m[y][x] ? 1 : pow(m[ny][nx] - m[y][x], 2));
            if (dist[ny][nx] > d + w) {
                dist[ny][nx] = d + w; pq.push({dist[ny][nx], ny, nx});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> T >> D;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c;
            m[i][j] = (c <= 'Z' ? c - 'A' : c - 'a' + 26);
            m2[i][j] = 51 - m[i][j]; //높이 반전
        }
    }
    dijkstra(m, dist); //go
    dijkstra(m2, dist2); //come
    ret = m[0][0];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (dist[i][j] + dist2[i][j] <= D) ret = max(ret, m[i][j]);
        }
    }
    cout << ret << '\n';
    return 0;
}