#include <bits/stdc++.h>
using namespace std;

int f, s, g, u, d, visited[1000001];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> f >> s >> g >> u >> d;
    int dir[] = {u, -d};
    q.push(s); visited[s] = 1;
    while (q.size()) {
        s = q.front(); q.pop();
        for (int i = 0; i < 2; i++) {
            int next = s + dir[i];
            if (next < 1 || next > f || visited[next]) continue;
            q.push(next); visited[next] = visited[s] + 1;
        }
    }
    if (visited[g] == 0) cout << "use the stairs\n";
    else cout << visited[g] - 1 << '\n';
    return 0;
}