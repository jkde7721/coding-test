#include <bits/stdc++.h>
using namespace std;

typedef struct block {
    int n, dir;
    bool eat;
} Block;

const int dy[] = {-1, -1, 0, 1, 1, 1, 0, -1}, dx[] = {0, -1, -1, -1, 0, 1, 1, 1};
int n, dir;
Block _map[4][4]; //위치 별 상태 저장(물고기 번호, 방향, 먹힌 상태)
pair<int, int> pos[17]; //물고기 번호 별 위치 저장

void move(int sy, int sx) {
    int y, x, ny, nx, dir; bool mv;
    for (int i = 1; i <= 16; i++) {
        tie(y, x) = pos[i]; dir = _map[y][x].dir; mv = 0;
        if (_map[y][x].eat) continue;
        for (int i = 0; i < 8; i++) {
            ny = y + dy[(dir + i) % 8]; nx = x + dx[(dir + i) % 8];
            if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4 || sy == ny && sx == nx) continue;
            _map[y][x].dir = (dir + i) % 8;
            mv = 1; break;
        }
        if (mv) {
            swap(pos[_map[y][x].n], pos[_map[ny][nx].n]);
            swap(_map[y][x], _map[ny][nx]);
        }
    }
}

int go(int sy, int sx) {
    int ret = _map[sy][sx].n, ny = sy, nx = sx, sdir = _map[sy][sx].dir;
    Block m[4][4]; pair<int, int> p[17];
    _map[sy][sx].eat = 1;
    move(sy, sx);
    memcpy(m, _map, sizeof(_map)); memcpy(p, pos, sizeof(pos)); //현재 상태 임시 저장
    for (int i = 0; i < 3; i++) {
        ny += dy[sdir]; nx += dx[sdir];
        if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4) break;
        if (_map[ny][nx].eat) continue;
        ret = max(ret, _map[sy][sx].n + go(ny, nx));
        memcpy(_map, m, sizeof(_map)); memcpy(pos, p, sizeof(pos));
    }
    _map[sy][sx].eat = 0;
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            cin >> n >> dir; dir--;
            _map[i][j] = {n, dir, 0};
            pos[n] = {i, j};
        }
    }
    cout << go(0, 0) << '\n';
    return 0;
}