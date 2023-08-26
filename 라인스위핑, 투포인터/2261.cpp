//라인스위핑 풀이 (특정 선이나 공간을 한쪽에서부터 쓸어버리는 식의 알고리즘)
//메모리: 3876KB, 시간: 52ms
//참고: https://cocoon1787.tistory.com/480
#include <bits/stdc++.h>
#define INF 10000
using namespace std;

int n, dist, idx;
pair<int, int> pos[100000]; //x좌표 기준으로 정렬
set<pair<int, int>> s; //y좌표 기준으로 정렬

int square(int num) { return num*num; }

int getDist(pair<int, int> p1, pair<int, int> p2) {
    return square(p1.first - p2.first) + square(p1.second - p2.second);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pos[i].first >> pos[i].second;
    sort(pos, pos + n); dist = getDist(pos[0], pos[1]);
    s.insert({pos[0].second, pos[0].first});
    s.insert({pos[1].second, pos[1].first});
    //pos 배열에서 현재 좌표 기준 이전 좌표들과만 거리 계산
    for (int i = 2; i < n; i++) {
        //i가 가리키는 pos의 x좌표는 점점 커지기만 함
        while (idx < i) {
            if (square(pos[idx].first - pos[i].first) <= dist) break;
            else {
                s.erase({pos[idx].second, pos[idx].first});
                idx++;
            }
        }
        //(y좌표 - sqrt(dist)) ~ (y좌표 + sqrt(dist)) 범위의 좌표와만 거리 계산
        auto l = s.lower_bound({pos[i].second - sqrt(dist), -INF});
        auto h = s.upper_bound({pos[i].second + sqrt(dist), INF});
        for (auto it = l; it != h; it++) dist = min(dist, getDist(pos[i], {it->second, it->first})); //x좌표, y좌표 순으로 전달
        s.insert({pos[i].second, pos[i].first});
    }
    cout << dist << '\n';
    return 0;
}

//Closest Pair 알고리즘 (분할정복, O(N * logN * logN) 시간복잡도)
//메모리: 3440KB, 시간: 68ms
/*
#include <bits/stdc++.h>
#define MAX 1e9
using namespace std;

int n;
pair<int, int> pos[100000];

int square(int num) { return num*num; }

int getDist(int i, int j) {
    return square(pos[i].first - pos[j].first) + square(pos[i].second - pos[j].second);
}

int getMinDist(int l, int r) {
    if (l == r) return MAX; //한 점
    if (l + 1 == r) return getDist(l, r); //두 점
    int mid = (l + r) / 2, d; vector<pair<int, int>> v;
    //d는 왼쪽, 오른쪽의 최소 거리 중 최소값
    d = min(getMinDist(l, mid), getMinDist(mid + 1, r));
    if (d == 0) return 0; //ex. 10만개의 모든 점이 같은 좌표인 경우 아래 이중 for문이 O(N^2)으로 동작 → 시간초과 발생

    //왼쪽 점과 오른쪽 점 사이의 거리 계산
    for (int i = l; i <= r; i++) {
        //x좌표 차이의 제곱이 d를 초과하면 해당 점과 다른 쪽 점과의 거리가 최소일 수 없음
        if (square(pos[i].first - pos[mid].first) <= d) v.push_back({pos[i].second, i});
    }
    sort(v.begin(), v.end()); //y좌표 기준으로 정렬
    for (int i = 0; i < v.size(); i++) {
        //실제 아래 for문은 상수 시간 (최대 4번 루프)
        for (int j = i + 1; j < v.size(); j++) {
            if (square(v[i].first - v[j].first) <= d) d = min(d, getDist(v[i].second, v[j].second));
            else break;
        }
    }
    return d;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) cin >> pos[i].first >> pos[i].second;
    sort(pos, pos + n);
    cout << getMinDist(0, n - 1) << '\n';
    return 0;
}
*/