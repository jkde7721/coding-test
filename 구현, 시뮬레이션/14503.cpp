#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1}, bdir[] = {2, 3, 0, 1};
int n, m, r, c, d, _map[50][50];
bool visited[50][50];

int go(int y, int x, int dir) {
    int ret = 0, ny, nx;
    if (!visited[y][x]) { visited[y][x] = 1; ret = 1; }
    for (int i = 0; i < 4; i++) {
        dir = (dir + 3) % 4;
        ny = y + dy[dir]; nx = x + dx[dir]; 
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || _map[ny][nx]) continue;
        return go(ny, nx, dir) + ret;
    }
    ny = y + dy[bdir[dir]]; nx = x + dx[bdir[dir]];
    if (ny >= 0 && ny < n && nx >= 0 && nx < m && !_map[ny][nx]) ret += go(ny, nx, dir);
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> r >> c>> d;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> _map[i][j];
    }
    cout << go(r, c, d) << '\n';
    return 0;
}