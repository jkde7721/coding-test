//메모리: 10228KB, 시간: 188ms
//2차원 펜윅트리 사용 (y축 기준 구간합, x축 기준 구간합 계산)
#include <bits/stdc++.h>
#define y1 y
using namespace std;

int n, m, w, x1, x2, y1, y2, c, tree[1025][1025], num[1025][1025];

void update(int y, int x, int diff) {
    for (int i = y; i <= n; i += (i & -i)) {
        for (int j = x; j <= n; j += (j & -j)) {
            tree[i][j] += diff;
        }
    }
}

int sum(int y, int x) {
    int ret = 0;
    for (int i = y; i > 0; i -= (i & -i)) {
        for (int j = x; j > 0; j -= (j & -j)) {
            ret += tree[i][j];
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> num[i][j]; update(i, j, num[i][j]);
        }
    }
    for (int i = 0; i < m; i++) {
        cin >> w;
        if (w == 0) {
            cin >> y1 >> x1 >> c; 
            update(y1, x1, c - num[y1][x1]);
            num[y1][x1] = c;
        }
        else {
            cin >> y1 >> x1 >> y2 >> x2;
            cout << (sum(y2, x2) - sum(y2, x1-1) - sum(y1-1, x2) + sum(y1-1, x1-1)) << '\n';
        }
    }

    return 0;
}