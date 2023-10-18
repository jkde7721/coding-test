//메모리: 47684KB, 시간: 620ms
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, k, y, x, ny, nx, crush, dist[1000][1000][11], ret = INF;
bool _map[1000][1000];
queue<tuple<int, int, int>> q;

int main() {
    fill(&dist[0][0][0], &dist[0][0][0] + 1000*1000*11, INF);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%1d", &_map[i][j]);
    }
    dist[0][0][0] = 1; q.push({0, 0, 0});
    while (q.size()) {
        tie(y, x, crush) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (_map[ny][nx] && crush < k && dist[ny][nx][crush + 1] > dist[y][x][crush] + 1) {
                dist[ny][nx][crush + 1] = dist[y][x][crush] + 1;
                q.push({ny, nx, crush + 1});
            }
            else if (!_map[ny][nx] && dist[ny][nx][crush] > dist[y][x][crush] + 1) {
                dist[ny][nx][crush] = dist[y][x][crush] + 1;
                q.push({ny, nx, crush});
            }
        }
    }
    for (int i = 0; i <= k; i++) ret = min(ret, dist[n-1][m-1][i]);
    cout << (ret == INF ? -1 : ret) << '\n';
    return 0;
}