//DFS 풀이
//메모리: 2152KB, 시간: 0ms
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

//한번에 갈 수 있는 최대 거리 = 20 * 50m = 1000m
int t, n;
bool visited[102], arrival;
pair<int, int> pos[102]; //0은 집, 1~n은 편의점, n+1은 페스티벌 좌표

int getDist(int i, int j) {
    return abs(pos[i].first-pos[j].first) + abs(pos[i].second-pos[j].second);
}

void dfs(int node, vector<int> adj[]) {
    if (node == n + 1) { arrival = true; return; }
    visited[node] = 1;
    for (int i : adj[node]) {
        if (!visited[i]) dfs(i, adj);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        memset(visited, 0, sizeof(visited));
        vector<int> adj[102]; arrival = false;
        cin >> n;
        for (int i = 0; i < n + 2; i++) cin >> pos[i].first >> pos[i].second;
        //유효한 간선 생성
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                if (i != j && getDist(i, j) <= MAX) adj[i].push_back(j);
            }
        }
        dfs(0, adj);
        cout << (arrival ? "happy" : "sad") << '\n';
    }
    return 0;
}

//플로이드 워셜 알고리즘 풀이
//메모리: 2032KB, 시간: 12ms
/*
#include <bits/stdc++.h>
#define MAX 1000
using namespace std;

int t, n;
bool go[102][102];
pair<int, int> pos[102];

int getDist(int i, int j) {
    return abs(pos[i].first-pos[j].first) + abs(pos[i].second-pos[j].second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        memset(go, 0, sizeof(go));
        cin >> n;
        for (int i = 0; i < n + 2; i++) cin >> pos[i].first >> pos[i].second;
        for (int i = 0; i < n + 2; i++) {
            for (int j = 0; j < n + 2; j++) {
                if (i != j && getDist(i, j) <= MAX) go[i][j] = 1; //노드 i → j 간선 유효
            }
        }
        for (int k = 0; k < n + 2; k++) {
            for (int i = 0; i < n + 2; i++) {
                for (int j = 0; j < n + 2; j++) {
                    if (go[i][k] && go[k][j]) go[i][j] = go[j][i] = 1; //i → k, k → j이면 i ↔️ j 가능
                }
            }
        }
        cout << (go[0][n+1] ? "happy" : "sad") << '\n';
    }
    return 0;
}
*/