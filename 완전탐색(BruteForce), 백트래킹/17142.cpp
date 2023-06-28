#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, lab[50][50], mask[10], visited[50][50], vcnt, wcnt, cnt, ny, nx, y, x, ret = INF;
pair<int, int> v[10];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 2) v[vcnt++] = {i, j};
            if (lab[i][j] == 0) wcnt++;
        }
    }
    //활성화할 바이러스 조합 생성
    for (int i = 0; i < vcnt - m; i++) mask[i] = 0;
    for (int i = vcnt - m; i < vcnt; i++) mask[i] = 1;
    do {
        queue<pair<int, int>> q;
        memset(visited, 0, sizeof(visited)); cnt = 0;
        for (int i = 0; i < vcnt; i++) {
            if (mask[i]) { q.push(v[i]); visited[v[i].first][v[i].second] = 1; }
        }
        while (q.size()) {
            tie(y, x) = q.front(); q.pop();
            if (lab[y][x] == 0) cnt++;
            if (cnt == wcnt) break; //모든 빈 칸에 바이러스를 퍼뜨리면 stop (비활성화 바이러스는 고려X) 
            for (int i = 0; i < 4; i++) {
                ny = y + dy[i]; nx = x + dx[i];
                if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx] || lab[ny][nx] == 1) continue;
                q.push({ny, nx}); visited[ny][nx] = visited[y][x] + 1;
            }
        }
        if (cnt == wcnt) ret = min(ret, visited[y][x] - 1);
    } while(next_permutation(mask, mask + vcnt));
    cout << (ret == INF ? -1 : ret) << '\n';

    return 0;
}