//�޸�: 2292KB, �ð�: 4ms
/*
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int n, p, d, mx, idx, ret;
vector<pair<int, int>> v;
priority_queue<int> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0 ; i < n; i++) {
        cin >> p >> d;
        v.push_back({d, p});
        mx = max(mx, d);
    }
    sort(v.begin(), v.end(), greater<pair<int, int>>());
    for (int i = mx; i >= 1; i--) {
        while (idx < n && v[idx].first == i) pq.push(v[idx++].second);
        if (pq.size()) {
            ret += pq.top(); pq.pop();
        }
    }
    cout << ret << '\n';

    return 0;
}
*/

//�޸�: 2292KB, �ð�: 4ms
//���� ���� �켱������ �� ���� ť �̿��ؼ� Ǯ���
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n, p, d, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p >> d;
        v.push_back({d, p});
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