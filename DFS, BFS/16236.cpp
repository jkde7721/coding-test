#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, _map[20][20], y, x, ny, nx, shk = 2, cnt, dist, visited[20][20], ret;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> _map[i][j];
            if (_map[i][j] == 9) { _map[i][j] = 0; y = i; x = j; }
        }
    }
    while (1) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        memset(visited, 0, sizeof(visited));
        q.push({y, x}); visited[y][x] = 1;
        while (q.size()) {
            tie(y, x) = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                ny = y + dy[i]; nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx]) continue;
                if (_map[ny][nx] > shk) continue;
                q.push({ny, nx}); visited[ny][nx] = visited[y][x] + 1;
                if (_map[ny][nx] && _map[ny][nx] < shk) pq.push({visited[ny][nx], ny, nx});
            }
        }
        if (!pq.size()) break;
        tie(dist, y, x) = pq.top(); //물고기 eat
        cnt++; _map[y][x] = 0;
        if (shk == cnt) { shk++; cnt = 0; }
        ret += dist - 1;
    }
    cout << ret << '\n';
    return 0;
}