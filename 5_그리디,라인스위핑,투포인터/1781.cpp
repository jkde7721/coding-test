//메모리: 5252KB, 시간: 64ms
//2109 문제와 비슷
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, ret;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(), v.end());
    for (auto it : v) {
        pq.push(it.second);
        if (pq.size() > it.first) pq.pop();
    }
    while (pq.size()) { ret += pq.top(); pq.pop(); }
    cout << ret << '\n';

    return 0;
}