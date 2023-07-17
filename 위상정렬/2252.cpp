//위상정렬 BFS 풀이
//메모리: 4152KB, 시간: 28ms
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, indegree[32001];
vector<int> adj[32001], ret;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; indegree[b]++; //진입차수 +1 증가
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) q.push(i); //진입차수가 0인 경우 enqueue
    }
    while (q.size()) {
        a = q.front(); q.pop();
        ret.push_back(a);
        for (int i : adj[a]) {
            indegree[i]--;
            if (!indegree[i]) q.push(i);
        }
    }
    for (int i : ret) cout << i << ' ';
    
    return 0;
}

//위상정렬 DFS 풀이
//위상정렬의 결과는 DFS 순회 결과의 역순
//메모리: 4048KB, 시간: 28ms
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b;
bool visited[32001];
vector<int> adj[32001], ret;

void dfs(int node) {
    visited[node] = 1;
    for (int i : adj[node]) {
        if (visited[i]) continue;
        dfs(i);
    }
    ret.push_back(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
    }
    for (int i = 1; i <= n; i++) {
        if (!visited[i]) dfs(i);
    }
    reverse(ret.begin(), ret.end());
    for (int i : ret) cout << i << ' ';
    
    return 0;
}
*/