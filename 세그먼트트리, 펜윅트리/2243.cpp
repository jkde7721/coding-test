//세그먼트 트리 + 이분 탐색 풀이
//메모리: 10216KB, 시간: 64ms
#include <bits/stdc++.h>
#define MAX 1000000
using namespace std;

int n, a, b, c, flavor;
vector<int> tree;

void update(int node, int s, int e, int idx, int diff) {
    if (idx < s || idx > e) return;
    tree[node] += diff;
    if (s != e) {
        update(node * 2, s, (s + e) / 2, idx, diff);
        update(node * 2 + 1, (s + e) / 2 + 1, e, idx, diff);
    }
}

int getFlavor(int node, int s, int e, int rank) {
    if (s == e) return s;
    if (tree[node * 2] >= rank) return getFlavor(node * 2, s, (s + e) / 2, rank);
    //ex. 현재 구하는 사탕 순위는 10이면서 왼쪽 자식의 순위 총합은 7일 때 오른쪽 자식에서 순위가 3인 사탕 구하기
    else return getFlavor(node * 2 + 1, (s + e) / 2 + 1, e, rank - tree[node * 2]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    tree.resize(pow(2, ceil(log2(MAX)) + 1));
    cin >> n; 
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b; flavor = getFlavor(1, 1, MAX, b);
            cout << flavor << '\n';
            update(1, 1, MAX, flavor, -1);
        }
        else {
            cin >> b >> c; update(1, 1, MAX, b, c);
        }
    }
    return 0;
}

/*
//펜윅 트리 + 이분 탐색 풀이
//메모리: 5928KB, 시간: 68ms
#include <bits/stdc++.h>
using namespace std;

int n, a, b, c, cnt[1000001], flavor;

void update(int idx, int num) {
    while (idx <= 1000000) {
        cnt[idx] += num;
        idx += idx & -idx;
    }
}

int sum(int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += cnt[idx];
        idx -= idx & -idx;
    }
    return ret;
}

int getFlavor(int rank) {
    int l = 1, r = 1000000, mid;
    while (l <= r) {
        mid = (l + r) / 2;
        if (sum(mid) >= rank) r = mid - 1;
        else l = mid + 1;
    }
    return l;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a;
        if (a == 1) {
            cin >> b; flavor = getFlavor(b);
            cout << flavor << '\n';
            update(flavor, -1);
        }
        else { 
            cin >> b >> c; update(b, c); 
        }
    }
    return 0;
}
*/