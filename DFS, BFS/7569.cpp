//메모리: 11428KB, 시간: 112ms
#include <bits/stdc++.h>
using namespace std;

const int dz[] = {1, -1, 0, 0, 0, 0}, dy[] = {0, 0, -1, 0, 1, 0}, dx[] = {0, 0, 0, 1, 0, -1};
int n, m, h, _map[100][100][100], visited[100][100][100], z, y, x, nz, ny, nx, cnt, total;
queue<tuple<int, int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n >> h;
    for (int k = 0; k < h; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> _map[k][i][j];
                if (_map[k][i][j] == 1) { 
                    q.push({k, i, j}); visited[k][i][j] = 1; cnt++;
                }
                if (_map[k][i][j] != -1) total++;
            }
        }
    }
    while (q.size()) {
        tie(z, y, x) = q.front(); q.pop();
        for (int i = 0; i < 6; i++) {
            nz = z + dz[i]; ny = y + dy[i]; nx = x + dx[i];
            if (nz < 0 || nz >= h || ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (visited[nz][ny][nx] || _map[nz][ny][nx] == -1) continue;
            q.push({nz, ny, nx}); visited[nz][ny][nx] = visited[z][y][x] + 1; cnt++;
        }
    }
    if (cnt == total) cout << visited[z][y][x] - 1 << '\n';
    else cout << "-1\n";

    return 0;
}