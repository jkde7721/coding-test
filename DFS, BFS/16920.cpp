//메모리: 14148KB, 시간: 52ms
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int N, M, P, s[10], y, x, ny, nx, dist, cnt[10];
char _map[1000][1000], c;
bool mv = true;
queue<tuple<int, int, int>> q[10]; //플레이어 별로 큐 관리

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> P;
    for (int i = 1; i <= P; i++) cin >> s[i];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> c; _map[i][j] = c;
            if (c != '.' && c != '#') { q[c - '0'].push({i, j, 0}); cnt[c - '0']++; }
        }
    }
    for (int t = 1; mv; t++) {
        mv = false;
        for (int p = 1; p <= P; p++) {
            while (q[p].size() && get<2>(q[p].front()) < t * s[p]) {
                tie(y, x, dist) = q[p].front(); q[p].pop();
                for (int i = 0; i < 4; i++) {
                    ny = y + dy[i]; nx = x + dx[i];
                    if (ny < 0 || ny >= N || nx < 0 || nx >= M || _map[ny][nx] != '.') continue;
                    q[p].push({ny, nx, dist + 1}); _map[ny][nx] = _map[y][x]; cnt[p]++; mv = true;
                }
            }
        }
    }
    for (int i = 1; i <= P; i++) cout << cnt[i] << ' ';
    return 0;
}