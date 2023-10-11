//BFS 풀이
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, cnt, mx, width, y, x, ny, nx;
bool _map[500][500], visited[500][500];
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> _map[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!_map[i][j] || visited[i][j]) continue;
            q.push({i, j}); visited[i][j] = 1; width = 1;
            while (q.size()) {
                tie(y, x) = q.front(); q.pop();
                for (int k = 0; k < 4; k++) {
                    ny = y + dy[k]; nx = x + dx[k];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= m || !_map[ny][nx] || visited[ny][nx]) continue;
                    q.push({ny, nx}); visited[ny][nx] = 1; width++;
                }
            }
            cnt++; mx = max(mx, width);
        }
    }
    cout << cnt << '\n' << mx << '\n';
    return 0;
}