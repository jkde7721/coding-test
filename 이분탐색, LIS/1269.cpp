//메모리: 3584KB, 시간: 72ms
#include <bits/stdc++.h>
using namespace std;

int n, m, a[200000], b[200000], cnt, ret;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];
    sort(b, b + m);
    for (int i = 0; i < n; i++) {
        if (*lower_bound(b, b + m, a[i]) == a[i]) cnt++;
    }
    ret = (n - cnt) + (m - cnt);
    cout << ret << '\n';

    return 0;
}

//메모리: 20768KB, 시간: 248ms
//map을 이용한 풀이
/*
#include <bits/stdc++.h>
using namespace std;

int n, m, tmp, ret;
map<int, int> _map;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < (n + m); i++) { cin >> tmp; _map[tmp]++; }
    for (auto it : _map) {
        if (it.second == 1) ret++;
    }
    cout << ret << '\n';

    return 0;
}
*/