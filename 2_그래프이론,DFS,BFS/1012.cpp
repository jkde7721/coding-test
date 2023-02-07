#include <iostream>
#include <cstring>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int t, n, m, k, y, x, ret, field[50][50];
bool visited[50][50];

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || !field[ny][nx]) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> t;
    while (t) {
        cin >> m >> n >> k;
        memset(field, 0, sizeof(field));
        memset(visited, 0, sizeof(visited));
        ret = 0;

        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            field[y][x] = 1;
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (field[i][j] && !visited[i][j]) {
                    dfs(i, j);
                    ret++;
                }
            }
        }
        cout << ret << '\n';
        t--;
    }

    return 0;
}