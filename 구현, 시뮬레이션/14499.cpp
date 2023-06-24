#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 0, -1, 1}, dx[] = {1, -1, 0, 0};
int n, m, y, x, k, _map[20][20], tmp[6], dice[6], dir, ny, nx;
int d[4][6] = {{4, 1, 0, 3, 5, 2}, {2, 1, 5, 3, 0, 4}, 
    {3, 0, 2, 5, 4, 1}, {1, 5, 2, 0, 4, 3}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> y >> x >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> _map[i][j]; 
    }
    for (int i = 0; i < k; i++) {
        cin >> dir; dir--;
        ny = y + dy[dir]; nx = x + dx[dir];
        if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
        y = ny; x = nx;
        memcpy(tmp, dice, sizeof(tmp));
        for (int i = 0; i < 6; i++) dice[i] = tmp[d[dir][i]];
        if (_map[y][x] == 0) _map[y][x] = dice[5];
        else { dice[5] = _map[y][x]; _map[y][x] = 0; }
        cout << dice[0] << '\n';
    }

    return 0;
}