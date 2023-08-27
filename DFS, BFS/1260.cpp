//메모리: 2316KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;

int n, m, v, a, b;
bool visited[1001], visited2[1001];
vector<int> adj[1001], ret, ret2;

void dfs(int node) {
    visited[node] = 1; ret.push_back(node);
    for (int next : adj[node]) {
        if (!visited[next]) dfs(next);
    }
}

void bfs(int node) {
    queue<int> q; q.push(node); 
    visited2[node] = 1; ret2.push_back(node);
    while (q.size()) {
        int cur = q.front(); q.pop();
        for (int next : adj[cur]) {
            if (!visited2[next]) {
                q.push(next);
                visited2[next] = 1; ret2.push_back(next);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> v;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end()); //방문할 수 있는 정점이 여러 개인 경우 정점 번호가 작은 것부터 방문
    
    dfs(v); bfs(v);
    for (int i : ret) cout << i << ' ';
    cout << '\n';
    for (int i : ret2) cout << i << ' ';
    return 0;
}