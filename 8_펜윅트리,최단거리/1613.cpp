//메모리: 2176KB, 시간: 80ms
#include <bits/stdc++.h>
using namespace std;

int n, k, s, a, b;
bool dist[401][401];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        dist[a][b] = 1;
    }

    for (int m = 1; m <= n; m++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][m] && dist[m][j]) dist[i][j] = 1;
            }
        }
    }

    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> a >> b;
        if (dist[a][b]) cout << "-1\n";
        else if (dist[b][a]) cout << "1\n";
        else cout << "0\n";
    }

    return 0;
}