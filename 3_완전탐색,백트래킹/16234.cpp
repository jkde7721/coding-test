#include <iostream>
#include <cstring>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1}; 
int n, l, r, a[50][50], visited[50][50], pop[2501], k, num, ret;

int dfs(int y, int x) {
    visited[y][x] = k; num++;
    int sum = a[y][x];

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny < 0 || ny >= n || nx < 0 || nx >= n) continue;
        if (visited[ny][nx]) continue;
        
        int diff = abs(a[y][x] - a[ny][nx]);
        if (diff >= l && diff <= r) {
            sum += dfs(ny, nx);
        }
    }
    return sum;
}

void move() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            a[i][j] = pop[visited[i][j]];
        }
    }
}

int main() {
    cin >> n >> l >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }

    while (1) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j]) {
                    k++; num = 0;
                    pop[k] = dfs(i, j) / num;
                }
            }
        }
        if (k == n*n) {
            break;
        }

        move();
        ret++;
        k = 0;
        memset(visited, 0, sizeof(visited));
        memset(pop, 0, sizeof(pop));
    }
    cout << ret << '\n';

    return 0;
}