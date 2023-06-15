/*
벨만포드 알고리즘: 음수 가중치가 있는 그래프에서 사용하는 최단 거리 알고리즘
최단 거리의 최대 거리 = V - 1, 따라서 V번째 반복에서도 dist 배열이 업데이트된다면 음수 가중치 사이클이 존재
→ 시간복잡도 O(VE)
*/
#include <iostream>
#include <vector>
#include <tuple>
#define INF 1e18
using namespace std;
typedef long long ll;

int n, m, u, v, w;
ll dist[501];
bool updated;
vector<pair<int, int>> graph[501];

int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL); cout.tie(NULL);
     fill(dist, dist + 501, INF);
     cin >> n >> m;
     for (int i = 0 ; i < m; i++) {
          cin >> u >> v >> w;
          graph[u].push_back({v, w});
     }
     dist[1] = 0;
     for (int i = 0; i < n; i++) {
          updated = false;
          //2중 for문 → 모든 Edge 탐색
          for (int j = 1; j <= n; j++) {
               for (auto it : graph[j]) {
                    tie(v, w) = it;
                    if (dist[j] != INF && dist[v] > dist[j] + w) {
                         dist[v] = dist[j] + w;
                         updated = true;
                    }
               }
          }
          if (!updated) break;
     }
     if (updated) { cout << "-1\n"; return 0; }
     for (int i = 2; i <= n; i++) {
          cout << (dist[i] == INF ? -1 : dist[i]) << '\n';
     }
     return 0;
}