#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int ret = INF, paper[10][10], color[6];

bool check(int y, int x, int w) {
    if (y + w > 10 || x + w > 10) return false;
    for (int i = y; i < y + w; i++) {
        for (int j = x; j < x + w; j++) {
            if (!paper[i][j]) return false;
        }
    }
    return true;
}

void mask(int y, int x, int w, int v) {
    for (int i = y; i < y + w; i++) {
        for (int j = x; j < x + w; j++) paper[i][j] = v;
    }
}

void go(int y, int x, int cnt) {
    if (cnt >= ret) return;
    if (y == 10) { ret = min(ret, cnt); return; }
    if (x == 10) { go(y + 1, 0, cnt); return; }
    if (!paper[y][x]) { go(y, x + 1, cnt); return; }
    for (int i = 5; i >= 1; i--) {
        if (color[i] >= 5) continue;
        if (check(y, x, i)) {
            mask(y, x, i, 0); color[i]++;
            go(y, x + i, cnt + 1);
            mask(y, x, i, 1); color[i]--;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) cin >> paper[i][j];
    }
    go(0, 0, 0);
    cout << (ret == INF ? -1 : ret) << '\n';

    return 0;
}