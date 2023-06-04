//메모리: 2280KB, 시간: 40ms
//다익스트라 + dfs로 최단거리 경로 무효화 + 다익스트라
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

typedef struct path {
    int v, p;
    bool valid;
} Path;

int n, m, s, d, u, v, p, dist[500];
bool minPath[500]; //해당 노드가 최단거리 경로에 속하는지 여부

void dijkstra(vector<vector<Path>>& adj) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    fill(dist, dist + 500, INF);
    dist[s] = 0; pq.push({0, s});
    while (pq.size()) {
        tie(p, u) = pq.top(); pq.pop();
        if (dist[u] < p) continue;
        for (auto& it : adj[u]) {
            if (it.valid && dist[it.v] > p + it.p) {
                dist[it.v] = p + it.p;
                pq.push({dist[it.v], it.v});
            }
        }
    }
}

bool dfs(int node, vector<vector<Path>>& adj) {
    for (auto& it : adj[node]) {
        if (dist[node] + it.p != dist[it.v]) continue;
        if (minPath[it.v] || dfs(it.v, adj)) {
            minPath[node] = 1; it.valid = 0;
        }
    }
    return minPath[node];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while ((cin >> n >> m) && n != 0 && m != 0) {
        cin >> s >> d;
        vector<vector<Path>> adj(n);
        for (int i = 0; i < m;  i++) {
            cin >> u >> v >> p;
            adj[u].push_back({v, p, 1});
        }
        dijkstra(adj);
        
        //최단거리 경로 invalid 처리
        memset(minPath, 0, sizeof(minPath));
        minPath[d] = 1; dfs(s, adj);

        dijkstra(adj);
        cout << (dist[d] == INF ? -1 : dist[d]) << '\n';
    }
    return 0;
}