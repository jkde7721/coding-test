//메모리: 2020KB, 시간: 20ms
#include <bits/stdc++.h>
using namespace std;

int num[10], ret, _map[4][30];
pair<int, int> mal[4];

bool isFull(int ny, int nx) {
    int y, x;
    for (auto it : mal) {
        y = it.first; x = it.second;
        if (y == ny && x == nx) return true;
        if (y > 0 && x > 0 && ny > 0 && nx > 0 && _map[y][x] == _map[ny][nx]) return true;
        if (_map[y][x] == 40 && _map[ny][nx] == 40) return true;
    }
    return false;
}

void go(int cnt, int sc) {
    if (cnt == 10) {    
        ret = max(ret, sc);
        return;
    }

    int y, x, ny, nx;
    for (int i = 0; i < 4; i++) {
        tie(y, x) = mal[i]; ny = y; nx = x;
        if (!_map[y][x]) continue;
        nx += num[cnt];
        if (ny == 0 && (nx == 5 || nx == 10 || nx == 15)) { 
            ny = nx / 5; nx = 0;
        }
        if (_map[ny][nx] && isFull(ny, nx)) continue;

        mal[i].first = ny; mal[i].second = nx;
        go(cnt + 1, sc + _map[ny][nx]);
        mal[i].first = y; mal[i].second = x;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 1; i < 21; i++) _map[0][i] = i*2;
    for (int i = 0, v = 10; i < 4; i++, v += 3) _map[1][i] = v;
    for (int i = 0, v = 20; i < 3; i++, v += 2) _map[2][i] = v;
    for (int i = 1, v = 28; i < 4; i++, v--) _map[3][i] = v;    
    _map[0][0] = 1; //시작점
    _map[1][4] = _map[2][3] = _map[3][4] = 25;
    _map[3][0] = _map[1][5] = _map[2][4] = _map[3][5] = 30;
    _map[1][6] = _map[2][5] = _map[3][6] = 35;
    _map[1][7] = _map[2][6] = _map[3][7] = 40;

    for (int i = 0; i < 10; i++) cin >> num[i];
    go(0, 0);
    cout << ret << '\n';

    return 0;
}