/*
Ǯ�� ��� 3����
1. g�κ��� ����/������������ �ִ� �Ÿ� + g-h �Ÿ� + h�κ��� ����/������������ �ִ� �Ÿ� = �ִ� �Ÿ��� ������ ��� (����� �����̱� ������ ����) �� ���ͽ�Ʈ�� 3��
�Ʒ� �� ����� ���� concern: �ִ� ��ΰ� ���� �� ������ ��, g-h ������ �켱������ �������� �ؾ� �� 
�� ��� ���� ����ġ 2���Ͽ� ¦���� ����, ���� g-h ������ -1�Ͽ� Ȧ���� ���� (g-h ���� ����ġ���� ����)
2. ���� �ּ����� g-h ���� �������� ���� ���¸� ����, pop�Ǿ��� �� ������ �ĺ��̸鼭 g-h ���� �������� ��� ���Ϳ� ���� �� ���ͽ�Ʈ�� 1�� 
3. �ִ� �Ÿ� ���� Ȧ���̸� g-h ������ ���� �� �� ���ͽ�Ʈ�� 1��
*/

//�޸�: 3464KB, �ð�: 40ms
//1�� ���
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

//�޸�: 3560KB, �ð�: 32ms
//2�� ���
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
            if (a == g && b == h || a == h && b == g) d--; //g-h ������ ���
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

//�޸�: 3344KB, �ð�: 32ms
//3�� ��� (good idea!!!)
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