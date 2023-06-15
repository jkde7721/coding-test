//메모리: 2044KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
const int INF = 987654321;
int n, m, b[50][50], mx[50][50];
bool visited[50][50];
char tmp;

//현재 y, x에서 동전을 움직일 수 있는 최대 횟수
int go(int y, int x) {
    int& ret = mx[y][x];
    if (ret == -1) {
        int ny, nx, tmp = 0;
        visited[y][x] = 1;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i] * b[y][x]; nx = x + dx[i] * b[y][x];
            if (ny < 0 || nx < 0 || ny >= n || nx >= m || !b[ny][nx]) continue;
            if (visited[ny][nx]) { tmp = INF; break; } //무한번 움직임
            tmp = max(tmp, go(ny, nx)); //ny, nx에서 동전을 움직일 수 있는 최대 횟수
        }
        visited[y][x] = 0;
        ret = tmp + (tmp == INF ? 0 : 1); //+ (y, x → ny, nx) 1번 움직임
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    memset(mx, -1, sizeof(mx));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> tmp;
            if (tmp == 'H') b[i][j] = 0;
            else b[i][j] = tmp - '0';
        }
    }
    int ret = go(0, 0);
    cout << (ret == INF ? -1 : ret) << '\n';

    return 0;
}