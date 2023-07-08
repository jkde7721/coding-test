//메모리: 14508KB, 시간: 136ms
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, y, x, ny, nx, nny, nnx, ret = INF, _map[1000][1000], visited[1000][1000], visited2[1000][1000];
queue<pair<int, int>> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &_map[i][j]);
        }
    }
    q.push({n-1, m-1}); visited[n-1][m-1] = 1;
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || _map[ny][nx]) continue;
            q.push({ny, nx}); visited[ny][nx] = visited[y][x] + 1;
        }
    }
    if (visited[0][0]) ret = visited[0][0];
    q.push({0, 0}); visited2[0][0] = 1;
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited2[ny][nx]) continue;
            if (_map[ny][nx]) {
                for (int j = 0; j < 4; j++) {
                    nny = ny + dy[j]; nnx = nx + dx[j];
                    if (nny < 0 || nny >= n || nnx < 0 || nnx >= m || visited2[nny][nnx] || !visited[nny][nnx]) continue;
                    ret = min(ret, visited2[y][x] + 1 + visited[nny][nnx]);
                }
                continue;
            }
            q.push({ny, nx}); visited2[ny][nx] = visited2[y][x] + 1;
        }
    }
    cout << (ret == INF ? -1 : ret) << '\n';
    return 0;
}

//다익스트라 풀이도 가능?