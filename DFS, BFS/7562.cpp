#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

const int dy[] = {-2, -1, 1, 2, 2, 1, -1, -2}, dx[] = {1, 2, 2, 1, -1, -2, -2, -1};
int t, n, y, x, ny, nx, ey, ex, visited[300][300];
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        fill(&visited[0][0], &visited[0][0] + 300*300, INF);
        cin >> n >> y >> x >> ey >> ex;
        q.push({y, x}); visited[y][x] = 1;
        while (q.size()) {
            tie(y, x) = q.front(); q.pop();
            for (int i = 0; i < 8; i++) {
                ny = y + dy[i]; nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] <= visited[y][x] + 1) continue;
                q.push({ny, nx}); visited[ny][nx] = visited[y][x] + 1;
            }
        }
        cout << visited[ey][ex] - 1 << '\n';
    }
    return 0;
}