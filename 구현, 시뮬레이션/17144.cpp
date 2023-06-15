//메모리: 2040KB, 시간: 36ms
#include <iostream>
#include <cstring>
#include <numeric>
using namespace std;

const int dy[] = {-1, 0, 1, 0};
const int dx[] = {0, 1, 0, -1};
int r, c, t, y1, x1, y2, x2, air[50][50], tmp[50][50];

void spread() {
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            if (air[i][j] < 5) continue;
            int value = air[i][j] / 5, num = 0;
            for (int k = 0; k < 4; k++) {
                int ny = i + dy[k], nx = j + dx[k];                
                if (ny < 0 || ny >= r || nx < 0 || nx >= c) continue;
                if ((ny == y1 && nx == x1) || (ny == y2 && nx == x2)) continue;
                tmp[ny][nx] += value; num++;
            }
            tmp[i][j] -= value * num;
        }
    }
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            air[i][j] += tmp[i][j];
        }
    }
}

void clean() {
    for (int i = y1; i > 0; i--) air[i][x1] = air[i - 1][x1];
    air[y1][x1] = 0;
    for (int i = 0; i < c - 1; i++) air[0][i] = air[0][i + 1];
    for (int i = 0; i < y1; i++) air[i][c - 1] = air[i + 1][c - 1];
    for (int i = c - 1; i > 0; i--) air[y1][i] = air[y1][i - 1];

    for (int i = y2; i < r - 1; i++) air[i][x2] = air[i + 1][x2];
    air[y2][x2] = 0;
    for (int i = 0; i < c - 1; i++) air[r - 1][i] = air[r - 1][i + 1];
    for (int i = r - 1; i > y2; i--) air[i][c - 1] = air[i - 1][c - 1];
    for (int i = c - 1; i > 0; i--) air[y2][i] = air[y2][i - 1];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> r >> c >> t;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> air[i][j];
            if (air[i][j] == -1) {
                if (y1 == 0 && x1 == 0) { y1 = i; x1 = j; }
                else { y2 = i; x2 = j; }
                air[i][j] = 0;
            }
        }
    }
    while (t > 0) {
        spread();
        clean();
        memset(tmp, 0, sizeof(tmp));
        t--;
    }
    cout << accumulate(&air[0][0], &air[0][0] + 2500, 0) << '\n';

    return 0;
}