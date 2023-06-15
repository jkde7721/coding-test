//메모리: 17652KB, 시간: 220ms
//동적 배열 + 구간합 → 세그먼트 트리 or 펜윅 트리 사용 
//펜윅 트리(Binary Indexed Tree, BIT) 풀이: 세그먼트 트리에 비해 공간복잡도↓ O(N)
//1의 최하위 비트 연산 필요: (idx & -idx)
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n, m, k, a, b, c;

//최대 logN번 수행
void update(vector<ll>& tree, int node, ll diff) {
    while (node <= n) {
        tree[node] += diff;
        node += (node & -node); 
    }
}

ll sum(vector<ll>& tree, int node) {
    ll ret = 0;
    while (node > 0) {
        ret += tree[node];
        node -= (node & -node);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> k;
    vector<ll> num(n + 1), tree(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
        update(tree, i, num[i]);
    }
    for (int i = 0; i < m + k; i++) {
        cin >> a >> b >> c;
        if (a == 1) {
            update(tree, b, c - num[b]);
            num[b] = c;
        }
        else cout << (sum(tree, c) - sum(tree, b - 1)) << '\n';
    }

    return 0;
}