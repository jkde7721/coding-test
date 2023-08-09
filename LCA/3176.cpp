//메모리: 32640KB, 시간: 212ms
//노드 간 유일한 경로 구하는 방법: DFS-O(N), LCA-O(logN)
#include <bits/stdc++.h>
#define MAX 16
using namespace std;

typedef struct path {
    int pn, mn, mx; //부모 노드 번호, (현재 노드~해당 부모 노드)까지의 경로 중 가장 짧은/긴 경로
} Path;

int n, k, a, b, c, d, e, depth[100001], mn, mx;
Path sparse[100001][MAX + 1];
vector<pair<int, int>> adj[100001];

void makeSparse(int node, int dep) {
    depth[node] = dep;
    for (int i = 1; pow(2, i) < dep; i++) {
        int prepn = sparse[node][i-1].pn;
        sparse[node][i].pn = sparse[prepn][i-1].pn;
        //min(현재 노드~현재 노드의 4번째 부모 노드까지의 경로 중 가장 짧은 경로, 현재 노드의 4번째 부모 노드~해당 4번째 부모 노드의 다시 4번째 부모 노드까지의 경로 중 가장 짧은 경로)
        sparse[node][i].mn = min(sparse[node][i-1].mn, sparse[prepn][i-1].mn);
        sparse[node][i].mx = max(sparse[node][i-1].mx, sparse[prepn][i-1].mx);
    }
    for (auto it : adj[node]) {
        if (!depth[it.first]) {
            sparse[it.first][0] = {node, it.second, it.second};
            makeSparse(it.first, dep + 1);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    makeSparse(1, 1); //임의의 루트 노드 1
    cin >> k;
    for (int i = 0; i < k; i++) {
        cin >> d >> e; mn = 1000000; mx = 0;
        int &node = (depth[d] > depth[e] ? d : e), diff = abs(depth[d] - depth[e]);
        for (int j = 0; diff; j++) {
            if (diff % 2) {
                mn = min(mn, sparse[node][j].mn);
                mx = max(mx, sparse[node][j].mx);
                node = sparse[node][j].pn;
            }
            diff /= 2;
        }

        if (d != e) {
            for (int j = MAX; j >= 0; j--) {
                if (sparse[d][j].pn != sparse[e][j].pn) {
                    mn = min(mn, min(sparse[d][j].mn, sparse[e][j].mn));
                    mx = max(mx, max(sparse[d][j].mx, sparse[e][j].mx));
                    d = sparse[d][j].pn;
                    e = sparse[e][j].pn;
                }
            }
            mn = min(mn, min(sparse[d][0].mn, sparse[e][0].mn));
            mx = max(mx, max(sparse[d][0].mx, sparse[e][0].mx));
        }
        cout << mn << ' ' << mx << '\n';
    }
    return 0;
}