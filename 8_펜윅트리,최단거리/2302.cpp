#include <bits/stdc++.h>
using namespace std;

int n, m, ret = 1, pre, cur, cnt[41];

int fibo(int idx) {
    if (cnt[idx] != 0) return cnt[idx];
    cnt[idx] = fibo(idx - 2) + fibo(idx - 1);
    return cnt[idx];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cnt[0] = cnt[1] = 1; fibo(40);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> cur;
        ret *= cnt[cur - pre - 1];
        pre = cur;
    }
    ret *= cnt[n - pre];
    cout << ret << '\n';
    
    return 0;
}