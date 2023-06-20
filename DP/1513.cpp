//메모리: 28456KB, 시간: 88ms
//2^2500의 시간복잡도로 완탐 풀이도 가능, but 시간초과 발생 → DP 풀이
/*
#include <bits/stdc++.h>
#define MOD 1000007;
using namespace std;

const int dy[] = {0, -1}, dx[] = {-1, 0};
//dp 배열: 해당 y, x 위치에 도착하기까지 해당 횟수만큼 해당 번호 보다 작거나 같은 오락실을 방문하는 경로의 개수 저장 (y, x 위치의 오락실 포함)
int n, m, c, city[51][51], y, x, dp[51][51][51][51];

int go(int y, int x, int cnt, int num) {
    if (cnt < 0 || city[y][x] > num) return 0;
    int& ret = dp[y][x][cnt][num];
    if (ret == -1) {
        int ny, nx; ret = 0;
        for (int i = 0; i < 2; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny < 1 || nx < 1) continue;
            ret += go(ny, nx, cnt - (city[y][x] > 0), (city[y][x] > 0 ? city[y][x] : num));
            ret %= MOD;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        cin >> y >> x;
        city[y][x] = i;
    }
    memset(dp, -1, sizeof(dp)); 
    for (int i = 0; i < 51; i++) dp[1][1][(city[1][1] > 0)][i] = 1;
    for (int i = 0; i <= c; i++) {
        cout << go(n, m, i, c) << ' ';
    }

    return 0;
}
*/

//메모리: 27432KB, 시간: 108ms
#include <bits/stdc++.h>
#define MOD 1000007
using namespace std;

const int dy[] = {1, 0}, dx[] = {0, 1};
//dp 배열: 현재 y, x에서 지금까지 최대 인덱스 번호의 오락실을 방문했을 때 앞으로 오락실을 인덱스번 방문하는 경로의 개수 저장 
int n, m, c, city[50][50], y, x, dp[50][50][51][51];

int go(int y, int x, int idx, int cnt)   {
    if (y == n - 1 && x == m - 1) {
        if (cnt == 0) return 1;
        return 0;
    }
    if (cnt < 0) return 0;
    int& ret = dp[y][x][idx][cnt];
    if (ret == -1) {
        ret = 0; int ny, nx;
        for (int i = 0; i < 2; i++) {
            ny = y + dy[i]; nx = x + dx[i];
            if (ny >= n || nx >= m) continue;
            if (city[ny][nx] && !cnt) continue;
            if (city[ny][nx] && city[ny][nx] <= idx) continue;
            ret += go(ny, nx, (city[ny][nx] ? city[ny][nx] : idx), (city[ny][nx] ? cnt - 1 : cnt));
            ret %= MOD;
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    memset(dp, -1, sizeof(dp));
    cin >> n >> m >> c;
    for (int i = 1; i <= c; i++) {
        cin >> y >> x;
        city[--y][--x] = i;
    }
    for (int i = 0; i <= c; i++) {
        cout << go(0, 0, city[0][0], i - (city[0][0] ? 1 : 0)) << ' '; 
    }
    return 0;
}