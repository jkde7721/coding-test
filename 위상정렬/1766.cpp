//BFS 풀이 (우선순위 큐를 이용한 위상정렬)
//메모리: 3964KB, 시간: 36ms
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, indegree[32001];
vector<int> adj[32001];
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        adj[a].push_back(b); indegree[b]++;
    }
    for (int i = 1; i <= n; i++) {
        if (!indegree[i]) pq.push(i); //먼저 풀어야 하는 문제들만 enqueue
    }
    while (pq.size()) {
        a = pq.top(); pq.pop(); //가장 쉬운 문제부터 먼저 품
        cout << a << ' ';
        for (int i : adj[a]) {
            indegree[i]--;
            if (!indegree[i]) pq.push(i);
        }
    }
    return 0;
}

//DFS 풀이 → 왜 틀리지??
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
    //어려운 문제를 먼저 풀도록 내림차순 정렬 (reverse하기 때문)
    for (int i = 1; i <= n; i++) sort(adj[i].begin(), adj[i].end(), greater<int>());
    //어려운 문제에 대해 먼저 DFS를 돌림
    for (int i = n; i >= 1; i--) {
        if (!visited[i]) dfs(i);
    }
    reverse(ret.begin(), ret.end());
    for (int i : ret) cout << i << ' ';
    return 0;
}
*/

/*
선행 문제를 푼 이후 풀 수 있는 문제들 중 가장 쉬운 문제를 풀어야 하는데 
DFS로는 선행 문제 다음의 문제 그냥 막 풀어버림 (가장 쉬운 문제인지 판별 없이)

반례
5 3
5 2
5 1
1 3
anw: 4 5 1 2 3
ret: 4 5 1 3 2
*/