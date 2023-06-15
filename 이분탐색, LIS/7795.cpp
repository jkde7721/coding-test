//메모리: 2176KB, 시간: 28ms
#include <bits/stdc++.h>
using namespace std;

int t, n, m, a[20000], b[20000], ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n >> m; ret = 0;
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < m; i++) cin >> b[i];
        sort(b, b + m);

        //lower_bound: 찾으려는 key 값 이상인 숫자가 배열 몇 번째에 처음 등장하는지를 찾음
        for (int i = 0; i < n; i++) {
            ret += (lower_bound(b, b + m, a[i]) - b);
        }
        cout << ret << '\n';
    }

    return 0;
}