#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, visited[1500][1500], visited2[1500][1500], y, x, y1 = -1, x1, y2, x2;
char lake[1500][1500];
string str;
queue<pair<int, int>> q, q2;

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < c; j++) {
            if (str[j] == '.' || str[j] == 'L') {
                visited[i][j] = 1;
                q.push({i, j});
            }
            if (str[j] == 'L') {
                if (y1 == -1) { y1 = i; x1 = j; }
                else { y2 = i; x2 = j; }
            }
            lake[i][j] = str[j];
        }
    }

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i]; int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    q.push({y1, x1});
    visited2[y1][x1] = 1;
    while (!visited2[y2][x2]) {
        queue<pair<int, int>> tmp;
        while (q.size()) {
            tie(y, x) = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i]; int nx = x + dx[i];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited2[ny][nx]) continue;
                if (visited[ny][nx] > visited2[y][x]) {
                    visited2[ny][nx] = visited2[y][x] + 1;
                    tmp.push({ny, nx});
                } else {
                    visited2[ny][nx] = visited2[y][x];
                    q.push({ny, nx});
                }
            }
        }
        q = tmp;
    }
    cout << visited2[y2][x2] - 1 << '\n';

    return 0;
}