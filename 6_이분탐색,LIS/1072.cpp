//메모리: 2020KB, 시간: 0ms
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x, y, z, ret, l = 1, r = 1e18, mid;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> x >> y;
    z = 100 * y / x;
    //99% 승률에서 100% 승률 만들기 불가능
    if (z >= 99) { cout << "-1\n"; return 0; }
    //최대 60번 루프
    while (l <= r) {
        mid = (l + r) / 2;
        if ((100 * (y + mid) / (x + mid)) != z) {
            ret = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ret << '\n';

    return 0;
}