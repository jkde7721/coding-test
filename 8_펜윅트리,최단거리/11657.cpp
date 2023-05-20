/*
�������� �˰���: ���� ����ġ�� �ִ� �׷������� ����ϴ� �ִ� �Ÿ� �˰���
�ִ� �Ÿ��� �ִ� �Ÿ� = V - 1, ���� V��° �ݺ������� dist �迭�� ������Ʈ�ȴٸ� ���� ����ġ ����Ŭ�� ����
�� �ð����⵵ O(VE)
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
          //2�� for�� �� ��� Edge Ž��
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