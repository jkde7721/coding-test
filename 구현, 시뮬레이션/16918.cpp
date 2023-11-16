#include <bits/stdc++.h>
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int r, c, n, t, y, x, ny, nx;
pair<char, int> _map[200][200]; //폭탄과 해당 폭탄이 설치된 시간 함께 저장
queue<tuple<int, int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> n;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> _map[i][j].first;
            if (_map[i][j].first == 'O') q.push({i, j, 0});
        }
    }
    for (int cur = 2; cur <= n; cur++) {
        //폭탄 설치
        if (cur % 2 == 0) {
            for (int i = 0; i < r; i++) {
                for (int j = 0; j < c; j++) {
                    if (_map[i][j].first == '.') {
                        _map[i][j] = {'O', cur};
                        q.push({i, j, cur});
                    }
                }
            }
        }
        //폭탄 제거
        else {
            while (q.size()) {
                tie(y, x, t) = q.front();
                if (t + 3 > cur) break;
                q.pop();
                if (t != _map[y][x].second) continue;
                
                _map[y][x].first = '.';
                for (int i = 0; i < 4; i++) {
                    int ny = y + dy[i], nx = x + dx[i];
                    if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                    _map[ny][nx].first = '.';
                }
            }
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) cout << _map[i][j].first;
        cout << '\n';
    }
    return 0;
}