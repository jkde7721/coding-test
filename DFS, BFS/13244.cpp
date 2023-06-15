#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int t, n, m, a, b;
vector<int> nodes[1001];
bool visited[1001];

int dfs(int idx) {
    int cnt = 1;
    visited[idx] = 1;
    for (int i : nodes[idx]) {
        if (visited[i]) continue;
        cnt += dfs(i);
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t > 0) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) { 
            cin >> a >> b;
            nodes[a].push_back(b);
            nodes[b].push_back(a);
        }
        if (n - 1 == m && n == dfs(1)) cout << "tree\n";
        else cout << "graph\n";

        for (int i = 1; i <= n; i++) { nodes[i].clear(); }
        memset(visited, 0, sizeof(visited));
        t--;
    }

    return 0; 
}