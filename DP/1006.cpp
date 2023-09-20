#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;

int t, n, w, enemy[20001], dp[20001][2];
bool visited[20001];

int go(int idx, bool cir, vector<int> adj[]) {
    if (cir && idx == n || idx > n) return 0;
    if (visited[idx]) return go(idx + 1, cir, adj);
    int& ret = dp[idx][cir];
    if (ret == MAX) {
        visited[idx] = 1;
        ret = min(ret, go(idx + 1, cir, adj) + 1);
        for (int next : adj[idx]) {
            if (visited[next] || enemy[idx] + enemy[next] > w) continue;
            visited[next] = 1;
            ret = min(ret, go(idx + 1, cir, adj) + 1);
            visited[next] = 0;
        }
        visited[idx] = 0;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        fill(&dp[0][0], &dp[0][0] + 20001*2, MAX);
        memset(visited, 0, sizeof(visited));
        vector<int> adj[20001];
        cin >> n >> w;
        for (int i = 1; i <= 2*n; i++) cin >> enemy[i];
        for (int i = 1; i <= 2*n; i++) {
            adj[i].push_back(i % n == 0 ? i+1-n : i+1);
            //adj[i].push_back(i % n == 1 ? i-1+n : i-1);
            if (i > n) adj[i].push_back(i-n);
        }
        cout << min(go(1, 0, adj), go(2, 1, adj) + 1) << '\n';
    }
    return 0;
}