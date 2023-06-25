//메모리: 2996KB, 시간: 36ms
#include <bits/stdc++.h>
using namespace std;

int n, m, num[500][500], ni, nj, ret, tmp;
pair<int, int> d[19][3] = {
    {{0, 1}, {0, 2}, {0, 3}}, {{1, 0}, {2, 0}, {3, 0}}, {{0, 1}, {1, 0}, {1, 1}}, 
    {{1, 0}, {2, 0}, {2, 1}}, {{1, 0}, {0, 1}, {0, 2}}, {{0, 1}, {1, 1}, {2, 1}}, {{0, 1}, {0, 2}, {-1, 2}}, 
    {{1, 0}, {2, 0}, {2, -1}}, {{1, 0}, {1, 1}, {1, 2}}, {{0, 1}, {1, 0}, {2, 0}}, {{0, 1}, {0, 2}, {1, 2}},
    {{1, 0}, {1, 1}, {2, 1}}, {{0, 1}, {-1, 1}, {-1, 2}}, {{1, 0}, {1, -1}, {2, -1}}, {{0, 1}, {1, 1}, {1, 2}},
    {{0, 1}, {0, 2}, {1, 1}}, {{1, 0}, {2, 0}, {1, -1}}, {{0, 1}, {0, 2}, {-1, 1}}, {{1, 0}, {2, 0}, {1, 1}}};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> num[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int k = 0; k < 19; k++) {
                tmp = num[i][j];
                for (int r = 0; r < 3; r++) {
                    ni = i + d[k][r].first; nj = j + d[k][r].second;
                    if (ni < 0 || ni >= n || nj < 0 || nj >= m) { tmp = 0; break; }
                    tmp += num[ni][nj];
                }
                ret = max(ret, tmp);
            }
        }
    }
    cout << ret << '\n';
    return 0;
}