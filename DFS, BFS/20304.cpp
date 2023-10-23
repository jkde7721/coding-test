//메모리: 8764KB, 시간: 84ms
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

//안전 거리가 0인 비밀번호부터 거리를 1씩 늘려가며 퍼져나가는 느낌...
int n, m, p, cur, nxt, dist[1000001], mx;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(dist, dist + 1000001, INF);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> p; dist[p] = 0; q.push(p); //시도한 비밀번호와 동일한 숫자는 안전 거리가 0
    }
    while (q.size()) {
        cur = q.front(); q.pop();
        for (int i = 0; i < 20; i++) {
            nxt = (1 << i) ^ cur; //cur와의 안전 거리가 1인 비밀번호 (cur의 1 bit만 반전, 1과 XOR 연산 시 0 → 1, 1 → 0)
            if (nxt <= n && dist[nxt] == INF) {
                dist[nxt] = dist[cur] + 1; q.push(nxt);
                mx = max(mx, dist[nxt]);
            }
        }
    }
    cout << mx << '\n';
    return 0;
}