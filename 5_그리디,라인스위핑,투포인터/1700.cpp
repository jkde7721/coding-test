//메모리: 2024KB, 시간: 0ms
//optimal algorithm: 멀티탭이 다 찼을 경우 가장 먼 미래에 사용될 전기 용품과 swap
/*
#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int n, k, tmp, ret, idx[MAX];
bool use[MAX];
priority_queue<pair<int, int>> pq, pq2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    vector<pair<int, int>> v(k + 1);
    for (int i = 1; i <= k; i++) {
        cin >> tmp;
        if (idx[tmp] != 0) v[idx[tmp]].first = i;
        idx[tmp] = i;
        v[i] = {MAX, tmp};
    }

    for (int i = 1; i <= k; i++) {
        if (use[v[i].second]) {
            while (pq.size() > 1) { pq2.push(pq.top()); pq.pop(); }
            pq.pop(); pq.swap(pq2); pq.push(v[i]);
            continue;
        }
        if (pq.size() >= n) {
            use[pq.top().second] = 0;
            pq.pop(); ret++;
        }
        pq.push(v[i]); use[v[i].second] = 1;
    }
    cout << ret << '\n';

    return 0;
}
*/

//메모리: 2020KB, 시간: 0ms
//priority_queue 사용하지 않고 vector만으로 풀어보기
#include <iostream>
#include <vector>
#define INF 987654321
using namespace std;

int n, k, ret, a[101];
bool use[101];
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < k; i++) cin >> a[i];
    for (int i = 0; i < k; i++) {
        if (use[a[i]]) continue;
        if (v.size() >= n) {
            int pos = 0, max_idx = 0;
            for (int j = 0; j < v.size(); j++) {
                int here = INF;
                for (int m = i + 1; m < k; m++) {
                    if (v[j] == a[m]) { here = m; break; }
                }
                if (max_idx < here) {
                    max_idx = here;
                    pos = j;
                }
            }
            use[v[pos]] = 0; ret++;
            v.erase(v.begin() + pos);
        }
        v.push_back(a[i]); use[a[i]] = 1;
    }
    cout << ret << '\n';

    return 0;
}