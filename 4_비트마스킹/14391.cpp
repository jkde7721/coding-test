//메모리: 2020KB, 시간: 28ms
/*
#include <iostream>
#include <cstring>
using namespace std;

const int dy[] = {0, 1};
const int dx[] = {1, 0};
int n, m, ret, sum;
char paper[4][4];
bool visited[4][4], dir[4][4];

string dfs(int y, int x) {
    visited[y][x] = 1;
    string num(1, paper[y][x]);
    int ny = y + dy[dir[y][x]], nx = x + dx[dir[y][x]];
    if (ny >= n || nx >= m || dir[y][x] != dir[ny][nx]) return num;

    num += dfs(ny, nx);
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> paper[i][j];
        }
    }
    for (int k = 0; k < (1 << n*m); k++) {
        sum = 0; memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dir[i][j] = (k & 1 << (m * i + j) ? 1 : 0);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) sum += stoi(dfs(i, j));
            }
        }
        ret = max(ret, sum);
    }
    cout << ret << '\n';

    return 0;
}
*/

//메모리: 2020KB, 시간: 12ms
/*
#include <iostream>
#include <cstring>
using namespace std;

const int dy[] = {0, 1};
const int dx[] = {1, 0};
int n, m, ret, sum, num, ny, nx, y, x, paper[4][4];
bool visited[4][4], dir[4][4];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &paper[i][j]);
        }
    }
    for (int k = 0; k < (1 << n*m); k++) {
        sum = 0; memset(visited, 0, sizeof(visited));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dir[i][j] = (k & 1 << (m * i + j) ? 1 : 0);
            }
        }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    num = 0; y = i; x = j;
                    while (1) {
                        visited[y][x] = 1; 
                        num = num * 10 + paper[y][x];
                        ny = y + dy[dir[y][x]]; nx = x + dx[dir[y][x]];
                        if (ny >= n || nx >= m || dir[y][x] != dir[ny][nx]) break;
                        y = ny; x = nx;
                    }
                    sum += num;
                }
            }
        }
        ret = max(ret, sum);
    }
    cout << ret << '\n';

    return 0;
}
*/

//메모리: 2020KB, 시간: 8ms
//visited, dir 배열 사용하지 않고 풀어보기 (중첩 루프 3개까지만)
#include <iostream>
using namespace std;

int n, m, sum, ret, tmp, nums[4][4];

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%1d", &nums[i][j]);
        }
    }
    for (int k = 0; k < (1 << n*m); k++) {
        sum = 0;
        for (int i = 0; i < n; i++) {
            tmp = 0;
            for (int j = 0; j < m; j++) {
                if (!(k & (1 << m * i + j))) tmp = tmp * 10 + nums[i][j];
                else { sum += tmp; tmp = 0; }
            }
            if (tmp != 0) sum += tmp;
        }
        for (int j = 0; j < m; j++) {
            tmp = 0;
            for (int i = 0; i < n; i++) {
                if (k & (1 << m * i + j)) tmp = tmp * 10 + nums[i][j];
                else { sum += tmp; tmp = 0; }
            }
            if (tmp != 0) sum += tmp;
        }
        ret = max(ret, sum);
    }
    cout << ret << '\n';

    return 0;
}