//메모리: 26412KB, 시간: 224ms
//동적 배열 + 구간합 → 세그먼트 트리 or 펜윅 트리 사용 
//세그먼트 트리 풀이
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
typedef long long ll;

ll n, m, k, a, b, c;

ll init(vector<ll>& num, vector<ll>& tree, int node, int s, int e) {
    if (s == e) tree[node] = num[s];
    else {
        tree[node] = init(num, tree, 2*node + 1, s, (s + e) / 2) +
                init(num, tree, 2*node + 2, (s + e) / 2 + 1, e);
    }
    return tree[node];
}

void update(vector<ll>& tree, int node, int idx, ll diff, int s, int e) {
    if (idx < s || idx > e) return;
    tree[node] += diff;
    if (s != e) {
        update(tree, 2*node+1, idx, diff, s, (s+e) / 2);
        update(tree, 2*node+2, idx, diff, (s+e) / 2 + 1, e);
    }
}

ll sum(vector<ll>& tree, int node, int l, int r, int s, int e) {
    if (r < s || l > e) return 0;
    if (l <= s && r >= e) return tree[node];
    return sum(tree, 2*node+1, l, r, s, (s+e)/2) + sum(tree, 2*node+2, l, r, (s+e)/2+1, e);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    vector<ll> num(n), tree(pow(2, ceil(log2(n)) + 1) - 1);
    for (int i = 0; i < n; i++) cin >> num[i];
    init(num, tree, 0, 0, n - 1);
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c; b--;
        if (a == 1) {
            update(tree, 0, b, c - num[b], 0, n - 1);
            num[b] = c;
        }
        else cout << sum(tree, 0, b, --c, 0, n - 1) << '\n';
    }
    return 0;
}