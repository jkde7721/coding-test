#include <iostream>
using namespace std;

int n, l, a[100][100], b[100][100];

int solve(int path[100][100]) {
    int cnt, x, ret = 0;
    for (int y = 0; y < n; y++) {
        cnt = 1;
        for (x = 0; x < n - 1; x++) {
            if (path[y][x] == path[y][x + 1]) cnt++;
            else if (path[y][x] + 1 == path[y][x + 1] && cnt >= l) cnt = 1;
            else if (path[y][x] - 1 == path[y][x + 1] && cnt >= 0) cnt = -l + 1;
            else break;
        }
        if (x == n - 1 && cnt >= 0) ret++;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }
    cout << (solve(a) + solve(b)) << '\n';

    return 0;
}