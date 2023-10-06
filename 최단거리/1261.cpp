#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

//cnt 배열: 해당 위치까지 왔을 때 부순 벽의 최소값 저장
const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, _map[100][100], cnt[100][100], c, y, x, ny, nx;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    fill(&cnt[0][0], &cnt[0][0] + 100*100, INF);
    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) scanf("%1d", &_map[i][j]);
    }
    cnt[0][0] = 0; pq.push({0, 0, 0});
    while (pq.size()) {
        tie(c, y, x) = pq.top(); pq.pop();
        if (cnt[y][x] < c) continue;
        for (int i = 0; i < 4; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            if (cnt[ny][nx] > c + _map[ny][nx]) {
                cnt[ny][nx] = c + _map[ny][nx];
                pq.push({cnt[ny][nx], ny, nx});
            }
        }
    }
    cout << cnt[n-1][m-1] << '\n';
    return 0;
}