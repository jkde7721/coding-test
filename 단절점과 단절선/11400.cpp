//메모리: 14420KB, 시간: 188ms
#include <bits/stdc++.h>
using namespace std;

int v, e, a, b, cnt[100001], visitCnt = 1;
vector<int> adj[100001];
vector<pair<int, int>> ret;

int dfs(int node, int pre) {
    cnt[node] = visitCnt++;
    //minAdjCnt 변수: 현재 노드에서 pre-node 간선 사용하지 않고 갈 수 있는 노드들 중 최소 방문 번호
    int minAdjCnt = cnt[node];
    for (int i : adj[node]) {
        //pre-node 간선 사용X
        if (i == pre) continue;
        if (!cnt[i]) {
            int tmp = dfs(i, node); //자식 노드에서 node-i 간선 사용하지 않고 갈 수 있는 노드들 중 최소 방문 번호
            if (tmp > cnt[node]) ret.push_back({min(node, i), max(node, i)}); //node-i 간선은 단절선
            minAdjCnt = min(minAdjCnt, tmp);
        }
        else minAdjCnt = min(minAdjCnt, cnt[i]); 
    }
    return minAdjCnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //주어진 그래프는 연결 그래프
    dfs(1, 0);

    sort(ret.begin(), ret.end());
    cout << ret.size() << '\n';
    for (auto& p : ret) cout << p.first << ' ' << p.second << '\n';
    return 0;
}