//메모리: 12000KB, 시간: 60ms
#include <bits/stdc++.h>
#define MAX 15
using namespace std;

int n, m, a, b, d, depth[40001], ret;
pair<int, int> sparse[40001][MAX + 1];
vector<pair<int, int>> adj[40001];

void makeSparse(int node, int dep) {
    depth[node] = dep;
    for (int i = 1; pow(2, i) < dep; i++) {
        sparse[node][i].first = sparse[sparse[node][i-1].first][i-1].first;
        sparse[node][i].second = sparse[node][i-1].second + sparse[sparse[node][i-1].first][i-1].second;
    }
    for (auto it : adj[node]) {
        if (depth[it.first]) continue;
        sparse[it.first][0] = {node, it.second};
        makeSparse(it.first, dep + 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b >> d;
        adj[a].push_back({b, d});
        adj[b].push_back({a, d});
    }
    //실제 루트 노드가 1이 아니더라도 두 노드 사이의 거리를 구하는 문제이기 때문에 루트 노드를 1로 가정해도 상관없음
    //만약 실제 루트 노드가 1이 아닌데 두 노드의 LCA를 구하는 문제라면 WA
    makeSparse(1, 1);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b; ret = 0;
        int &node = (depth[a] > depth[b] ? a : b), diff = abs(depth[a] - depth[b]);
        for (int j = 0; diff; j++) {
            if (diff % 2) {
                ret += sparse[node][j].second;
                node = sparse[node][j].first;
            }
            diff /= 2;
        }
        if (a == b) { cout << ret << '\n'; continue; }
        for (int j = MAX; j >= 0; j--) {
            if (sparse[a][j].first != sparse[b][j].first) {
                ret += sparse[a][j].second + sparse[b][j].second;
                a = sparse[a][j].first;
                b = sparse[b][j].first;
            }
        }
        cout << (ret + sparse[a][0].second + sparse[b][0].second) << '\n';
    }

    return 0;
}