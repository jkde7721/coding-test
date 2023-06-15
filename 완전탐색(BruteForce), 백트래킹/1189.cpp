#include <iostream>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, k, arr[5][5], visited[5][5], ret;
string tmp;

void dfs(int y, int x, int d) {
    visited[y][x] = 1; d++;
    if (y == 0 && x == c - 1) {
        if (d == k) ret++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= r || nx < 0 || nx >= c || !arr[ny][nx]) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx, d);
        visited[ny][nx] = 0;
    }
}

int main() {
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        cin >> tmp;
        for (int j = 0; j < c; j++) {
            if (tmp[j] == 'T') arr[i][j] = 0;
            else arr[i][j] = 1;
        }
    }

    dfs(r - 1, 0, 0);
    cout << ret << '\n';

    return 0;
}