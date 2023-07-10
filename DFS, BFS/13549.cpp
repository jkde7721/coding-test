//BFS 풀이
//메모리: 2676KB, 시간: 0ms
/*
#include <bits/stdc++.h>
using namespace std;

const int d[] = {2, 1, -1};
int n, k, visited[100001], pos, t, npos, nt, ret = 1e9;
queue<pair<int, int>> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    visited[n] = 1; q.push({n, 1});
    while (q.size()) {
        tie(pos, t) = q.front(); q.pop();
        if (t > visited[pos]) continue;
        if (pos >= k) {
            if (pos > k) t += pos - k;
            ret = min(ret, t); continue;
        }
        if (t >= ret) continue;
        for (int i = 0; i < 3; i++) {
            npos = (i == 0 ? pos * d[i] : pos + d[i]);
            nt = (i == 0 ? 0 : 1);
            if (npos < 0 || npos > 100000) continue;
            if (visited[npos] && visited[npos] <= t + nt) continue;
            q.push({npos, t + nt}); visited[npos] = t + nt;
        }
    }
    cout << ret - 1 << '\n';
    
    return 0;
}
*/

//다익스트라 풀이 (one source → 특정 위치까지의 최단 거리 + 가중치가 다른 간선 + 우선순위 큐를 이용하여 최단 거리의 위치에서부터 그리디하게 이동)
//메모리: 2924KB, 시간: 4ms
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

//가중치가 0 또는 1로 해당 위치에 처음 도착했을 때 걸린 시간이 최단 시간 → visited 배열로 방문 여부만 관리해줘도 됨
const int d[] = {2, 1, -1};
int n, k, visited[100001], pos, t, npos, nt;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k; fill(visited, visited + 100001, INF);
    visited[n] = 0; pq.push({0, n});
    while (pq.size()) {
        tie(t, pos) = pq.top(); pq.pop();
        if (pos == k) break;
        if (t > visited[pos]) continue;
        for (int i = 0; i < 3; i++) {
            npos = (i == 0 ? pos * d[i] : pos + d[i]);
            nt = (i == 0 ? 0 : 1);
            if (npos < 0 || npos > 100000) continue;
            if (npos > k) { nt += npos - k; npos = k; }
            if (visited[npos] > t + nt) {
                pq.push({t + nt, npos}); visited[npos] = t + nt;
            }
        }
    }
    cout << t << '\n';
    return 0;
}