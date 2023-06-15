//메모리: 2344KB, 시간: 0ms
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m, x, dist[1001], dist2[1001], u, v, t, ret;
vector<pair<int, int>> adj[1001], adj2[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int dist[1001], vector<pair<int, int>> adj[1001]) {
    fill(dist, dist + 1001, INF);
    dist[x] = 0; pq.push({0, x});
    while (pq.size()) {
        tie(t, u) = pq.top(); pq.pop();
        if (dist[u] < t) continue;
        for (auto it : adj[u]) {
            if (dist[it.first] > dist[u] + it.second) {
                dist[it.first] = dist[u] + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> t;
        adj[u].push_back({v, t});
        adj2[v].push_back({u, t}); //간선 뒤집음
    }
    dijkstra(dist, adj); //come
    dijkstra(dist2, adj2); //go
    for (int i = 1; i <= n; i++) {
        ret = max(ret, dist[i] + dist2[i]);
    }
    cout << ret << '\n';

    return 0;
}