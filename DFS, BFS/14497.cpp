#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, cls[301][301], y1, x1, y2, x2, y, x, visited[301][301];
string str;
queue<pair<int, int>> q, q2;

int main() {
    cin >> n >> m >> y1 >> x1 >> y2 >> x2;
    for (int i = 1; i <= n; i++) {
        cin >> str;
        for (int j = 1; j <= str.size(); j++) {
            if (str[j - 1] == '#' || str[j - 1] == '*') cls[i][j] = 1;
            else cls[i][j] = str[j - 1] - '0';
        }
    }
    q.push({y1, x1});
    visited[y1][x1] = 1;

    while (q.size() || q2.size()) {
        tie(y, x) = (q.size() ? q : q2).front();
        (q.size() ? q : q2).pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i]; int nx = x + dx[i];
            if (ny < 1 || ny > n || nx < 1 || nx > m || visited[ny][nx]) continue;
            if (cls[ny][nx]) {
                visited[ny][nx] = visited[y][x] + 1;
                q2.push({ny, nx});
            }
            else {
                visited[ny][nx] = visited[y][x];
                q.push({ny, nx});
            }
        }
    }
    cout << visited[y2][x2] - 1 << '\n';

    return 0;
}