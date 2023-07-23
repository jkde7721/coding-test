//메모리: 5928KB, 시간: 84ms
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, a, b, tmp, tree[1000000];

//해당 node의 범위는 s ~ e
void update(int node, int s, int e, int idx, int num) {
    if (idx < s || idx > e) return;
    tree[node] = min(tree[node], num);
    if (s != e) {
        update(node * 2, s, (s + e) / 2, idx, num);
        update(node * 2 + 1, (s + e) / 2 + 1, e, idx, num);
    }
}

int getMin(int node, int s, int e, int l, int r) {
    if (l > e || r < s) return INF;
    if (l <= s && e <= r) return tree[node];
    return min(getMin(node * 2, s, (s + e) / 2, l, r), getMin(node * 2 + 1, (s + e) / 2 + 1, e, l, r));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(tree, tree + 1000000, INF);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp; update(1, 0, n - 1, i, tmp);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        cout << getMin(1, 0, n - 1, a - 1, b - 1) << '\n';
    }
    return 0;
}