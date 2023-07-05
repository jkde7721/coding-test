//메모리: 8644KB, 시간: 84ms
//참고: https://www.acmicpc.net/board/view/83695
//그래프가 아닌 트리이기 때문에 dfs로 거리 구하기 가능 (A 노드 → B 노드까지의 경로가 오직 1개이기 때문)
#include <bits/stdc++.h>
using namespace std;

int n, u, v, d, dist, idx;
bool visited[100001];
vector<pair<int, int>> adj[100001];

void dfs(int node, int d) {
    if (d > dist) { dist = d; idx = node; }
    visited[node] = 1;
    for (auto it : adj[node]) {
        if (visited[it.first]) continue;
        dfs(it.first, d + it.second);
    }
    visited[node] = 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> u;
        while ((cin >> v) && v != -1 && (cin >> d)) {
            adj[u].push_back({v, d});
        }
    }
    dfs(1, 0); //임의의 정점
    dist = 0; dfs(idx, 0); //가장 먼 정점으로부터 다시 dfs
    cout << dist << '\n';
    return 0;
}