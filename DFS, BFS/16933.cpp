//메모리: 92324KB, 시간: 1072ms
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

typedef struct {
    int y, x, crush;
    bool day; //0-낮, 1-밤
} Spot;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, k, y, x, ny, nx, crush, dist[1000][1000][11][2], ret = INF;
bool _map[1000][1000], day;
Spot cur;
queue<Spot> q;

int main() {
    fill(&dist[0][0][0][0], &dist[0][0][0][0] + 1000*1000*11*2, INF);
    scanf("%d %d %d", &n, &m, &k);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%1d", &_map[i][j]);
    }
    dist[0][0][0][0] = 1; q.push({0, 0, 0, 0});
    while (q.size()) {
        cur = q.front(); q.pop();
        y = cur.y; x = cur.x; crush = cur.crush; day = cur.day;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (_map[ny][nx] && crush < k && dist[ny][nx][crush + 1][1] > dist[y][x][crush][day] + 1 + day) {
                dist[ny][nx][crush + 1][1] = dist[y][x][crush][day] + 1 + day;
                q.push({ny, nx, crush + 1, 1});
            }
            else if (!_map[ny][nx] && dist[ny][nx][crush][!day] > dist[y][x][crush][day] + 1) {
                dist[ny][nx][crush][!day] = dist[y][x][crush][day] + 1;
                q.push({ny, nx, crush, !day});
            }
        }
    }
    for (int i = 0; i <= k; i++) ret = min(ret, min(dist[n-1][m-1][i][0], dist[n-1][m-1][i][1]));
    cout << (ret == INF ? -1 : ret) << '\n';
    return 0;
}