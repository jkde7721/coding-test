//LCA 알고리즘 O(NlogN)
//메모리: 11288KB, 시간: 64ms
#include <bits/stdc++.h>
#define MAX 15
using namespace std;

int n, m, a, b, sparse[50001][MAX + 1], depth[50001];
vector<int> adj[50001];

void makeSparse(int node, int dep, int pre) {
    depth[node] = dep; sparse[node][0] = pre;
    for (int i = 1; pow(2, i) < dep; i++) {
        sparse[node][i] = sparse[sparse[node][i - 1]][i - 1];
    }
    for (int i : adj[node]) {
        if (depth[i]) continue;
        makeSparse(i, dep + 1, node); 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    makeSparse(1, 1, 0);
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        int &node = (depth[a] > depth[b] ? a : b), diff = abs(depth[a] - depth[b]);
        for (int j = 0; diff; j++) {
            if (diff % 2) node = sparse[node][j];
            diff /= 2; //right shift와 동일
        }
        //노드 a와 노드 b의 깊이 동일
        if (a == b) { cout << a << '\n'; continue; }
        for (int j = MAX; j >= 0; j--) {
            if (sparse[a][j] != sparse[b][j]) {
                a = sparse[a][j];
                b = sparse[b][j];
            }
        }
        cout << sparse[a][0] << '\n';
    }

    return 0;
}