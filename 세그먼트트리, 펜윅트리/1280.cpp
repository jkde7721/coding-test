//메모리: 5144KB, 시간: 48ms
#include <bits/stdc++.h>
#define MOD 1000000007
#define MAX 200001
using namespace std;
typedef long long ll;

ll n, tmp, cnt[200002], pos[200002], ret = 1;

void update(ll* tree, int idx, int diff) {
    while (idx <= MAX) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

ll sum(ll* tree, int idx) {
    ll ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

//나무 심는 비용: (자기 보다 작은 좌표 개수 * 현재 좌표 - 자기 보다 작은 좌표 합) + (자기 보다 큰 좌표 합 - 자기 보다 큰 좌표 개수 * 현재 좌표)
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tmp; tmp++; //because 0
        update(cnt, tmp, 1); update(pos, tmp, tmp);
        if (i == 0) continue;
        ret *= ((sum(cnt, tmp - 1) * tmp - sum(pos, tmp - 1)) + ((sum(pos, MAX) - sum(pos, tmp)) - (sum(cnt, MAX) - sum(cnt, tmp)) * tmp)) % MOD;
        ret %= MOD;
        if (ret == 0) break;
    }
    cout << ret << '\n';

    return 0;
}