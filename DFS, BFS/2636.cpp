#include <iostream>
#include <cstring>
#include <numeric>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1}; 
int n, m, pan[100][100], num, tmp, hour;
bool visited[100][100];

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m || visited[ny][nx]) continue;
        if (pan[ny][nx] == 1) {
            pan[ny][nx] = 0;
            visited[ny][nx] = 1;
        }
        else dfs(ny, nx);
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> pan[i][j];
        }
    }

    while((tmp = accumulate(&pan[0][0], &pan[0][0] + 10000, 0)) != 0) {
        hour++;
        num = tmp;
        memset(visited, 0, sizeof(visited));
        dfs(0, 0);
    }
    cout << hour << '\n' << num << '\n';
}