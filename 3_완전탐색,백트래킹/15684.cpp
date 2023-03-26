//메모리: 2020KB, 시간: 988ms
#include <iostream>
using namespace std;

int n, m, h, y, x, ladder[31][11], ret = 987654321;

bool isOk() {
    for (int i = 1; i <= n; i++) {
        int cur = i;
        for (int j = 1; j <= h; j++) {
            if (ladder[j][cur]) cur = ladder[j][cur];
        }
        if (cur != i) return false;
    }
    return true;
}

void build(int hor, int ver, int cnt) {
    if (cnt > ret || cnt > 3) return;
    if (isOk()) {
        ret = min(ret, cnt);
        return;
    }

    for (int i = hor; i <= h; i++) {
        for (int j = ver; j < n; j++) {
            if (ladder[i][j] || ladder[i][j + 1]) continue;
            ladder[i][j] = j + 1;
            ladder[i][j + 1] = j;
            build(i, j + 2, cnt + 1);
            ladder[i][j] = 0;
            ladder[i][j + 1] = 0;
        }
        ver = 1;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> h;
    for (int i = 0; i < m; i++) {
        cin >> y >> x;
        ladder[y][x] = x + 1;
        ladder[y][x + 1] = x;
    }
    build(1, 1, 0);
    cout << (ret == 987654321 ? -1 : ret) << '\n';

    return 0;
}