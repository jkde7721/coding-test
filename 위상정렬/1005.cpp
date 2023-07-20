//위상정렬 풀이
//메모리: 3356KB, 시간: 188ms
#include <bits/stdc++.h>
using namespace std;

//ret 배열이 DP의 메모이제이션 역할
int t, n, k, d[1001], x, y, w, indeg[1001], ret[1001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        vector<int> adj[1001], adj2[1001]; queue<int> q;
        memset(indeg, 0, sizeof(indeg));
        memset(ret, 0, sizeof(ret));
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> d[i];
        for (int i = 0; i < k; i++) {
            cin >> x >> y; indeg[y]++;
            adj[x].push_back(y);
            adj2[y].push_back(x);
        }
        cin >> w;
        for (int i = 1; i <= n; i++) {
            if (!indeg[i]) q.push(i);
        }
        while (q.size()) {
            x = q.front(); q.pop();
            for (int i : adj2[x]) { //i → x
                ret[x] = max(ret[x], ret[i]);
            }
            ret[x] += d[x];
            for (int i : adj[x]) { //x → i
                indeg[i]--;
                if (!indeg[i]) q.push(i);
            }
        }
        cout << ret[w] << '\n';
    }

    return 0;
}

/*
//DP 풀이
//메모리: 2820KB, 시간: 208ms
#include <bits/stdc++.h>
using namespace std;

int t, n, k, d[1001], x, y, w, dp[1001];

int dfs(int cur, vector<int> adj[]) {
    int& ret = dp[cur];
    if (ret == -1) {
        ret = d[cur];
        for (int i : adj[cur]) { //i → cur
            ret = max(ret, dfs(i, adj) + d[cur]);
        }
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        vector<int> adj[1001];
        memset(dp, -1, sizeof(dp));
        cin >> n >> k;
        for (int i = 1; i <= n; i++) cin >> d[i];
        for (int i = 0; i < k; i++) {
            cin >> x >> y;
            adj[y].push_back(x); //방향 반전
        }
        cin >> w;
        cout << dfs(w, adj) << '\n';
    }
    return 0;
}
*/