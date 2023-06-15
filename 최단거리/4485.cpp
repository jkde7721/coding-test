//메모리: 2276KB, 시간: 4ms
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, idx, y, x, ny, nx, _dist, cave[125][125], dist[125][125];
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while ((cin >> n) && n != 0) {
        fill(&dist[0][0], &dist[0][0] + 125*125, INF);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) cin >> cave[i][j];
        }
        dist[0][0] = cave[0][0]; pq.push({cave[0][0], 0, 0});
        while (pq.size()) {
            tie(_dist, y, x) = pq.top(); pq.pop();
            if (dist[y][x] < _dist) continue;
            for (int i = 0; i < 4; i++) {
                ny = y + dy[i]; nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
                if (dist[ny][nx] > _dist + cave[ny][nx]) {
                    dist[ny][nx] = _dist + cave[ny][nx];
                    pq.push({dist[ny][nx], ny, nx});
                }
            }
        }
        cout << "Problem " << (++idx) << ": " << dist[n - 1][n - 1] << '\n';
    }
    return 0;
}