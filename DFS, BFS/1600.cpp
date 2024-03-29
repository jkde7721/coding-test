//메모리: 7040KB, 시간: 104ms
#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;

//visited 배열: 해당 y, x 위치에 k번 남기고 도착하는 최단 거리 저장
const int dy[] = {-1, 0, 1, 0, -1, -2, -2, -1, 1, 2, 2, 1}, dx[] = {0, 1, 0, -1, -2, -1, 1, 2, 2, 1, -1, -2};
int K, W, H, visited[200][200][31], y, x, k, ny, nx, nk, ret = MAX;
bool _map[200][200];
queue<tuple<int, int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(&visited[0][0][0], &visited[0][0][0] + 200*200*31, MAX);
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> _map[i][j];
    }
    q.push({0, 0, K}); visited[0][0][K] = 1;
    while (q.size()) {
        tie(y, x, k) = q.front(); q.pop();
        for (int i = 0; i < 12; i++) {
            if (i >= 4 && k == 0) break;
            ny = y + dy[i]; nx = x + dx[i]; nk = i >= 4 ? k-1 : k;
            if (ny < 0 || ny >= H || nx < 0 || nx >= W || _map[ny][nx] || visited[y][x][k] + 1 >= visited[ny][nx][nk]) continue;
            q.push({ny, nx, nk}); visited[ny][nx][nk] = visited[y][x][k] + 1;
        }
    }
    for (int i = 0; i <= K; i++) ret = min(ret, visited[H-1][W-1][i]);
    cout << (ret == MAX ? -1 : ret-1) << '\n';
    return 0;
}

//왜 DP 풀이 틀림...?
/*
#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;

const int dy[] = {-1, 0, 1, 0, -1, -2, -2, -1, 1, 2, 2, 1}, dx[] = {0, 1, 0, -1, -2, -1, 1, 2, 2, 1, -1, -2};
int K, W, H, dp[200][200][31], ret;
bool _map[200][200];

int go(int y, int x, int k) {
    if (y == H-1 && x == W-1) return 0;
    int& ret = dp[y][x][k];
    if (ret == 0) {
        ret = MAX;
        for (int i = 0; i < 12; i++) {
            if (i >= 4 && k == 0) break;
            int ny = y + dy[i], nx = x + dx[i], nk = i >= 4 ? k-1 : k;
            if (ny < 0 || ny >= H || nx < 0 || nx >= W || _map[ny][nx]) continue;
            ret = min(ret, go(ny, nx, nk) + 1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> K >> W >> H;
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) cin >> _map[i][j];
    }
    ret = go(0, 0, K);
    cout << (ret == MAX ? -1 : ret) << '\n';
    return 0;
}
*/