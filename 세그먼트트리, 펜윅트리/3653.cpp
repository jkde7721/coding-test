//메모리: 3316KB, 시간: 88ms
#include <iostream>
#include <vector>
using namespace std;

int t, n, m, movie;

void update(vector<int>& tree, int idx, int diff) {
    while (idx < tree.size()) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

int sum(vector<int>& tree, int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m;
        vector<int> h(n + 1), tree(n+m+1, 0);
        for (int i = 1; i <= n; i++) {
            update(tree, m + i, 1);
            h[i] = m + i;
        }
        for (int i = m; i >= 1; i--) {
            cin >> movie;
            cout << (sum(tree, h[movie]) - 1) << ' ';
            update(tree, h[movie], -1);
            h[movie] = i;
            update(tree, h[movie], 1);
        }
        cout << '\n';
    }

    return 0;
}