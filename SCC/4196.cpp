//메모리: 14148KB, 시간: 116ms
//SCC(코사라주 알고리즘) 풀이 → 스택에 push되는 순서는 결국 위상정렬의 역방향 순서와 same
/*
코사라주 알고리즘 응용 (참고: https://www.acmicpc.net/board/view/32925)
코사라주 알고리즘의 스택 상단에는 최대한 많은 노드들과 연결된 노드들이 위치 (인접 노드 모두 방문 후 스택에 push하기 때문)
→ 코사라주 알고리즘의 스택을 사용하여 2번째 DFS에서 역방향이 아닌 정방향 탐색 수행
*/
#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y, ret;
bool visited[100001];
stack<int> stk;

void dfs(int node, vector<int> adj[], bool first) {
    visited[node] = 1;
    for (int i : adj[node]) {
        if (!visited[i]) dfs(i, adj, first);
    }
    if (first) stk.push(node);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof(visited));
        vector<int> adj[100001]; ret = 0;
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) dfs(i, adj, 1);
        }
        memset(visited, 0, sizeof(visited));
        while (stk.size()) {
            if (!visited[stk.top()]) { dfs(stk.top(), adj, 0); ret++; }
            stk.pop(); 
        }
        cout << ret << '\n';
    }
    return 0;
}

/*
//메모리: 27176KB, 시간: 140ms
//SCC(타잔 알고리즘) + 위상정렬 풀이
//DAG가 아닌 그래프를 위상정렬하기 위해 SCC를 하나의 노드로 묶음, 사실 타잔 알고리즘이 위상정렬도 해줌
#include <bits/stdc++.h>
using namespace std;

int t, n, m, x, y, lowLink[100001], visitCnt, ret;
bool finished[100001], visited[100001];
stack<int> stk;

int dfs(int node, vector<int> adj[], vector<vector<int>>& scc) {
    stk.push(node); lowLink[node] = visitCnt++;
    int ll = lowLink[node];
    for (int i : adj[node]) {
        if (finished[i]) continue;
        if (!lowLink[i]) ll = min(ll, dfs(i, adj, scc));
        else ll = min(ll, lowLink[i]);
    }
    if (ll == lowLink[node]) {
        vector<int> v; int tmp = -1;
        while (tmp != node) {
            tmp = stk.top(); stk.pop();
            v.push_back(tmp); finished[tmp] = 1;
        }
        scc.push_back(v);
    }
    return lowLink[node] = ll;
}

void dfs(int node, vector<int> adj[]) {
    visited[node] = 1;
    for (int i : adj[node]) {
        if (!visited[i]) dfs(i, adj);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        memset(lowLink, 0, sizeof(lowLink));
        memset(finished, 0, sizeof(finished));
        memset(visited, 0, sizeof(visited));
        vector<int> adj[100001]; vector<vector<int>> scc;
        visitCnt = 1; ret = 0;

        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> x >> y;
            adj[x].push_back(y);
        }
        for (int i = 1; i <= n; i++) {
            if (!lowLink[i]) dfs(i, adj, scc);
        }
        //scc는 SCC를 한 노드로 하는 DAG로 위상정렬의 역방향
        reverse(scc.begin(), scc.end());
        for (vector<int>& v : scc) {
            for (int i : v) {
                if (!visited[i]) { dfs(i, adj); ret++; }
            }
        }
        cout << ret << '\n';
    }
    
    return 0;
}
*/