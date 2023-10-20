//무식한 BFS
//메모리: 2812KB, 시간: 156ms
/*
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, x, y, a, b, ny, nx, cnt = 1;
bool _map[101][101], visited[101][101], on = 1;
vector<pair<int, int>> sw[101][101];
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        sw[x][y].push_back({a, b});
    }
    _map[1][1] = 1;
    while (on) {
        memset(visited, 0, sizeof(visited)); on = 0;
        visited[1][1] = 1; q.push({1, 1});
        while (q.size()) {
            tie(y, x) = q.front(); q.pop();
            for (auto& it : sw[y][x]) {
                if (!_map[it.first][it.second]) { cnt++; on = 1; }
                _map[it.first][it.second] = 1;
            }
            for (int i = 0; i < 4; i++) {
                ny = y + dy[i]; nx = x + dx[i];
                if (ny <= 0 || ny > n || nx <= 0 || nx > n || !_map[ny][nx] || visited[ny][nx]) continue;
                visited[ny][nx] = 1; q.push({ny, nx});
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}
*/

//BFS 1번만
//메모리: 2820KB, 시간: 8ms
#include <bits/stdc++.h>
using namespace std;

//on 배열: 현재 불이 켜진 곳 
//mv 배열: 현재 불이 켜지진 않았지만 불이 켜진다면 이동 가능할 곳
//불 off & 이동X / 불 on & 이동X / 불 off & 이동O / 불 on & 이동O → 이 경우만 큐에 push
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, x, y, a, b, ny, nx, cnt = 1;
bool on[101][101], mv[101][101], visited[101][101];
vector<pair<int, int>> sw[101][101];
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y >> a >> b;
        sw[x][y].push_back({a, b});
    }
    on[1][1] = visited[1][1] = 1; q.push({1, 1});
    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        //이미 불이 켜져 있어서 이동 가능한 곳, 앞으로 불이 켜지면 이동 가능할 곳 체크
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny <= 0 || ny > n || nx <= 0 || nx > n || visited[ny][nx]) continue;
            if (on[ny][nx]) { visited[ny][nx] = 1; q.push({ny, nx}); }
            else mv[ny][nx] = 1;
        }
        for (auto& it : sw[y][x]) {
            if (!on[it.first][it.second]) {
                on[it.first][it.second] = 1; cnt++;
                if (mv[it.first][it.second]) { visited[it.first][it.second] = 1; q.push(it); }
            }
        }
    }
    cout << cnt << '\n';
    return 0;
}