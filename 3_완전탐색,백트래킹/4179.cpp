#include <iostream>
#include <queue>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, y, x, miro[1000][1000], visited[1000][1000], visitedf[1000][1000];
char tmp;
queue<pair<int, int>> q, qf;

bool isEscape(int y, int x) {
    if (y == 0 || y == r - 1 || x == 0 || x == c - 1) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> tmp;
            if (tmp == '#') miro[i][j] = 0;
            else miro[i][j] = 1;
            if (tmp == 'J') {
                q.push({i, j});
                visited[i][j] = 1;
            }
            else if (tmp == 'F') {
                qf.push({i, j});
                visitedf[i][j] = 1;
            }
        }
    }

//¿œ¥‹ ∫“¿ª ≥ø
    while (qf.size()) {
        y = qf.front().first;
        x = qf.front().second;
        qf.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c || miro[ny][nx] == 0) continue;
            if (visitedf[ny][nx]) continue;
            visitedf[ny][nx] = visitedf[y][x] + 1;
            qf.push({ny, nx});
        }
    }

    while (q.size()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        if (isEscape(y, x)) {
            cout << visited[y][x] << '\n';
            return 0;
        }

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= r || nx < 0 || nx >= c || miro[ny][nx] == 0) continue;
            if (visited[ny][nx] || visitedf[ny][nx] && visitedf[ny][nx] <= visited[y][x] + 1) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    cout << "IMPOSSIBLE\n";

    return 0;
}