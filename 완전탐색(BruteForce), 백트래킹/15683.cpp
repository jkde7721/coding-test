//메모리: 2024KB, 시간: 4ms
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
//1~5번 CCTV의 방향에 대한 경우의 수
vector<vector<vector<int>>> dir = {
    {}, {{0}, {1}, {2}, {3}}, {{0, 2}, {1, 3}}, {{0, 1}, {1, 2}, {2, 3}, {3, 0}}, 
    {{3, 0, 1}, {0, 1, 2}, {1, 2, 3}, {2, 3, 0}}, {{0, 1, 2, 3}}
};
int n, m, room[8][8], visited[8][8], ret = 64;

void go(int y, int x) {
    if (y >= n) {
        int tmp = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) tmp++;
            }
        }
        ret = min(ret, tmp);
        return;
    }
    if (x >= m) { go(y+1, 0); return; }
    if (!room[y][x] || room[y][x] == 6) { go(y, x+1); return; }

    int ny, nx, cctv = room[y][x];
    for (int i = 0; i < dir[cctv].size(); i++) {
        for (int d : dir[cctv][i]) {
            ny = y, nx = x;
            while (1) {
                ny += dy[d]; nx += dx[d];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || room[ny][nx] == 6) break;
                visited[ny][nx]++;
            }
        }
        go(y, x+1);
        for (int d : dir[cctv][i]) {
            ny = y, nx = x;
            while (1) {
                ny += dy[d]; nx += dx[d];
                if (ny < 0 || ny >= n || nx < 0 || nx >= m || room[ny][nx] == 6) break;
                visited[ny][nx]--; //원복
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> room[i][j];
            if (room[i][j]) visited[i][j] = 1;
        }
    }
    go(0, 0);
    cout << ret << '\n';

    return 0;
}