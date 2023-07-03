//�޸�: 10680KB, �ð�: 80ms
//������ �ִܰŸ��� �ش� ������ ¦��/Ȧ������ ������ ����ϴ� 2���� ���� ������ ���
//Ȧ�� ����ġ�� ���� ������ 2 �������� �Ҽ��� �߻� �� ���� �Ÿ��� x2 ó���Ͽ� ���(�ܼ� ��� �񱳸� �ϸ� �Ǳ� ����)
//but ���� �ִܰŸ��� double������ �����ص� AC
#include <bits/stdc++.h>
#define INF 987654321
using namespace std;

int n, m, a, b, d, wd, fDist[4001], wDist[2][4001], ret;
bool fast;
vector<pair<int, int>> adj[4001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<tuple<int, int, bool>, vector<tuple<int, int, bool>>, greater<tuple<int, int, bool>>> pq2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> d;
        adj[a].push_back({b, d * 2});
        adj[b].push_back({a, d * 2});
    }

    fill(fDist, fDist + 4001, INF);
    fDist[1] = 0; pq.push({0, 1});
    while (pq.size()) {
        tie(d, a) = pq.top(); pq.pop();
        if (fDist[a] < d) continue;
        for (auto it : adj[a]) {
            if (fDist[it.first] > d + it.second) {
                fDist[it.first] = d + it.second;
                pq.push({fDist[it.first], it.first});
            }
        }
    }

    fill(&wDist[0][0], &wDist[0][0] + 2*4001, INF);
    wDist[0][1] = 0; pq2.push({0, 1, 0}); //slow�� 1�� ��� go
    while (pq2.size()) {
        tie(d, a, fast) = pq2.top(); pq2.pop();
        if (wDist[fast][a] < d) continue;
        fast ^= 1; //slow �� fast, fast �� slow 
        for (auto it : adj[a]) {
            wd = (fast ? it.second / 2 : it.second * 2);
            if (wDist[fast][it.first] > d + wd) {
                wDist[fast][it.first] = d + wd;
                pq2.push({wDist[fast][it.first], it.first, fast});
            }
        }
    }

    for (int i = 2; i <= n; i++) {
        if (fDist[i] < wDist[0][i] && fDist[i] < wDist[1][i]) ret++;
    }
    cout << ret << '\n';
    return 0;
}