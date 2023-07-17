//메모리: 2272KB, 시간: 28ms
/*
- 모든 노드를 방문하기 전 큐가 비면 사이클 존재, 즉 DAG가 아님
- 한 단계에서 enqueue되는 노드가 2개 이상인 경우 위상정렬 결과 여러 개 존재
➡️ 이 문제에서는 모든 노드 간 관계가 정의되어있기 때문에 위상정렬 결과 오직 1개이거나 없거나
*/
#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b, indegree[501];
bool adj[501][501]; //인접행렬 사용

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        vector<int> tmp, ret; queue<int> q;
        memset(adj, 0, sizeof(adj));
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a; indegree[a] = i;
            for (int j : tmp) adj[j][a] = 1;
            tmp.push_back(a);
        }
        cin >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            if (adj[a][b]) { adj[a][b] = 0; adj[b][a] = 1; indegree[b]--; indegree[a]++; }
            else { adj[a][b] = 1; adj[b][a] = 0; indegree[b]++; indegree[a]--; }
        }
        for (int i = 1; i <= n; i++) {
            if (!indegree[i]) q.push(i);
        }
        while (q.size()) {
            a = q.front(); q.pop();
            ret.push_back(a);
            for (int i = 1; i <= n; i++) {
                if (!adj[a][i]) continue;
                indegree[i]--;
                if (!indegree[i]) q.push(i);
            }
        }

        if (ret.size() != n) cout << "IMPOSSIBLE\n"; //DAG가 아님
        else {
            for (int i : ret) cout << i << ' ';
            cout << '\n';
        }
    }
    return 0;
}