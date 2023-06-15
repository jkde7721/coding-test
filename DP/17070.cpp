//메모리: 2024KB, 시간: 0ms
/*
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {0, 1, 1}, dx[] = {1, 0, 1};
int n, home[17][17], cnt[17][17][3];

int go(int y, int x, int dir) {
    int py = y + dy[dir], px = x + dx[dir];
    if (py >= n || px >= n || home[py][px]) return 0;
    if (dir == 2 && (home[py-1][px] || home[py][px-1])) return 0;
    if (py == n - 1 && px == n - 1) return 1;
    
    int& ret = cnt[y][x][dir];
    if (ret == -1) {
        int ny = y + dy[dir], nx = x + dx[dir];
        if (dir == 0) ret = go(ny, nx, 0) + go(ny, nx, 2);
        else if (dir == 1) ret = go(ny, nx, 1) + go(ny, nx, 2);
        else ret = go(ny, nx, 0) + go(ny, nx, 1) + go(ny, nx, 2);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    memset(cnt, -1, sizeof(cnt));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> home[i][j];
    }
    cout << go(0, 0, 0) << '\n';

    return 0;
}
*/

//재귀 사용하지 않고 반복문만으로 풀어보기
#include <bits/stdc++.h>
using namespace std;

int n, home[16][16], cnt[16][16][3];

bool check(int y, int x, int dir) {
    if (y >= n || x >= n || home[y][x]) return false;
    if (dir == 2 && (home[y-1][x] || home[y][x-1])) return false;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> home[i][j];
    }
    cnt[0][1][0] = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (check(i, j + 1, 0)) cnt[i][j+1][0] += cnt[i][j][0];
            if (check(i + 1, j + 1, 2)) cnt[i+1][j+1][2] += cnt[i][j][0];

            if (check(i + 1, j, 1)) cnt[i+1][j][1] += cnt[i][j][1];
            if (check(i + 1, j + 1, 2)) cnt[i+1][j+1][2] += cnt[i][j][1];

            if (check(i, j + 1, 0)) cnt[i][j+1][0] += cnt[i][j][2];
            if (check(i + 1, j, 1)) cnt[i+1][j][1] += cnt[i][j][2];
            if (check(i + 1, j + 1, 2)) cnt[i+1][j+1][2] += cnt[i][j][2];
        }
    }
    cout << (cnt[n-1][n-1][0] + cnt[n-1][n-1][1] + cnt[n-1][n-1][2]) << '\n';

    return 0;
}