#include <bits/stdc++.h>
using namespace std;

int k, n, dir, ret;
string wh[4];

void _rotate(int n, int dir) {
    if (dir) rotate(wh[n].begin(), wh[n].begin() + 7, wh[n].end());
    else rotate(wh[n].begin(), wh[n].begin() + 1, wh[n].end());
}
void _lrorate(int n, int dir, char pre) {
    if (n < 0 || wh[n][2] == pre) return;
    _lrorate(n - 1, dir ^ 1, wh[n][6]);
    _rotate(n, dir);
}
void _rrorate(int n, int dir, char pre) {
    if (n > 3 || wh[n][6] == pre) return;
    _rrorate(n + 1, dir ^ 1, wh[n][2]);
    _rotate(n, dir);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 4; i++) cin >> wh[i];
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> n >> dir; n--; dir = (dir == -1 ? 0 : dir);
        _lrorate(n - 1, dir ^ 1, wh[n][6]);
        _rrorate(n + 1, dir ^ 1, wh[n][2]);
        _rotate(n, dir);
    }
    for (int i = 0; i < 4; i++) {
        if (wh[i][0] == '1') ret += pow(2, i);
    }
    cout << ret << '\n';
    return 0;
}