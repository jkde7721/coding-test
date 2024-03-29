//메모리: 2596KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, idx = 1, y, x, ny, nx, ret = 1e9;
bool _map[100][100], visited[100][100];
pair<int, int> dist[100][100]; //임의의 섬에서 해당 위치까지의 최단 거리 저장
queue<pair<int, int>> q;

void dfs(int y, int x) {
    q.push({y, x}); visited[y][x] = 1; dist[y][x] = {idx, 1};
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || !_map[ny][nx] || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> _map[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (_map[i][j] && !visited[i][j]) { dfs(i, j); idx++; }
        }
    }
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
            if (dist[ny][nx].second > 0) {
                //출발한 섬이 서로 다르다면
                if (dist[y][x].first != dist[ny][nx].first) ret = min(ret, dist[y][x].second + dist[ny][nx].second - 2); //섬에서의 최단 거리는 1부터 시작했으므로 각각 -1
                continue;
            }
            q.push({ny, nx}); dist[ny][nx] = {dist[y][x].first, dist[y][x].second + 1};
        }
    }
    cout << ret << '\n';
    return 0;
}

//완전탐색 같은 풀이
//메모리: 2564KB, 시간: 316ms
/*
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, dist[100][100], y, x, ny, nx, ret = 1e9;
bool _map[100][100], visited[100][100];
queue<pair<int, int>> q;

void dfs(int y, int x) {
    q.push({y, x}); visited[y][x] = 1; dist[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || !_map[ny][nx] || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> _map[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            //각 섬을 기준으로 bfs 수행
            if (_map[i][j] && !visited[i][j]) { 
                memset(dist, 0, sizeof(dist));
                dfs(i, j); //각 섬을 큐에 삽입하기 위해 dfs
                while (q.size()) {
                    tie(y, x) = q.front(); q.pop();
                    for (int i = 0; i < 4; i++) {
                        ny = y + dy[i]; nx = x + dx[i];
                        if (ny < 0 || ny >= n || nx < 0 || nx >= n || dist[ny][nx] > 0) continue;
                        if (_map[ny][nx]) { ret = min(ret, dist[y][x]); continue; }
                        q.push({ny, nx}); dist[ny][nx] = dist[y][x] + 1;
                    }
                }
            }
        }
    }
    cout << ret - 1 << '\n';
    return 0;
}
*/