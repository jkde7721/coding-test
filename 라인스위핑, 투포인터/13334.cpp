//메모리: 4196KB, 시간: 40ms
#include <bits/stdc++.h>
using namespace std;

int n, h, o, d, s, e, cnt, ret;
vector<pair<int, int>> v;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h >> o;
        v.push_back({max(h, o), min(h, o)});
    }
    cin >> d;
    sort(v.begin(), v.end()); //도착점을 기준으로 정렬

    for (auto& it : v) {
        if (it.first - it.second > d) continue; //애초에 불가능
        e = it.first; s = e - d; pq.push(it.second); //시작점만 저장
        while (pq.size() && pq.top() < s) pq.pop();
        ret = max(ret, (int)pq.size());
    }
    cout << ret << '\n';
    return 0;
}