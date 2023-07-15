//그리디 + 완전탐색 + 비트마스킹 문제
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

const int dy[] = {0, -1, 0, 1, 0}, dx[] = {0, 0, 1, 0, -1};
int _map[10][10], tmp[10][10], ret = INF, cnt;
char c;

void turn(int y, int x) {
    for (int i = 0; i < 5; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= 10 || nx < 0 || nx >= 10) continue;
        _map[ny][nx] ^= 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> c;
            if (c == '#') _map[i][j] = 0;
            else _map[i][j] = 1;
            tmp[i][j] = _map[i][j];
        }
    }
    //0행의 전구 스위치를 누르는 모든 경우
    for (int k = 0; k < (1 << 10); k++) {
        memcpy(_map, tmp, sizeof(tmp)); cnt = 0;
        for (int i = 0; i < 10; i++) {
            if (k & (1 << i)) { turn(0, i); cnt++; }
        }
        //바로 위 행의 같은 열에 전구가 켜져있으면 스위치 누름
        for (int i = 1; i < 10; i++) {
            for (int j = 0; j < 10; j++) {
                if (_map[i-1][j]) { turn(i, j); cnt++; }
            }
        }
        if (accumulate(&_map[0][0], &_map[0][0] + 10*10, 0) == 0) ret = min(ret, cnt);
    }
    cout << (ret == INF ? -1 : ret) << '\n';

    return 0;
}