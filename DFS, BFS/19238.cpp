#include <bits/stdc++.h>
using namespace std;

typedef struct pass {
    int sy, sx, ey, ex;
    bool wait;
} Pass;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, fuel, _map[21][21], y, x, dist, dist2, idx, visited[21][21], cnt;
Pass pass[401];
queue<pair<int, int>> q;

void bfs(int y, int x) {
    memset(visited, 0, sizeof(visited));
    int ny, nx;
    q.push({y, x}); visited[y][x] = 1;
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 1 || ny > n || nx < 1 || nx > n || visited[ny][nx] || _map[ny][nx] == -1) continue;
            q.push({ny, nx}); visited[ny][nx] = visited[y][x] + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> fuel; cnt = m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> _map[i][j];
            if (_map[i][j]) _map[i][j] = -1; //벽은 -1
        }
    }
    cin >> y >> x;
    for (int i = 1; i <= m; i++) {
        cin >> pass[i].sy >> pass[i].sx >> pass[i].ey >> pass[i].ex;
        pass[i].wait = 1;
        _map[pass[i].sy][pass[i].sx] = i; //출발 위치에 승객 번호 저장 
    }
    while (cnt > 0) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
        bfs(y, x);
        for (Pass p : pass) {
            if (!p.wait || visited[p.sy][p.sx] == 0) continue;
            pq.push({visited[p.sy][p.sx] - 1, p.sy, p.sx});
        }
        if (pq.empty()) break; //태울 수 있는 승객X

        tie(dist, y, x) = pq.top(); idx = _map[y][x]; //태울 승객 번호
        bfs(y, x); 
        y = pass[idx].ey; x = pass[idx].ex; dist2 = visited[y][x] - 1;
        if (visited[y][x] == 0) break; //목적지 이동 불가
        if (fuel < dist + dist2) break; //연료 부족 
        //승객 목적지 이동 성공
        fuel += dist2 - dist; pass[idx].wait = 0; cnt--;
    }
    cout << (cnt == 0 ? fuel : -1) << '\n';

    return 0;
}