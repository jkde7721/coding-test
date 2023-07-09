//메모리: 2020KB, 시간: 7916ms
/*
#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 1, 1, -1}, dx[] = {1, 1, -1, -1};
int n, chess[15][15];

void mask(int y, int x, vector<pair<int, int>>& v) {
    int _y = y, _x = x, ny, nx, idx = 0;
    for (int i = 0; i < n; i++) {
        if (!chess[y][i]) v.push_back({y, i});
        if (!chess[i][x]) v.push_back({i, x});
        chess[y][i] = 1; chess[i][x] = 1;
    }
    while (idx < 4) {
        ny = _y + dy[idx]; nx = _x + dx[idx];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) { 
            _y = y; _x = x; idx++; continue; 
        }
        if (!chess[ny][nx]) v.push_back({ny, nx});
        chess[ny][nx] = 1; _y = ny; _x = nx;
    }
}

int go(int y) {
    if (y == n) return 1;
    int ret = 0;
    for (int i = 0; i < n; i++) {
        if (chess[y][i]) continue;
        vector<pair<int, int>> v;
        mask(y, i, v);
        ret += go(y + 1);
        for (auto it : v) chess[it.first][it.second] = 0;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cout << go(0) << '\n';
    return 0;
}
*/

//메모리: 2020KB, 시간: 4072ms
#include <bits/stdc++.h>
using namespace std;

int n, chess[15]; //해당 행에서 퀸의 열 위치 저장 

int go(int y) {
    if (y == n) return 1;
    int ret = 0; bool ok;
    for (int i = 0; i < n; i++) {
        ok = true;
        for (int j = 0; j < y; j++) { //앞 행의 퀸들과 위치 비교 
            //열, 대각선 검사
            if (chess[j] == i || abs(chess[j] - i) == abs(j - y)) { 
                ok = false; break; 
            }
        }
        if (ok) {
            chess[y] = i;
            ret += go(y + 1);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    cout << go(0) << '\n';
    return 0;
}