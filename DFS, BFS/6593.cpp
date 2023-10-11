//3차원 행렬에서의 BFS
#include <bits/stdc++.h>
using namespace std;

const int dz[] = {0, 0, 0, 0, 1, -1}, dy[] = {-1, 0, 1, 0, 0, 0}, dx[] = {0, 1, 0, -1, 0, 0};
int l, r, c, z, y, x, nz, ny, nx, ez, ey, ex, visited[30][30][30];
char _map[30][30][30];
queue<tuple<int, int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0) break;
        memset(visited, 0, sizeof(visited));
        for (int k = 0; k < l; k++) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    cin >> _map[k][i][j];
                    if (_map[k][i][j] == 'S') { q.push({k, i, j}); visited[k][i][j] = 1; }
                    if (_map[k][i][j] == 'E') { ez = k; ey = i; ex = j; }
                }
            }
        }
        while (q.size()) {
            tie(z, y, x) = q.front(); q.pop();
            for (int i = 0; i < 6; i++) {
                nz = z + dz[i]; ny = y + dy[i]; nx = x + dx[i];
                if (nz < 0 || nz >= l || ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if (_map[nz][ny][nx] == '#' || visited[nz][ny][nx] > 0) continue;
                q.push({nz, ny, nx}); visited[nz][ny][nx] = visited[z][y][x] + 1;
            }
        }
        if (visited[ez][ey][ex] == 0) cout << "Trapped!\n";
        else cout << "Escaped in " << visited[ez][ey][ex] - 1 << " minute(s).\n";
    }
    return 0;
}