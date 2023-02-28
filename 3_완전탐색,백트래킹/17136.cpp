#include <iostream>
#include <numeric>
using namespace std;

int pap[10][10], cnt[6], ret = 25;

bool isFit(int y, int x, int k) {
    for (int i = y; i < y + k; i++) {
        for (int j = x; j < x + k; j++) {
            if (i == 10 || j == 10 || pap[i][j] == 0) return false;
        }
    }
    return true;
}

void glue(int y, int x, int k, int v) {
    for (int i = y; i < y + k; i++) {
        for (int j = x; j < x + k; j++) {
            pap[i][j] = v;
        }
    }
}

void dfs(int y, int x) {
    if (accumulate(cnt, cnt + 6, 0) >= ret) return;

    if (y == 10) {
        ret = min(ret, accumulate(cnt, cnt + 6, 0));
        return;
    }
    if (x == 10) {
        dfs(y + 1, 0);
        return;
    }
    if (pap[y][x] == 0) {
        dfs(y, x + 1);
        return;
    }

    for (int k = 5; k >= 1; k--) {
        if (cnt[k] == 5) continue;
        if (isFit(y, x, k)) {
            cnt[k]++;
            glue(y, x, k, 0);
            dfs(y, x + k);
            cnt[k]--;
            glue(y, x, k, 1);
        }
    }
}

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cin >> pap[i][j];
        }
    }
    dfs(0, 0);
    cout << (ret == 25 ? -1 : ret) << '\n';

    return 0;
}