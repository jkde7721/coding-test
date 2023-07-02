//메모리: 40116KB, 시간: 500ms
//하나의 구멍을 공유하는 두 칸의 관계만을 고려 → 계산된 물의 높이가 기존 높이 보다 더 작으면 업데이트
//!!왜 다익스트라가 필요? 다시 풀어보기!! (BFS + 우선순위 큐(가장 낮은 물의 높이에서부터 인접 칸들의 물의 높이를 결정해나감))
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, h, hh, d, y, x, ny, nx, hole[1000][1000][4], height[1000][1000], ret;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

void enqueue(int d, int y, int x) {
    if (d < height[y][x]) {
        height[y][x] = d;
        pq.push({d, y, x});
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 0; i < n + 1; i++) {
        for (int j = 0; j < m; j++) {
            cin >> hh;
            if (i < n) hole[i][j][0] = hh;
            if (i - 1 >= 0) hole[i - 1][j][2] = hh;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m + 1; j++) {
            cin >> hh;
            if (j < m) hole[i][j][3] = hh;
            if (j - 1 >= 0) hole[i][j - 1][1] = hh;
        }
    }
    fill(&height[0][0], &height[0][0] + 1000*1000, h);
    //행의 왼쪽, 오른쪽 확인
    for (int i = 0; i < n; i++) {
        if (hole[i][0][3] != -1) enqueue(hole[i][0][3], i, 0);
        if (hole[i][m - 1][1] != -1) enqueue(hole[i][m - 1][1], i, m - 1);
    }
    //열의 위쪽, 아래쪽 확인
    for (int i = 0; i < m; i++) {
        if (hole[0][i][0] != -1) enqueue(hole[0][i][0], 0, i);
        if (hole[n - 1][i][2] != -1) enqueue(hole[n - 1][i][2], n - 1, i);
    }

    while (pq.size()) {
        tie(d, y, x) = pq.top(); pq.pop();
        if (height[y][x] < d) continue;
        for (int i = 0; i < 4; i++) {
            if (hole[y][x][i] == -1) continue;
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 0 || ny >= n || nx < 0 || nx >= m) continue;
            int nh = max(height[y][x], min(hole[y][x][i], height[ny][nx]));
            if (height[ny][nx] > nh) {
                height[ny][nx] = nh;
                pq.push({height[ny][nx], ny, nx});
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) ret += height[i][j];
    }
    cout << ret << '\n';
    return 0;
}