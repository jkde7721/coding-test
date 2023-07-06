//메모리: 16408KB, 시간: 216ms
//가장 높은 등수: x를 기준으로 확실히 앞에 누가 있는지 dfs (간선 방향 반대) 
//가장 낮은 등수: x를 기준으로 확실히 뒤에 누가 있는지 dfs
/*
2 → 1
3 → 4 → 1
=> 1의 가장 높은 등수: 4, 가장 낮은 등수: 5
*/
#include <bits/stdc++.h>
using namespace std;

int n, m, x, a, b;
bool visited[100001], visited2[100001];
vector<int> adj[100001], adj2[100001];

int dfs(vector<int>* adj, int u, bool* visited) {
    int dep = 1;
    for (int v : adj[u]) {
        if (!visited[v]) {
            visited[v] = 1;
            dep += dfs(adj, v, visited);
        }
    }
    return dep;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    cout << dfs(adj2, x, visited2) << ' ' << (n - dfs(adj, x, visited) + 1) << '\n';
    return 0;
}

//bfs 풀이 
//메모리: 16312KB, 시간: 208ms
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, x, a, b, cnt;
bool visited[100001];
vector<int> adj[100001], adj2[100001];
queue<int> q;

int bfs(vector<int> adj[], int cur) {
    memset(visited, 0, sizeof(visited)); cnt = 0;
    q.push(cur); visited[cur] = 1;
    while (q.size()) {
        cur = q.front(); q.pop();
        for (int i : adj[cur]) {
            if (visited[i]) continue;
            q.push(i); visited[i] = 1; cnt++;
        }
    }
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; 
        adj[a].push_back(b);
        adj2[b].push_back(a);
    }
    cout << bfs(adj2, x) + 1 << ' ' << n - bfs(adj, x) << '\n';

    return 0;
}
*/