//모든 노드 간 edge 존재해서 모두 체크하면 시간초과 → 최소 비용의 즉 인접한 edge만 선택 
//크루스칼 알고리즘 
//메모리: 13324KB, 시간: 104ms
#include <bits/stdc++.h>
using namespace std;

typedef struct Planet {
    int x, y, z, idx;
} Planet;

int n, ret, d, a, b, root[100000];
vector<tuple<int, int, int>> edge;
Planet p[100000];

bool cmpx(Planet p1, Planet p2) { return p1.x < p2.x; }
bool cmpy(Planet p1, Planet p2) { return p1.y < p2.y; }
bool cmpz(Planet p1, Planet p2) { return p1.z < p2.z; }

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
    cin >> n;
    for (int i = 0; i < n; i++) root[i] = i;
    for (int i = 0; i < n; i++) {
        cin >> p[i].x >> p[i].y >> p[i].z;
        p[i].idx = i;
    }
    sort(p, p + n, cmpx); //x를 기준으로 오름차순 정렬
    for (int i = 0; i < n - 1; i++) edge.push_back({abs(p[i].x - p[i+1].x), p[i].idx, p[i+1].idx});
    sort(p, p + n, cmpy); //y를 기준으로 오름차순 정렬
    for (int i = 0; i < n - 1; i++) edge.push_back({abs(p[i].y - p[i+1].y), p[i].idx, p[i+1].idx});
    sort(p, p + n, cmpz); //z를 기준으로 오름차순 정렬
    for (int i = 0; i < n - 1; i++) edge.push_back({abs(p[i].z - p[i+1].z), p[i].idx, p[i+1].idx});
    
    sort(edge.begin(), edge.end());
    for (auto it : edge) {
        tie(d, a, b) = it;
        if (_find(a) == _find(b)) continue; //사이클 생성
        _union(a, b);
        ret += d;
    }
    cout << ret << '\n';

    return 0;
}

//프림 알고리즘
//메모리: 19460KB, 시간: 168ms
/*
#include <bits/stdc++.h>
using namespace std;

int n, x, y, z, d, p;
bool visited[100000];
long long ret;
vector<pair<int, int>> px, py, pz;
vector<pair<int, int>> adj[100000];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void addAdj(vector<pair<int, int>>& v, int i) {
    int idx = v[i].second, idx2 = v[i+1].second, dist = abs(v[i].first - v[i+1].first);
    adj[idx].push_back({idx2, dist}); adj[idx2].push_back({idx, dist});
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x >> y >> z;
        px.push_back({x, i}); py.push_back({y, i}); pz.push_back({z, i});
    }
    sort(px.begin(), px.end()); sort(py.begin(), py.end()); sort(pz.begin(), pz.end());
    for (int i = 0; i < n - 1; i++) {
        addAdj(px, i); addAdj(py, i); addAdj(pz, i);
    }
    pq.push({0, 0});
    while (pq.size()) {
        tie(d, p) = pq.top(); pq.pop();
        if (visited[p]) continue;
        visited[p] = 1; ret += d;
        for (auto it : adj[p]) {
            if (visited[it.first]) continue;
            pq.push({it.second, it.first});
        }
    }
    cout << ret << '\n';

    return 0;
}
*/