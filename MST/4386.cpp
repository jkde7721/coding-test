//❗double형 연산 조심
#include <bits/stdc++.h>
using namespace std;

int n, a, b, root[100];
double x, y, dist, ret;
pair<double, double> pos[100];
vector<tuple<double, int, int>> edge;

double getDist(int a, int b) {
    return sqrt(pow(pos[a].first-pos[b].first, 2) + pow(pos[a].second-pos[b].second, 2));
}

int _find(int node) {
    if (root[node] == node) return node;
    return root[node] = _find(root[node]);
}

void _union(int a, int b) {
    root[_find(a)] = _find(b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) root[i] = i;
    for (int i = 0; i < n; i++) {
        cin >> x >> y; pos[i] = {x, y};
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) edge.push_back({getDist(i, j), i, j});
    }
    sort(edge.begin(), edge.end());
    for (auto& it : edge) {
        tie(dist, a, b) = it;
        if (_find(a) == _find(b)) continue;
        ret += dist; _union(a, b);
    }
    cout << fixed; cout.precision(2);
    cout << ret << '\n';
    return 0;
}