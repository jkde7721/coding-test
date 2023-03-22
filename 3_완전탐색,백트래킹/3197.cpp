//메모리: 27164KB, 시간: 208ms
/*
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, visited[1500][1500], visited2[1500][1500], y, x, y1 = -1, x1, y2, x2;
char lake[1500][1500];
string str;
queue<pair<int, int>> q, q2;

int main() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < c; j++) {
            if (str[j] == '.' || str[j] == 'L') {
                visited[i][j] = 1;
                q.push({i, j});
            }
            if (str[j] == 'L') {
                if (y1 == -1) { y1 = i; x1 = j; }
                else { y2 = i; x2 = j; }
            }
            lake[i][j] = str[j];
        }
    }

    while (q.size()) {
        tie(y, x) = q.front(); q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i]; int nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited[ny][nx]) continue;
            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    q.push({y1, x1});
    visited2[y1][x1] = 1;
    while (!visited2[y2][x2]) {
        queue<pair<int, int>> tmp;
        while (q.size()) {
            tie(y, x) = q.front(); q.pop();
            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i]; int nx = x + dx[i];
                if (ny < 0 || ny >= r || nx < 0 || nx >= c || visited2[ny][nx]) continue;
                if (visited[ny][nx] > visited2[y][x]) {
                    visited2[ny][nx] = visited2[y][x] + 1;
                    tmp.push({ny, nx});
                } else {
                    visited2[ny][nx] = visited2[y][x];
                    q.push({ny, nx});
                }
            }
        }
        q = tmp;
    }
    cout << visited2[y2][x2] - 1 << '\n';

    return 0;
}
*/

//메모리: 14092KB, 시간: 116ms
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, y1, x1, days;
bool water_visited[1500][1500], swan_visited[1500][1500];
char lake[1500][1500];
string str;
queue<pair<int, int>> water_q, water_tmp, swan_q, swan_tmp;

bool move_swan() {
    while (swan_q.size()) {
        int y, x; tie(y, x) = swan_q.front(); swan_q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || swan_visited[ny][nx]) continue;
            if (lake[ny][nx] == '.') swan_q.push({ny, nx});
            if (lake[ny][nx] == 'X') swan_tmp.push({ny, nx}); 
            if (lake[ny][nx] == 'L') return true;
            swan_visited[ny][nx] = 1;
        }
    }
    swap(swan_q, swan_tmp);
    return false;
}

void melt_ice() {
    while (water_q.size()) {
        int y, x; tie(y, x) = water_q.front(); water_q.pop();
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i], nx = x + dx[i];
            if (ny < 0 || ny >= r || nx < 0 || nx >= c || water_visited[ny][nx]) continue;
            water_visited[ny][nx] = 1;
            water_tmp.push({ny, nx}); 
            lake[ny][nx] = '.';
        }
    }
    swap(water_q, water_tmp);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> str;
        for (int j = 0; j < c; j++) {
            lake[i][j] = str[j];
            if (str[j] == '.' || str[j] == 'L') {
                water_visited[i][j] = 1;
                water_q.push({i, j});
            }
            if (str[j] == 'L') { y1 = i; x1 = j; }
        }
    }

    swan_q.push({y1, x1}); swan_visited[y1][x1] = 1;
    while (!move_swan()) {
        melt_ice();
        days++;
    }
    cout << days << '\n';

    return 0;
}