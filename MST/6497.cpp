//크루스칼 알고리즘 풀이
//메모리: 9068KB, 시간: 256ms
#include <bits/stdc++.h>
using namespace std;

int m, n, x, y, z, ret, root[200000];

int _find(int node) {
    if (root[node] == node) return node;
    return root[node] = _find(root[node]);
}

void _union(int x, int y) {
    root[_find(x)] = _find(y);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while ((cin >> m >> n) && (m != 0 || n != 0)) {
        vector<tuple<int, int, int>> edge; ret = 0;
        for (int i = 0; i < m; i++) root[i] = i;

        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            edge.push_back({z, x, y});
        }
        sort(edge.begin(), edge.end());
        for (auto& it : edge) {
            tie(z, x, y) = it;
            if (_find(x) == _find(y)) { ret += z; continue; }
            _union(x, y);
        }
        cout << ret << '\n';
    }
    return 0;
}

//프림 알고리즘 풀이
//메모리: 15044KB, 시간: 360ms
/*
#include <bits/stdc++.h>
using namespace std;

int m, n, x, y, z, ret;
bool visited[200000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while ((cin >> m >> n) && (m != 0 || n != 0)) {
        memset(visited, 0, sizeof(visited));
        vector<pair<int, int>> adj[200000]; ret = 0;

        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            adj[x].push_back({y, z});
            adj[y].push_back({x, z});
        }
        pq.push({0, 0});
        while (pq.size()) {
            tie(z, y) = pq.top(); pq.pop();
            if (visited[y]) { ret += z; continue; }
            visited[y] = 1;
            for (auto& it : adj[y]) {
                if (!visited[it.first]) pq.push({it.second, it.first});
            }
        }
        cout << ret << '\n';
    }
    return 0;
}
*/