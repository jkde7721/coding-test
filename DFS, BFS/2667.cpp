#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, _map[25][25], num;
bool visited[25][25];
vector<int> v;

int dfs(int y, int x) {
    visited[y][x] = 1;
    int ny, nx, cnt = 1;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i]; nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || !_map[ny][nx] || visited[ny][nx]) continue;
        cnt += dfs(ny, nx);
    }
    return cnt;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) scanf("%1d", &_map[i][j]);
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (_map[i][j] && !visited[i][j]) { v.push_back(dfs(i, j)); num++; }
        }
    }
    sort(v.begin(), v.end());
    printf("%d\n", num);
    for (int i : v) printf("%d\n", i);
    return 0;
}