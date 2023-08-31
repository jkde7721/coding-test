//메모리: 3152KB, 시간: 72ms
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, _map[300][300], year, cnt;
bool visited[300][300];

void melt() {
    vector<tuple<int, int, int>> v;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < m; x++) {
            if (_map[y][x] == 0) continue;
            int amt = 0, ny, nx;
            for (int i = 0; i < 4; i++) {
                ny = y + dy[i]; nx = x + dx[i];
                if (_map[ny][nx] == 0) amt++;
            }
            v.push_back({y, x, amt});
        }
    }
    int y, x, amt;
    for (auto& it : v) {
        tie(y, x, amt) = it;
        if (_map[y][x] < amt) _map[y][x] = 0;
        else _map[y][x] -= amt;
    }
}

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (_map[ny][nx] == 0 || visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> _map[i][j];
    }
    while (1) {
        memset(visited, 0, sizeof(visited)); 
        cnt = 0; year++;
        melt();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (_map[i][j] > 0 && !visited[i][j]) { dfs(i, j); cnt++; }
            }
        }
        if (cnt == 0 || cnt >= 2) break;
    }
    cout << (cnt == 0 ? 0 : year) << '\n';
    return 0;
}