//메모리: 2028KB, 시간: 0ms
/*
양의 사이클이 있다 하더라도
1. 애초에 시작 지점에서 사이클에 갈 수 X 
2. 사이클에서 도착 지점에 갈 수 X
3. 양의 사이클에 의한 도참 지점에 대한 완화가 n번의 for문 내에서 발생X → 단순 boolean flag 사용X
1번 → dist[j] != MIN
2, 3번 → bfs로 양의 사이클에서 도착 지점에 갈 수 있는지 확인 
*/
#include <bits/stdc++.h>
#define MIN -1e18
using namespace std;
typedef long long ll;

//dist 배열: 시작 도시에서 해당 도시까지 벌 수 있는 최대 금액 
int n, m, s, e, u, v, p, money[50];
ll dist[50];
bool visited[50];
vector<pair<int, int>> adj[50];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(dist, dist + 50, MIN);
    cin >> n >> s >> e >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> p;
        adj[u].push_back({v, p});
    }
    for (int i = 0; i < n; i++) cin >> money[i];

    dist[s] = money[s];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (auto it : adj[j]) {
                if (dist[j] != MIN && dist[it.first] < dist[j] - it.second + money[it.first]) {
                    dist[it.first] = dist[j] - it.second + money[it.first];
                    if (i == n - 1) { q.push(it.first); visited[it.first] = 1; } //양의 사이클 감지
                }
            }
        }
    }
    if (dist[e] == MIN) cout << "gg\n";
    else {
        while (q.size()) {
            u = q.front(); q.pop();
            if (u == e) { cout << "Gee\n"; return 0; }
            for (auto it : adj[u]) {
                if (visited[it.first]) continue;
                q.push(it.first); visited[it.first] = 1;
            }
        }
        cout << dist[e] << '\n';
    }
    return 0;
}

/*
input
3 0 2 4
0 1 9999
1 2 9999
1 1 9999
0 2 0
10000 10000 10000
output
Gee
----------
input
5 0 2 5
0 1 2
1 2 2
3 1 1
3 4 1
4 3 1
0 0 0 1 8
output
-4
*/