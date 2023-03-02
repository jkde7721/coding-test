#include <iostream>
#include <queue>
#include <cstring>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int _map[50][50], visited[50][50], n, m, y, x, ret;
string tmp;
queue<pair<int, int>> q;

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        for (int j = 0; j < m; j++) {
            if (tmp[j] == 'L') _map[i][j] = 1;
            else _map[i][j] = 0;
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (_map[i][j]) {
                q.push({i, j});
                visited[i][j] = 1;

                while (q.size()) {
                    y = q.front().first;
                    x = q.front().second;
                    q.pop();

                    for (int k = 0; k < 4; k++) {
                        int ny = y + dy[k];
                        int nx = x + dx[k];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= m || _map[ny][nx] == 0) continue;
                        if (visited[ny][nx]) continue;

                        visited[ny][nx] = visited[y][x] + 1;
                        q.push({ny, nx});
                    }
                }

                ret = max(ret, visited[y][x]);
                memset(visited, 0, sizeof(visited));
            }
        }
    }
    cout << ret - 1 << '\n';

    return 0;
}