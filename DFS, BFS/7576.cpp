//메모리: 14112KB, 시간: 104ms
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, _map[1000][1000], visited[1000][1000], y, x, ny, nx, cnt, total;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> _map[i][j];
            if (_map[i][j] == 1) {
                q.push({i, j}); visited[i][j] = 1; cnt++;
            }
            if (_map[i][j] != -1) total++;
        }
    }
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || _map[ny][nx] == -1) continue;
            q.push({ny, nx}); visited[ny][nx] = visited[y][x] + 1; cnt++;
        }
    }
    if (cnt == total) cout << visited[y][x] - 1 << '\n';
    else cout << "-1\n";

    return 0;
}