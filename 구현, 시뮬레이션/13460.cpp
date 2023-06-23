#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

const int dy[] = {-1, 0, 1, 0}, dx[] = {0, 1, 0, -1};
int n, m, ry, rx, by, bx, ret;
char brd[10][10];

int go(int cnt, int ry, int rx, int by, int bx, int preDir) {
    if (cnt == 10) return INF;
    int nry, nrx, nby, nbx, ret = INF; bool rh, bh, move;
    for (int k = 0; k < 4; k++) {
        if (preDir == k) continue;
        nry = ry; nrx = rx; nby = by; nbx = bx; rh = bh = 0;
        while (1) {
            move = 0;
            //현재 구슬이 구멍에 빠지지 않았으면서, 장애물이 없고, 상대 구슬이 없으면 move
            if (nry != -1 && brd[nry + dy[k]][nrx + dx[k]] != '#' && (nry + dy[k] != nby || nrx + dx[k] != nbx)) { nry += dy[k]; nrx += dx[k]; move = 1; }
            if (nby != -1 && brd[nby + dy[k]][nbx + dx[k]] != '#' && (nby + dy[k] != nry || nbx + dx[k] != nrx)) { nby += dy[k]; nbx += dx[k]; move = 1; }
            if (!move) break;
            if (brd[nry][nrx] == 'O') { rh = 1; nry = nrx = -1; }
            if (brd[nby][nbx] == 'O') { bh = 1; nby = nbx = -1; }
        }
        if (nry == ry && nrx == rx && nby == by && nbx == bx) continue;
        if (bh) continue; //파란 구슬 구멍에 빠짐 
        if (rh) return cnt + 1; //빨간 구슬 구멍에 빠짐
        ret = min(ret, go(cnt + 1, nry, nrx, nby, nbx, k));
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> brd[i][j]; 
            if (brd[i][j] == 'R') { ry = i; rx = j; }
            if (brd[i][j] == 'B') { by = i; bx = j; }
        }
    }
    ret = go(0, ry, rx, by, bx, -1);
    cout << (ret == INF ? -1 : ret) << '\n';
    return 0;
}