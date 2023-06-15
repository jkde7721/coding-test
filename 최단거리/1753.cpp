/*
다익스트라 알고리즘: 가중치가 다른 그래프에서 두 정점을 연결하는 가장 짧은 경로를 찾는 최단 거리 알고리즘
(하나의 정점에서 다른 모든 정점까지의 최단 거리를 구하는 알고리즘, Single Source Shortest Path)
가중치가 양수인 경우에만 사용 가능
→ 시간복잡도 O(ElogV)
*/
#include <iostream>
#include <queue>
#include <tuple>
#define INF 987654321
using namespace std;

int V, E, K, u, v, w, value;
vector<pair<int, int>> graph[20001];
int dist[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //최소힙 

int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL); cout.tie(NULL);
     cin >> V >> E >> K;
     while (E--) {
          cin >> u >> v >> w;
          graph[u].push_back({v, w});
     }

     fill(dist, dist + 20001, INF);
     dist[K] = 0; pq.push({0, K});
     while (pq.size()) {
          tie(value, u) = pq.top(); pq.pop();
          if (value > dist[u]) continue;
          for (auto it : graph[u]) {
               tie(v, w) = it;
               if (dist[v] > value + w) {
                    dist[v] = value + w;
                    pq.push({dist[v], v});
               }
          }
     }
     for (int i = 1; i <= V; i++) {
          if (dist[i] == INF) cout << "INF\n";
          else cout << dist[i] << '\n';
     }

     return 0;
}