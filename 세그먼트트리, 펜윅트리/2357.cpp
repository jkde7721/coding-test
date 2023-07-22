//세그먼트 트리 풀이 (펜윅 트리 풀이도 가능 https://ioinformatics.org/journal/v9_2015_39_44.pdf)
//메모리: 9832KB, 시간: 160ms
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, a, b, mn[1000000], mx[1000000], tmp;

//해당 node의 범위는 s ~ e
void update(int* tree, int node, int s, int e, int idx, int num, bool isMax) {
    if (idx < s || idx > e) return;
    tree[node] = (isMax ? max(tree[node], num) : min(tree[node], num));
    if (s != e) {
        update(tree, node * 2, s, (s + e) / 2, idx, num, isMax);
        update(tree, node * 2 + 1, (s + e) / 2 + 1, e, idx, num, isMax);
    }
}

int getNum(int node, int s, int e, int l, int r, bool isMax) {
    if (l > e || r < s) return (isMax ? 0 : INF);
    if (l <= s && e <= r) return (isMax ? mx[node] : mn[node]);
    int tmp = getNum(node * 2, s, (s + e) / 2, l, r, isMax), tmp2 = getNum(node * 2 + 1, (s + e) / 2 + 1, e, l, r, isMax);
    return (isMax ? max(tmp, tmp2) : min(tmp, tmp2));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    fill(mn, mn + 1000000, INF);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        update(mn, 1, 0, n - 1, i, tmp, false);
        update(mx, 1, 0, n - 1, i, tmp, true);
    }
    for (int i = 0; i < m; i++) {
        cin >> a >> b; a--; b--;
        cout << getNum(1, 0, n - 1, a, b, false) << ' ' << getNum(1, 0, n - 1, a, b, true) << '\n';
    }
    return 0;
}