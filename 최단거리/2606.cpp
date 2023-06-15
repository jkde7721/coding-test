//컴퓨터 수, 즉 n이 작기 때문에 플로이드 워셜 알고리즘 가능
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, ret;
bool conn[101][101];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        conn[a][b] = conn[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == j || conn[i][j]) continue;
                if (conn[i][k] && conn[k][j]) conn[i][j] = conn[j][i] = 1;
            }
        }
    }
    for (int i = 2; i <= n; i++) ret += conn[1][i];
    cout << ret << '\n';

    return 0;
}