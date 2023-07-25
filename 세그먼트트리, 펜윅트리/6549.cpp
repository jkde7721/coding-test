//스택 풀이
//메모리: 3744KB, 시간: 36ms
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll n, h, idx, tmp, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while ((cin >> n) && n != 0) {
        stack<pair<ll, ll>> stk; ret = 0;
        for (int i = 0; i <= n; i++) {
            if (i < n) cin >> h;
            else h = -1;
            while (stk.size() && h < stk.top().second) {
                tmp = stk.top().second; stk.pop();
                idx = (stk.empty() ? 0 : stk.top().first + 1);
                ret = max(ret, tmp * (i - idx));
            }
            stk.push({i, h});
        }
        cout << ret << '\n';
    }
    return 0;
}

/*
//세그먼트 트리 + 분할 정복 풀이
//메모리: 8692KB, 시간: 120ms
#include <bits/stdc++.h>
#define INF 1e9 + 1
typedef long long ll;
using namespace std;

int n;
ll h[100001], ret;

void update(vector<int>& t, int node, int s, int e, int idx) {
    if (idx < s || idx > e) return;
    t[node] = (h[t[node]] > h[idx] ? idx : t[node]);
    if (s != e) {
        update(t, node * 2, s, (s + e) / 2, idx);
        update(t, node * 2 + 1, (s + e) / 2 + 1, e, idx);
    }
}

int getMinIdx(vector<int>& t, int node, int s, int e, int l, int r) {
    if (l > e || r < s) return 0;
    if (l <= s && e <= r) return t[node];
    int idx = getMinIdx(t, node * 2, s, (s + e) / 2, l, r), idx2 = getMinIdx(t, node * 2 + 1, (s + e) / 2 + 1, e, l, r);
    return (h[idx] < h[idx2] ? idx : idx2);
}

void go(vector<int>& t, int l, int r) {
    if (l > r) return;
    int idx = getMinIdx(t, 1, 1, n, l, r);
    ret = max(ret, h[idx] * (r - l + 1));
    go(t, l, idx - 1); go(t, idx + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while ((cin >> n) && n != 0) {
        vector<int> tree(pow(2, ceil(log2(n)) + 1), 0); h[0] = INF; ret = 0;
        for (int i = 1; i <= n; i++) {
            cin >> h[i]; update(tree, 1, 1, n, i);
        }
        go(tree, 1, n);
        cout << ret << '\n';
    }
    return 0;
}
*/