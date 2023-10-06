//간선의 가중치가 모두 1로 동일하기 때문에 일반적인 BFS 풀이 가능
//만약 간선의 가중치가 양의 정수이면서 모두 다르다면 BFS 풀이 불가능, 다익스트라 풀이 가능
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, k, x, a, b, cur, dist[300001];
vector<int> adj[300001], ret;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(dist, dist + 300001, INF);
    cin >> n >> m >> k >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    dist[x] = 0; q.push(x);
    while (q.size()) {
        cur = q.front(); q.pop();
        for (int next : adj[cur]) {
            if (dist[next] > dist[cur] + 1) {
                dist[next] = dist[cur] + 1; q.push(next);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] == k) ret.push_back(i);
    }
    if (ret.empty()) cout << -1 << '\n';
    for (int i : ret) cout << i << '\n';
    return 0;
}