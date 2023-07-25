//세그먼트 트리 + 분할 정복 풀이
//메모리: 6632KB, 시간: 44ms
#include <bits/stdc++.h>
#define INF 1e9 + 1
using namespace std;

int n, ret, h[100001];
vector<int> tree; //해당 범위에서 최소값을 가진 노드의 인덱스 저장

void update(int node, int s, int e, int idx) {
    if (idx < s || idx > e) return;
    tree[node] = (h[tree[node]] >= h[idx] ? idx : tree[node]);
    if (s != e) {
        update(node * 2, s, (s + e) / 2, idx);
        update(node * 2 + 1, (s + e) / 2 + 1, e, idx);
    }
}

int getMinIdx(int node, int s, int e, int l, int r) {
    if (l > e || r < s) return 0;
    if (l <= s & e <= r) return tree[node];
    int idx = getMinIdx(node * 2, s, (s + e) / 2, l, r), idx2 = getMinIdx(node * 2 + 1, (s + e) / 2 + 1, e, l, r);
    return (h[idx] < h[idx2] ? idx : idx2);
}

void go(int l, int r) {
    if (l > r) return;
    int idx = getMinIdx(1, 1, n, l, r);
    ret = max(ret, h[idx] * (r - l + 1));
    //최소값을 가진 노드를 기준으로 다시 분할
    go(l, idx - 1); go(idx + 1, r);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n; tree.resize(pow(2, ceil(log2(n)) + 1)); h[0] = INF;
    for (int i = 1; i <= n; i++) {
        cin >> h[i]; update(1, 1, n, i);
    }
    go(1, n);
    cout << ret << '\n';
    return 0;
}

/*
//스택 풀이
//메모리: 2944KB, 시간: 12ms
//참고: https://loosie.tistory.com/305
#include <bits/stdc++.h>
using namespace std;

int n, h, ret, idx, tmp;
stack<pair<int, int>> stk; //막대의 높이가 오름차순으로 저장

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i <= n; i++) {
        if (i < n) cin >> h;
        else h = -1; //스택에 남아있는 막대들 처리하기 위해
        //새로운 막대의 높이가 더 작으면 기존 스택에 있는 막대들로 더 이상 직사각형 생성 불가
        while (stk.size() && h < stk.top().second) {
            tmp = stk.top().second; stk.pop();
            idx = (stk.empty() ? 0 : stk.top().first + 1);
            ret = max(ret, tmp * (i - idx));
        }
        stk.push({i, h});
    }
    cout << ret << '\n';
    return 0;
}
*/