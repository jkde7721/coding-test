//크루스칼 알고리즘 풀이
//메모리: 20976KB, 시간: 380ms
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, root[100001], ret, mx;
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
    for (int i = 1; i <= n; i++) root[i] = i; //자기 자신으로만 구성된 트리 초기화
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());
    for (auto& it : edge) {
        tie(c, a, b) = it;
        if (_find(a) == _find(b)) continue; //사이클 생성하는 간선
        ret += c; mx = max(mx, c); _union(a, b);
    }
    cout << ret - mx << '\n';
    return 0;
}

//프림 알고리즘 풀이
//메모리: 44016KB, 시간: 632ms
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, a, b, c, ret, mx;
bool visited[100001];
vector<pair<int, int>> adj[100001];
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
    pq.push({0, 1}); //임의의 정점에서 시작
    while (pq.size()) {
        tie(c, b) = pq.top(); pq.pop();
        if (visited[b]) continue;
        //MST 집합에 정점 b 추가
        visited[b] = 1; ret += c; mx = max(mx, c);
        for (auto& it : adj[b]) {
            if (!visited[it.first]) pq.push({it.second, it.first});
        }
    }
    cout << ret - mx << '\n';
    return 0;
}
*/