//�޸�: 17652KB, �ð�: 220ms
//���� �迭 + ������ �� ���׸�Ʈ Ʈ�� or ���� Ʈ�� ��� 
//���� Ʈ��(Binary Indexed Tree, BIT) Ǯ��: ���׸�Ʈ Ʈ���� ���� �������⵵�� O(N)
//1�� ������ ��Ʈ ���� �ʿ�: (idx & -idx)
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

ll n, m, k, a, b, c;

//�ִ� logN�� ����
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