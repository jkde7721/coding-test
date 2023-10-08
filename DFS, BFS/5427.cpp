//메모리: 12948KB, 시간: 92ms
//불을 먼저 내고 시간을 카운트 → 상근이 이동
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int t, w, h, fvisited[1000][1000], visited[1000][1000], sy, sx, y, x, ny, nx, ret;
char _map[1000][1000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        queue<pair<int, int>> q; ret = INF;
        fill(&fvisited[0][0], &fvisited[0][0] + 1000*1000, INF);
        memset(visited, 0, sizeof(visited));
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                cin >> _map[i][j];
                if (_map[i][j] == '*') {
                    fvisited[i][j] = 1;
                    q.push({i, j});
                }
                if (_map[i][j] == '@') { sy = i; sx = j; }
            }
        }

        while (q.size()) {
            tie(y, x) = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                ny = y + dy[i]; nx = x + dx[i];
                if (ny < 0 || ny >= h || nx < 0 || nx >= w || _map[ny][nx] == '#' || fvisited[ny][nx] != INF) continue;
                fvisited[ny][nx] = fvisited[y][x] + 1;
                q.push({ny, nx});
            }
        }
        
        visited[sy][sx] = 1; q.push({sy, sx});
        while (q.size()) {
            tie(y, x) = q.front(); q.pop();
            if (y == 0 || y == h-1 || x == 0 || x == w-1) { ret = visited[y][x]; break; }
            for (int i = 0; i < 4; i++) {
                ny = y + dy[i]; nx = x + dx[i];
                if (ny < 0 || ny >= h || nx < 0 || nx >= w || _map[ny][nx] == '#' || visited[ny][nx] > 0) continue;
                if (fvisited[ny][nx] <= visited[y][x] + 1) continue; //특정 위치의 fvisited 값이 visited 값보다 커야 상근이가 갈 수 있음
                visited[ny][nx] = visited[y][x] + 1;
                q.push({ny, nx});
            }
        }
        if (ret == INF) cout << "IMPOSSIBLE\n";
        else cout << ret << '\n';
    }
    return 0;
}