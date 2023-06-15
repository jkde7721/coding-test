/*
플로이드 워셜 알고리즘: 모든 쌍에 대한 최단 거리를 구하는 알고리즘
→ 시간복잡도 O(V^3), 따라서 N의 크기가 작을 때 사용 가능, 음수 가중치 가능
*/
#include <iostream>
#define INF 987654321
using namespace std;

int n, m, a, b, c, dist[101][101];

int main() {
     ios_base::sync_with_stdio(false);
     cin.tie(NULL); cout.tie(NULL);
     fill(&dist[0][0], &dist[0][0] + 101*101, INF);
     cin >> n >> m;
     for (int i = 0; i < m; i++) {
          cin >> a >> b >> c;
          if (dist[a][b] > c) dist[a][b] = c;
     }
     for (int i = 1; i <= n; i++) dist[i][i] = 0;
     //k번 노드를 중간 노드로 선정 (1~n번 노드까지)
     for (int k = 1; k <= n; k++) {
          for (int i = 1; i <= n; i++) {
               for (int j = 1; j <= n; j++) {
                    if (dist[i][j] > dist[i][k] + dist[k][j]) {
                         dist[i][j] = dist[i][k] + dist[k][j];
                    }
               }
          }
     }
     for (int i = 1; i <= n; i++) {
          for (int j = 1; j <= n; j++) {
               cout << (dist[i][j] == INF ? 0 : dist[i][j]) << ' ';
          }
          cout << '\n';
     }

     return 0;
}