//메모리: 3972KB, 시간: 24ms
#include <bits/stdc++.h>
using namespace std;

//dp 배열: (0, 0) → (m-1, n-1) 좌표까지 이동하는 경우의 수
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int m, n, _map[500][500], dp[500][500];

int go(int y, int x) {
    int& ret = dp[y][x];
    if (ret == -1) {
        ret = 0;
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= m || nx < 0 || nx >= n || _map[y][x] <= _map[ny][nx]) continue;
            ret += go(ny, nx);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> m >> n;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) cin >> _map[i][j];
    }
    memset(dp, -1, sizeof(dp)); dp[m-1][n-1] = 1;
    cout << go(0, 0) << '\n';
    return 0;
}