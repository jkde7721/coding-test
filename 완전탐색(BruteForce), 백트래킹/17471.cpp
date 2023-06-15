//메모리: 2020KB, 시간: 0ms
#include <iostream>
#include <vector>
#include <cstring>
#define INF 987654321
using namespace std;

int n, ingu[11], tmp, area, ret = INF, sum, idx1, idx0;
bool visited[11], group[11];
vector<int> adj[11];

int dfs(int idx, int grp) {
    int num = 1, area;
    visited[idx] = 1;
    for (int i = 0; i < adj[idx].size(); i++) {
        area = adj[idx][i];
        if (visited[area] || group[area] != grp) continue;
        num += dfs(area, grp);
    }
    return num;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ingu[i];
        sum += ingu[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        for (int j = 0; j < tmp; j++) {
            cin >> area;
            adj[i].push_back(area);
        }
    }

    for (int i = 1; i < (1 << (n - 1)); i++) {
        memset(visited, 0, sizeof(visited));
        memset(group, 0, sizeof(group));
        idx1 = idx0 = -1; tmp = 0;

        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                tmp += ingu[j + 1];
                if (idx1 == -1) idx1 = j + 1;
                group[j + 1] = 1;
            }
            else { if (idx0 == -1) idx0 = j + 1; }
        }

        if (dfs(idx1, 1) + dfs(idx0, 0) == n) {
            ret = min(ret, abs(sum - 2 * tmp));
        }
    }
    cout << (ret == INF ? -1 : ret) << '\n';

    return 0;
}