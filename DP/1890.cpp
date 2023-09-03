//Top-Down 방식 풀이
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//dp 배열: 현재 위치에서 (n-1, n-1) 위치까지 가는 경로의 개수 저장
const int dy[] = {0, 1}, dx[] = {1, 0};
int n, _map[100][100];
ll dp[100][100];

ll go(int y, int x) {
    ll& ret = dp[y][x];
    if (ret == -1) {
        ret = 0;
        for (int i = 0; i < 2; i++) {
            int ny = y + dy[i] * _map[y][x], nx = x + dx[i] * _map[y][x];
            if (ny >= n || nx >= n || _map[ny][nx] == 0) continue;
            ret += go(ny, nx);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> _map[i][j];
    }
    memset(dp, -1, sizeof(dp)); 
    dp[n-1][n-1] = _map[n-1][n-1] = 1; //위의 _map[ny][nx] == 0 조건식 때문
    cout << go(0, 0) << '\n';
    return 0;
}

//Bottom-Up 방식 풀이
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, _map[100][100];
ll dp[100][100];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) cin >> _map[i][j];
    }
    dp[0][0] = 1; _map[n-1][n-1] = 1;
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int rx = x + _map[y][x], dy = y + _map[y][x];
            if (rx < n && _map[y][rx] != 0) dp[y][rx] += dp[y][x];
            if (dy < n && _map[dy][x] != 0) dp[dy][x] += dp[y][x];
        }
    }
    cout << dp[n-1][n-1] << '\n';
    return 0;
}
*/