//메모리: 18596KB, 시간: 356ms
#include <bits/stdc++.h>
#define MOD 1000000007
typedef long long ll;
using namespace std;

int n, m, k, a, b, c, tmp;

void update(int node, int s, int e, int idx, int num, vector<ll>& tree) {
    if (idx < s || idx > e) return;
    //리프 노드에서 값 직접 변경 → 이전 값을 다른 배열에 저장할 필요X (diff 값으로 변경하는 경우)
    if (s == e) { tree[node] = num; return; }
    update(node * 2, s, (s + e) / 2, idx, num, tree);
    update(node * 2 + 1, (s + e) / 2 + 1, e, idx, num, tree);
    tree[node] = tree[node * 2] * tree[node * 2 + 1] % MOD;
}

ll multiply(int node, int s, int e, int l, int r, vector<ll>& tree) {
    if (l > e || r < s) return 1;
    if (l <= s && e <= r) return tree[node];
    return multiply(node * 2, s, (s + e) / 2, l, r, tree) * multiply(node * 2 + 1, (s + e) / 2 + 1, e, l, r, tree) % MOD;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    vector<ll> tree(pow(2, ceil(log2(n)) + 1), 1);
    for (int i = 0; i < n; i++) {
        cin >> tmp; update(1, 0, n - 1, i, tmp, tree);
    }
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) update(1, 0, n - 1, b - 1, c, tree);
        else cout << multiply(1, 0, n - 1, b - 1, c - 1, tree) << '\n';
    }
    return 0;
}