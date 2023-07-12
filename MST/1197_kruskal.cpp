//Kruskal + Union-Find 알고리즘
//메모리: 4496KB, 시간: 36ms
#include <bits/stdc++.h>
using namespace std;

int v, e, a, b, c, root[10001], ret;
vector<tuple<int, int, int>> edge;

int _find(int node) {
    if (root[node] == node) return node;
    return root[node] = _find(root[node]); //경로 압축 중요
}

void _union(int a, int b) {
    int pa = _find(a), pb = _find(b);
    root[pa] = root[pb] = min(pa, pb); //합쳐지는 트리의 루트 노드를 합치는 트리의 루트 노드에 연결 
    //root[_find(a)] = _find(b); //일관성 없이 이렇게 해도 가능
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    for (int i = 1; i <= v; i++) root[i] = i;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        edge.push_back({c, a, b});
    }
    sort(edge.begin(), edge.end());
    for (auto it : edge) {
        tie(c, a, b) = it;
        if (_find(a) == _find(b)) continue; //해당 간선이 사이클 생성
        _union(a, b); //두 노드 연결
        ret += c;
    }
    cout << ret << '\n';

    return 0;
}