//메모리: 2060KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;

int t, n, cnt[10001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;

    cnt[0] = 1;
    for (int i = 1; i <= 3; i++) {
        for (int j = 1; j <= 10000; j++) {
            if (j - i >= 0) cnt[j] += cnt[j - i];
        }
    }
    while (t--) {
        cin >> n;
        cout << cnt[n] << '\n';
    }

    return 0;
}