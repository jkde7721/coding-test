#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, a, b, visited[101];
vector<int> adj[101];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> a >> b >> m;
    for (int i = 0; i < m; i++) {
        cin >> x >> y;
        //양방향 그래프 생성
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    q.push(a); visited[a] = 1;
    while (q.size()) {
        x = q.front(); q.pop();
        for (int i : adj[x]) {
            if (!visited[i]) {
                q.push(i); visited[i] = visited[x] + 1;
            }
        }
    }
    //a노드와 b노드가 관계가 전혀 없으면 visited[b]는 0 → 아래 연산 결과는 -1
    cout << visited[b] - visited[a] << '\n';
    return 0;
}