#include <bits/stdc++.h>
using namespace std;

const int dy[] {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
bool visited[10][10];
int n, m, _map[10][10], idx = 1, root[7], num, a, b, dist, ret, cnt;
vector<tuple<int, int, int>> edge;

void dfs(int y, int x) {
    visited[y][x] = 1; _map[y][x] = idx;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx] || !_map[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int _dfs(int y, int x, int _dy, int _dx) {
    if (y >= n || x >= m) return 0;
    if (_map[y][x]) { num = _map[y][x]; return 0; }
    int ny = y + _dy, nx = x + _dx, dist = 1;
    dist += _dfs(ny, nx, _dy, _dx);
    return dist;
}

int _find(int node) {
    if (root[node] == node) return node;
    return root[node] = _find(root[node]);
}

void _union(int a, int b) {
    root[_find(a)] = _find(b);
}

void mst() {
    for (int i = 1; i <= 6; i++) root[i] = i;
    sort(edge.begin(), edge.end());
    for (auto& it : edge) {
        tie(dist, a, b) = it;
        if (_find(a) == _find(b)) continue;
        ret += dist; cnt++; _union(a, b);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> _map[i][j];
    }
    //섬 번호 표시
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && _map[i][j]) { dfs(i, j); idx++; }
        }
    }
    //모든 세로, 가로 방향 다리 탐색
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (_map[i][j]) {
                num = 0; dist = _dfs(i + 1, j, 1, 0); //세로 방향
                if (num != 0 && num != _map[i][j] && dist > 1) edge.push_back({dist, _map[i][j], num});
                num = 0; dist = _dfs(i, j + 1, 0, 1); //가로 방향
                if (num != 0 && num != _map[i][j] && dist > 1) edge.push_back({dist, _map[i][j], num});
            }
        }
    }
    mst();
    //모든 섬을 연결하지 못하는 경우
    cout << (cnt + 1 != idx - 1 ? -1 : ret) << '\n';
    return 0;
}