#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int m, n, k, ly, lx, ry, rx, num, wid, mo[100][100];
bool visited[100][100];
vector<int> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    wid++;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= m || nx < 0 || nx >= n || mo[ny][nx]) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx);
    }
}

int main() {
    cin >> m >> n >> k;
    while (k > 0) {
        cin >> lx >> ly >> rx >> ry;
        for (int i = ly; i < ry; i++) {
            for (int j = lx; j < rx; j++) {
                mo[i][j] = 1;
            }
        }
        k--;
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (mo[i][j] == 0 && !visited[i][j]) {
                wid = 0; num++;
                dfs(i, j);
                v.push_back(wid);
            }
        }
    }
    cout << num << '\n';
    sort(v.begin(), v.end());
    for (int i : v) {
        cout << i << ' ';
    }

    return 0;
}