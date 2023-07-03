#include <bits/stdc++.h>
using namespace std;

typedef struct shark {
    int y, x, dir;
} Shark;

const int dy[] = {0, -1, 1, 0, 0}, dx[] = {0, 0, 0, -1, 1};
int n, m, k, dir[401][5][4], num, t, y, x, ny, nx, d, tmp, stay, go, cnt;
pair<int, int> _map[20][20]; //상어 번호, 냄새 수명
Shark pos[401]; //현재 상어 위치

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k; cnt = m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> num;
            if (num != 0) {
                _map[i][j] = {num, k};
                pos[num] = {i, j, 0};
            }
        }
    }
    for (int i = 1; i <= m; i++) cin >> pos[i].dir;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= 4; j++) cin >> dir[i][j][0] >> dir[i][j][1] >> dir[i][j][2] >> dir[i][j][3];
    }
    while (cnt > 1 && t++ < 1000) {
        //상어 이동 위치, 방향 계산
        for (int i = 1; i <= m; i++) {
            if (pos[i].y == -1) continue; //이미 쫓겨난 상어
            y = pos[i].y; x = pos[i].x; d = 0;
            for (int j = 0; j < 4; j++) {
                tmp = dir[i][pos[i].dir][j]; 
                ny = y + dy[tmp]; nx = x + dx[tmp];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n || _map[ny][nx].first) continue;
                d = tmp; break;
            }
            if (!d) {
                for (int j = 0; j < 4; j++) {
                    tmp = dir[i][pos[i].dir][j]; 
                    ny = y + dy[tmp]; nx = x + dx[tmp];
                    if (ny < 0 || ny >= n || nx < 0 || nx >= n || _map[ny][nx].first != i) continue;
                    d = tmp; break;
                }
            }
            pos[i] = {ny, nx, d};
        }
        //냄새 수명 - 1, 냄새 소멸
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (_map[i][j].first == 0) continue;
                _map[i][j].second--;
                if (_map[i][j].second == 0) _map[i][j].first = 0;
            }
        }
        //상어 실제 이동, 상어 쫓아냄
        for (int i = 1; i <= m; i++) {
            if (pos[i].y == -1) continue; //이미 쫓겨난 상어
            y = pos[i].y; x = pos[i].x;
            //빈 칸이거나 자신의 냄새가 있는 칸
            if (_map[y][x].first == 0 || _map[y][x].first == i) {
                _map[y][x] = {i, k};
            }
            //한 칸에 여러 마리의 상어
            else {
                stay = min(_map[y][x].first, i); //남아있는 상어 번호
                go = max(_map[y][x].first, i); //쫓겨나는 상어 번호
                _map[y][x] = {stay, k};
                pos[go] = {-1, -1, -1}; //쫓겨나는 상어 위치, 방향 비활성화
                cnt--; //남아있는 상어 개수 - 1
            }
        }
    }
    if (cnt == 1) cout << t << '\n';
    else cout << "-1\n";
    return 0;
}