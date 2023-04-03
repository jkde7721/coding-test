//메모리: 2032KB, 시간: 208ms
/*
#include <iostream>
#include <cstring>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int n, m, _map[50][50], num, mx, mx2, tmp;
bool visited[50][50];

int dfs(int y, int x) {
    int cnt = 1;
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        if (_map[y][x] & (1 << i)) continue;
        int ny = y + dy[i], nx = x + dx[i];
        if (visited[ny][nx]) continue;
        cnt += dfs(ny, nx);
    }
    return cnt;
}

int go() {
    int ret = 0;
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                ret = max(ret, dfs(i, j));
                tmp++;
            }
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> _map[i][j];
        }
    }
    mx = mx2 = go();
    num = tmp;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                if ((j == 0 && k == 0) || (i == 0 && k == 1) || (j == n - 1 && k == 2) || (i == m - 1 && k == 3)) continue;
                if (!(_map[i][j] & (1 << k))) continue;
                _map[i][j] &= ~(1 << k);
                mx2 = max(mx2, go());
                _map[i][j] |= (1 << k);
            }
        }
    }
    cout << num << '\n';
    cout << mx << '\n';
    cout << mx2 << '\n';

    return 0;
}
*/

//메모리: 2048KB, 시간: 0ms
#include <iostream>
using namespace std;

const int dy[] = {0, -1, 0, 1};
const int dx[] = {-1, 0, 1, 0};
int n, m, _map[50][50], visited[50][50], area[2501], num, mx, mx2, tmp, tmp2;

int dfs(int y, int x) {
    int cnt = 1;
    visited[y][x] = num;
    for (int i = 0; i < 4; i++) {
        if (_map[y][x] & (1 << i)) continue;
        int ny = y + dy[i], nx = x + dx[i];
        if (visited[ny][nx]) continue;
        cnt += dfs(ny, nx);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> _map[i][j];
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                num++;
                area[num] = dfs(i, j);
                mx = max(mx, area[num]);
            }
        }
    }

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                if ((j == 0 && k == 0) || (i == 0 && k == 1) || (j == n - 1 && k == 2) || (i == m - 1 && k == 3)) continue;
                if (!(_map[i][j] & (1 << k))) continue;
                tmp = visited[i][j];
                tmp2 = visited[i + dy[k]][j + dx[k]];
                //벽을 제거했을 때 연결된 방이 서로 다른 방인 경우에만 최댓값 업데이트
                if (tmp != tmp2) mx2 = max(mx2, area[tmp] + area[tmp2]);
            }
        }
    }
    cout << num << '\n';
    cout << mx << '\n';
    cout << mx2 << '\n';

    return 0;
}