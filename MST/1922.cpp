//크루스칼 알고리즘
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, ret, root[1001];
vector<tuple<int, int, int>> edge;

int _find(int node) {
    if (root[node] == node) return node;
    return root[node] = _find(root[node]);
}

void _union(int a, int b) {
    root[_find(a)] = _find(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) root[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());
    for (auto it : edge) {
        tie(c, a, b) = it;
        if (_find(a) == _find(b)) continue; //사이클 생성
        _union(a, b);
        ret += c;
    }
    cout << ret << '\n';
    
    return 0;
}
*/

//프림 알고리즘
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, ret;
bool visited[1001];
vector<pair<int, int>> adj[1001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    pq.push({0, 1});
    while (pq.size()) {
        tie(c, b) = pq.top(); pq.pop();
        if (visited[b]) continue;
        visited[b] = 1; ret += c;
        for (auto it : adj[b]) {
            if (visited[it.first]) continue;
            pq.push({it.second, it.first});
        }
    }
    cout << ret << '\n';
    
    return 0;
}