#include <iostream>
#include <cstring>
#include <numeric>
#include <vector>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int n, m, lab[8][8], visited[8][8], mx, wall = 3;
vector<pair<int, int>> v;

void dfs(int y, int x) {
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || nx < 0 || ny >= n || nx >= m || lab[ny][nx] == 1) continue;
        if (visited[ny][nx]) continue;
        dfs(ny, nx); 
    }
}

void init(pair<int, int> idx, int value) {
    lab[idx.first][idx.second] = value;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> lab[i][j];
            if (lab[i][j] == 0) v.push_back({i, j});
            if (lab[i][j] == 1) wall++;
        }
    }
    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                init(v.at(i), 1); init(v.at(j), 1); init(v.at(k), 1);
                
                memset(visited, 0, sizeof(visited));
                for (int y = 0; y < n; y++) {
                    for (int x = 0; x < m; x++) {
                        if (lab[y][x] == 2 && !visited[y][x]) {
                            dfs(y, x);
                        }
                    }
                }
                mx = max(mx, (n * m - wall - accumulate(&visited[0][0], &visited[0][0] + 64, 0)));
                
                init(v.at(i), 0); init(v.at(j), 0); init(v.at(k), 0);
            }
        }
    }
    cout << mx << '\n';

    return 0;
}