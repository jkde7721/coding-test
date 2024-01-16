#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
bool isExist, visited[2001];
vector<int> adj[2001];

void dfs(int node, int depth) {
    if (depth >= 5) { 
        isExist = 1; return;
    }
    visited[node] = 1;
    for (int nxt : adj[node]) {
        if (!visited[nxt]) {
            dfs(nxt, depth + 1);
        }
    }
    visited[node] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 0; i < n; i++) {
        dfs(i, 1);
        if (isExist) break;
    }
    cout << isExist << '\n';
    
    return 0;
}