//메모리: 6252KB, 시간: 44ms
#include <bits/stdc++.h>
using namespace std;

int n, k, id, w, t, cash;
long long ret;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < k; i++) pq.push({0, i});
    for (int i = 0; i < n; i++) {
        cin >> id >> w;
        tie(t, cash) = pq.top(); pq.pop();
        pq.push({t + w, cash});
        pq2.push({t + w, -cash, id});
    }
    for (long long i = 1; i <= n; i++) {
        tie(t, cash, id) = pq2.top(); pq2.pop();
        ret += i * id;
    }
    cout << ret << '\n';

    return 0;
}