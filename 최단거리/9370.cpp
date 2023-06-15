/*
풀이 방법 3가지
1. g로부터 시작/도착점까지의 최단 거리 + g-h 거리 + h로부터 도착/시작점까지의 최단 거리 = 최단 거리와 같으면 출력 (양방향 간선이기 때문에 가능) → 다익스트라 3번
아래 두 방법에 대한 concern: 최단 경로가 여러 개 존재할 때, g-h 간선을 우선적으로 지나도록 해야 함 
→ 모든 간선 가중치 2배하여 짝수로 만듦, 이후 g-h 간선은 -1하여 홀수로 만듦 (g-h 간선 가중치값은 고유)
2. 기존 최소힙에 g-h 간선 지났는지 여부 상태를 저장, pop되었을 때 목적지 후보이면서 g-h 간선 지났으면 결과 벡터에 저장 → 다익스트라 1번 
3. 최단 거리 값이 홀수이면 g-h 간선을 지난 것 → 다익스트라 1번
*/

//메모리: 3464KB, 시간: 40ms
//1번 방법
/*
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int T, n, m, t, s, g, h, a, b, d, x, gh, dist[2001], dist2[2001], dist3[2001];
vector<int> dest;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

void dijkstra(int start, vector<pair<int, int>> adj[2001], int dist[2001]) {
    fill(dist, dist + 2001, INF);
    dist[start] = 0; pq.push({0, start});
    while (pq.size()) {
        tie(d, a) = pq.top(); pq.pop();
        if (dist[a] < d) continue;
        for (auto it : adj[a]) {
            if (dist[it.first] > d + it.second) {
                dist[it.first] = d + it.second;
                pq.push({dist[it.first], it.first});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        vector<pair<int, int>> adj[2001];
        dest.clear();
        cin >> n >> m >> t >> s >> g >> h;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d;
            if (a == g && b == h || a == h && b == g) gh = d;
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }
        for (int i = 0; i < t; i++) { cin >> x; dest.push_back(x); }

        dijkstra(s, adj, dist);
        dijkstra(g, adj, dist2);
        dijkstra(h, adj, dist3);
        sort(dest.begin(), dest.end());
        for (int i : dest) {
            if (dist[i] == (dist2[s] + gh + dist3[i]) || dist[i] == (dist2[i] + gh + dist3[s])) cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}
*/

//메모리: 3560KB, 시간: 32ms
//2번 방법
/*
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int T, n, m, t, s, g, h, a, b, d, x, dist[2001];
bool passGH, dest[2001];
vector<int> ret;
priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        vector<pair<int, int>> adj[2001]; ret.clear();
        fill(dist, dist + 2001, INF);
        memset(dest, 0, sizeof(dest));
        cin >> n >> m >> t >> s >> g >> h;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d; d *= 2;
            if (a == g && b == h || a == h && b == g) d--; //g-h 간선인 경우
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }
        for (int i = 0; i < t; i++) { cin >> x; dest[x] = 1; }

        dist[s] = 0; pq.push({0, s, 0});
        while (pq.size()) {
            tie(d, a, passGH) = pq.top(); pq.pop();
            if (dist[a] < d) continue;
            if (dest[a] && passGH) ret.push_back(a);
            for (auto it : adj[a]) {
                if (dist[it.first] > d + it.second) {
                    dist[it.first] = d + it.second;
                    pq.push({dist[it.first], it.first, (passGH ? 1 : (a == g && it.first == h || a == h && it.first == g))});
                }
            }
        }
        sort(ret.begin(), ret.end());
        for (int i : ret) cout << i << ' ';
        cout << '\n';
    }

    return 0;
}
*/

//메모리: 3344KB, 시간: 32ms
//3번 방법 (good idea!!!)
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int T, n, m, t, s, g, h, a, b, d, x, dist[2001];
vector<int> dest;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        vector<pair<int, int>> adj[2001]; 
        dest.clear();
        fill(dist, dist + 2001, INF);
        cin >> n >> m >> t >> s >> g >> h;
        for (int i = 0; i < m; i++) {
            cin >> a >> b >> d; d *= 2;
            if (a == g && b == h || a == h && b == g) d--;
            adj[a].push_back({b, d});
            adj[b].push_back({a, d});
        }
        for (int i = 0; i < t; i++) { cin >> x; dest.push_back(x); }

        dist[s] = 0; pq.push({0, s});
        while (pq.size()) {
            tie(d, a) = pq.top(); pq.pop();
            if (dist[a] < d) continue;
            for (auto it : adj[a]) {
                if (dist[it.first] > d + it.second) {
                    dist[it.first] = d + it.second;
                    pq.push({dist[it.first], it.first});
                }
            }
        }
        sort(dest.begin(), dest.end());
        for (int i : dest) {
            if (dist[i] % 2) cout << i << ' ';
        }
        cout << '\n';
    }

    return 0;
}