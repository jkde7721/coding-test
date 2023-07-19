//메모리: 2800KB, 시간: 8ms
#include <bits/stdc++.h>
#define INF 1e9
typedef long long ll;
using namespace std;

int n, s, tmp, st = 1, en, ret = INF;
ll psum[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> s;
    for (int i = 1; i <= n; i++) {
        cin >> tmp; psum[i] = psum[i - 1] + tmp;
    }
    while (st <= n) {
        if (psum[st] - psum[en] >= s) { ret = min(ret, st - en); en++; }
        else st++;
    }
    cout << (ret == INF ? 0 : ret) << '\n';
    return 0;
}