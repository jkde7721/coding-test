#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, _map[100][100], _map2[100][100], ret, ret2;
bool visited[100][100], visited2[100][100];
char c;

void dfs(int y, int x, bool v[100][100], int m[100][100]) {
    v[y][x] = 1;
    int ny, nx;
    for (int i = 0; i < 4; i++) {
        ny = y + dy[i]; nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (v[ny][nx] || m[y][x] != m[ny][nx]) continue;
        dfs(ny, nx, v, m);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> c;
            if (c == 'G') _map[i][j] = 1;
            else if (c == 'B') { _map[i][j] = 2; _map2[i][j] = 1; }
        } 
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) { dfs(i, j, visited, _map); ret++; }
            if (!visited2[i][j]) { dfs(i, j, visited2, _map2); ret2++; }
        } 
    }
    cout << ret << ' ' << ret2 << '\n';
    return 0;
}