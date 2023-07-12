//Prim 알고리즘
//다익스트라 구현과 비슷
//메모리: 6660KB, 시간: 48ms
#include <bits/stdc++.h>
using namespace std;

int v, e, a, b, c, ret;
bool visited[10001];
vector<pair<int, int>> adj[10001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }
    pq.push({0, 1}); //임의의 시작 노드
    while (pq.size()) {
        tie(c, b) = pq.top(); pq.pop(); //현재 MST에 인접한 최소 가중치의 간선 선택
        if (visited[b]) continue; //사이클 생성
        ret += c; visited[b] = 1;
        for (auto it : adj[b]) {
            if (visited[it.first]) continue;
            pq.push({it.second, it.first});
        }
    }
    cout << ret << '\n';

    return 0;
}