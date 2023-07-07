#include <bits/stdc++.h>
using namespace std;

int n, u, v, d, ret;
vector<pair<int, int>> adj[10001];

int dfs(int node) {
    int mx = 0, mx2 = 0, tmp; //mx는 제일 긴 하위 경로, mx2는 그 다음으로 긴 하위 경로
    for (auto it : adj[node]) {
        tmp = it.second + dfs(it.first);
        if (tmp > mx) { mx2 = mx; mx = tmp; }
        else if (tmp > mx2) mx2 = tmp;
    }
    ret = max(ret, mx + mx2);
    return mx;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> u >> v >> d;
        adj[u].push_back({v, d});
    }
    dfs(1);
    cout << ret << '\n';

    return 0;
}