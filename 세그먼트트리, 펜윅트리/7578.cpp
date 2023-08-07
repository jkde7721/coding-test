//펜윅트리 풀이
//메모리: 7880KB, 시간: 220ms
#include <bits/stdc++.h>
using namespace std;

int n, num, ord[1000001], tree[500001];
long long ret;

void update(int idx, int diff) {
    while (idx <= n) {
        tree[idx] += diff;
        idx += idx & -idx;
    }
}

int sum(int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= idx & -idx;
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> num; ord[num] = i;
    }
    for (int i = 0; i < n; i++) {
        cin >> num;
        ret += i - sum(ord[num]);
        update(ord[num], 1);
    }
    cout << ret << '\n';
    return 0;
}