//음수 사이클 찾는 문제 → 모든 지점이 서로 연결되어 있는 것이 아니기 때문에 임의의 지점 1로부터 출발하면 음수 사이클이 있다 하더라도 음수 사이클에 도달하지 못할 수 있음 
//1. 모든 지점의 dist 배열을 0으로 초기화하면 모든 지점에서 출발하는 것이 됨 (실제 최단 거리를 구하는 것이 아닌 음수 사이클 존재 여부만 판단하면 되기 때문에)
//2. 가중치 0으로 모든 지점과 연결된 새로운 임의의 지점 생성하여 이 임의의 지점에서 출발
//모든 지점에 대해서 벨만-포드 수행 시 500 * 500 * 2500으로 시간 초과

//1번 풀이
/*
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, w, s, e, t, tc;

bool bellman(vector<pair<int, int>> adj[]) {
    int dist[501]; memset(dist, 0, sizeof(dist));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto it : adj[j]) {
                if (dist[it.first] > dist[j] + it.second) {
                    dist[it.first] = dist[j] + it.second;
                    if (i == n) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;
    while (tc--) {
        vector<pair<int, int>> adj[501];
        cin >> n >> m >> w;
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            adj[s].push_back({e, t}); adj[e].push_back({s, t});
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            adj[s].push_back({e, -t});
        }
        if (bellman(adj)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
*/

//2번 풀이
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, w, s, e, t, tc;

bool bellman(vector<pair<int, int>> adj[]) {
    int dist[502];
    fill(dist, dist + 502, INF); dist[n+1] = 0;
    for (int i = 1; i <= n+1; i++) {
        for (int j = 1; j <= n+1; j++) {
            for (auto it : adj[j]) {
                if (dist[j] != INF && dist[it.first] > dist[j] + it.second) {
                    dist[it.first] = dist[j] + it.second;
                    if (i == n+1) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;
    while (tc--) {
        vector<pair<int, int>> adj[502];
        cin >> n >> m >> w;
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            adj[s].push_back({e, t}); adj[e].push_back({s, t});
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            adj[s].push_back({e, -t});
        }
        //가중치 0으로 모든 지점과 연결된 임의의 n+1 지점 추가 (다른 지점으로 가기만 하면 됨)
        for (int i = 1; i <= n; i++) adj[n+1].push_back({i, 0});
        if (bellman(adj)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}

//간단하게 bellman 함수 내 dist[j] != INF 조건문을 없애도 됨 (단순히 음수 사이클만 발견하면 되기 때문)
/*
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, w, s, e, t, tc;

bool bellman(vector<pair<int, int>> adj[]) {
    int dist[501];
    fill(dist, dist + 501, INF); dist[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            for (auto it : adj[j]) {
                if (dist[it.first] > dist[j] + it.second) {
                    dist[it.first] = dist[j] + it.second;
                    if (i == n) return true;
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> tc;
    while (tc--) {
        vector<pair<int, int>> adj[501];
        cin >> n >> m >> w;
        for (int i = 0; i < m; i++) {
            cin >> s >> e >> t;
            adj[s].push_back({e, t}); adj[e].push_back({s, t});
        }
        for (int i = 0; i < w; i++) {
            cin >> s >> e >> t;
            adj[s].push_back({e, -t});
        }
        if (bellman(adj)) cout << "YES\n";
        else cout << "NO\n";
    }

    return 0;
}
*/