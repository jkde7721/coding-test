//메모리: 2224KB, 시간: 4ms
#include <bits/stdc++.h>
using namespace std;

int n, ret, s, e, num;
double l;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> l;
    vector<pair<int, int>> v(n);
    for (int i = 0 ; i < n; i++) cin >> v[i].first >> v[i].second;
    sort(v.begin(), v.end());

    for (auto it : v) {
        if (e <= it.first) s = it.first;
        else s = e;
        num = ceil((it.second - s) / l);
        e = s + num * l; ret += num;
    }
    cout << ret << '\n';

    return 0;
}