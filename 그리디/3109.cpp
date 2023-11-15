//그리디 + DFS
//시간 초과를 막기 위한 visited 처리 중요
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1}, dx[] = {1, 1, 1};
int r, c, y, x, ny, nx, ret;
char ch;
bool _map[10000][500], visited[10000][500];

bool go(int y, int x) {
    visited[y][x] = 1; //원복X → 특정 위치에서 끝에 도달하지 못했다는 것은 다시 그 위치에 갈 필요 없다는 의미
    if (x == c - 1) { ret++; return true; } //끝에 도달하자마자 end 
    for (int i = 0; i < 3; i++) {
        int ny = y + dy[i], nx = x + dx[i];
        if (ny < 0 || ny >= r || nx >= c || !_map[ny][nx] || visited[ny][nx]) continue;
        if (go(ny, nx)) return true;
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> ch;
            _map[i][j] = ch == '.' ? 1 : 0;
        }
    }
    for (int i = 0; i < r; i++) go(i, 0);
    cout << ret << '\n';
    return 0;
}