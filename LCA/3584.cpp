//O(NlogN) 알고리즘 풀이
//메모리: 4092KB, 시간: 16ms
/*
#include <bits/stdc++.h>
#define MAX 13 //2^13 = 8,192
using namespace std;

int t, n, a, b, depth[10001], sparse[10001][MAX + 1], root;
bool child[10001];

void init() {
    memset(depth, 0, sizeof(depth)); 
    memset(child, 0, sizeof(child));
    memset(sparse, 0, sizeof(sparse));
}

void makeSparse(int node, int dep, int pre, vector<int> adj[]) {
    depth[node] = dep; sparse[node][0] = pre;
    for (int i = 1; pow(2, i) < dep; i++) {
        sparse[node][i] = sparse[sparse[node][i - 1]][i - 1];
    }
    for (int i : adj[node]) makeSparse(i, dep + 1, node, adj);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        vector<int> adj[10001]; init();
        cin >> n;
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b; adj[a].push_back(b);
            child[b] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (!child[i]) { root = i; break; }
        }
        makeSparse(root, 1, 0, adj);
        
        cin >> a >> b;
        int &node = (depth[a] > depth[b] ? a : b), diff = abs(depth[a] - depth[b]);
        for (int i = 0; diff; i++) {
            if (diff % 2) node = sparse[node][i];
            diff /= 2;
        }
        if (a == b) { cout << a << '\n'; continue; }
        for (int i = MAX; i >= 0; i--) {
            if (sparse[a][i] != sparse[b][i]) {
                a = sparse[a][i];
                b = sparse[b][i];
            }
        }
        cout << sparse[a][0] << '\n';
    }
    
    return 0;
}
*/

//O(N^2) 알고리즘 풀이
//최소 공통 조상을 찾는 횟수가 1번이므로 실제로는 O(N) 알고리즘으로 동작
//메모리: 3004KB, 시간: 8ms
#include <bits/stdc++.h>
using namespace std;

int t, n, a, b, ret, root;
bool child[10001];

int dfs(int node, vector<int> adj[]) {
    int cnt = (node == a || node == b ? 1 : 0);
    for (int i : adj[node]) cnt += dfs(i, adj);
    if (cnt == 2 && ret == 0) ret = node;
    return cnt;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n; vector<int> adj[10001]; 
        memset(child, 0, sizeof(child)); ret = 0;
        for (int i = 0; i < n - 1; i++) {
            cin >> a >> b; adj[a].push_back(b);
            child[b] = 1;
        }
        for (int i = 1; i <= n; i++) {
            if (!child[i]) { root = i; break; }
        }
        cin >> a >> b; dfs(root, adj);
        cout << ret << '\n';
    }
    return 0;
}