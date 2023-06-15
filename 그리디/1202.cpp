//메모리: 7204KB, 시간: 160ms
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;

int n, k, idx;
ll ret;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    vector<pair<int, int>> v(n);
    vector<int> v2(k);

    for (int i = 0; i < n; i++) cin >> v[i].first >> v[i].second;
    for (int i = 0; i < k; i++) cin >> v2[i];
    sort(v.begin(), v.end());
    sort(v2.begin(), v2.end());
    for (int i : v2) {
        while (idx < v.size() && v[idx].first <= i) pq.push(v[idx++].second);
        if (pq.size()) {
            ret += pq.top(); pq.pop();
        }
    }
    cout << ret << '\n';

    return 0;
}