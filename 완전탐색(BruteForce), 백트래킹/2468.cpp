#include <iostream>
#include <cstring>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, area[100][100], mx, safe;
bool visited[100][100];

void dfs(int y, int x, int h) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n || area[ny][nx] <= h) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx, h);
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> area[i][j];
        }
    }
    for (int h = 0; h <= 100; h++) {
        memset(visited, 0, sizeof(visited));
        safe = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (area[i][j] > h && !visited[i][j]) {
                    dfs(i, j, h);
                    safe++;
                }
            }
        }
        if (safe > mx) mx = safe;
    }
    cout << mx << '\n';

    return 0;
}