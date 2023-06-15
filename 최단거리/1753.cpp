/*
���ͽ�Ʈ�� �˰���: ����ġ�� �ٸ� �׷������� �� ������ �����ϴ� ���� ª�� ��θ� ã�� �ִ� �Ÿ� �˰���
(�ϳ��� �������� �ٸ� ��� ���������� �ִ� �Ÿ��� ���ϴ� �˰���, Single Source Shortest Path)
����ġ�� ����� ��쿡�� ��� ����
�� �ð����⵵ O(ElogV)
*/
#include <iostream>
#include <queue>
#include <tuple>
#define INF 987654321
using namespace std;

int V, E, K, u, v, w, value;
vector<pair<int, int>> graph[20001];
int dist[20001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //�ּ��� 

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