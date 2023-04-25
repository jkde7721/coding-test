//메모리: 2804KB, 시간: 8ms
#include <bits/stdc++.h>
using namespace std;

int n, s, tmp, ret = -1000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<int> v(n+1), sum(n+1);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        sum[i] = sum[i-1] + v[i];
    }
    for (int e = 1; e <= n; e++) {
        tmp = sum[e] - sum[s];
        ret = max(ret, tmp);
        if (tmp < 0) s = e;
    }
    cout << ret << '\n';

    return 0;
}