#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, miro[100][100], visited[100][100], y, x;
queue<pair<int, int>> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &miro[i][j]);
        }
    }

    visited[0][0] = 1;
    q.push({0, 0});
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m || miro[ny][nx] == 0) continue;
            if (visited[ny][nx]) continue;
            q.push({ny, nx});
            visited[ny][nx] = visited[y][x] + 1;
        }
    }
    printf("%d\n", visited[n - 1][m - 1]);

    return 0;
}