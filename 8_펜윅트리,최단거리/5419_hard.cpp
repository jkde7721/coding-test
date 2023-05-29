//�޸�: 3544KB, �ð�: 344ms
/*
- ���� �ڱ⺸�� x���� �۰ų� �����鼭 y���� ũ�ų� ���� ��ǥ�� ������ count�Ͽ� ret�� �÷���
- ���� x������ �� y��ǥ�� �ִ� ���� ������ tree�� �����ϰ� �������� ������Ʈ
- ���� �ڱ⺸�� x���� �۰ų� �����鼭 y���� ũ�ų� ���� ��ǥ�� ������ tree ���� ������
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, idx;
ll ret;
pair<int, int> land[75000];
vector<int> _y;

ll sum(vector<int>& tree, int node) {
    ll ret = 0;
    while (node > 0) {
        ret += tree[node];
        node -= node & -node;
    }
    return ret;
}

void update(vector<int>& tree, int node, int diff) {
    while (node < tree.size()) {
        tree[node] += diff;
        node += node & -node;
    }
}

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second > b.second;
    return a.first < b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n; _y.clear(); ret = 0;
        for (int i = 0; i < n; i++) {
            cin >> land[i].first >> land[i].second;
            _y.push_back(land[i].second * -1);
        }
        sort(land, land + n, cmp);
        sort(_y.begin(), _y.end());
        _y.erase(unique(_y.begin(), _y.end()), _y.end());
        vector<int> tree(_y.size() + 1); //���� x�������� �ش� y�� �࿡ �ִ� �� ��ǥ ���� ����

        idx = (lower_bound(_y.begin(), _y.end(), land[0].second * -1) - _y.begin()) + 1;
        update(tree, idx, 1);
        for (int i = 1; i < n; i++) {
            idx = (lower_bound(_y.begin(), _y.end(), land[i].second * -1) - _y.begin()) + 1;
            ret += sum(tree, idx); update(tree, idx, 1);
        }
        cout << ret << '\n';
    }

    return 0;
}

//�ٸ� Ǯ�� 
//������ ���⿡ �ִ� ������ ������ count�ϴ� ������� ����
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int t, n, idx;
ll ret;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first) return a.second < b.second;
    return a.first > b.first;
}

void update(vector<int>& tree, int idx, int diff) {
    while (idx < tree.size()) {
        tree[idx] += diff;
        idx += (idx & -idx);
    }
}

int sum(vector<int>& tree, int idx) {
    int ret = 0;
    while (idx > 0) {
        ret += tree[idx];
        idx -= (idx & -idx);
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> t;
    while (t--) {
        cin >> n; ret = 0;
        vector<pair<int, int>> land(n);
        vector<int> _y;
        for (int i = 0; i < n; i++) {
            cin >> land[i].first >> land[i].second;
            _y.push_back(land[i].second);
        }
        sort(land.begin(), land.end(), cmp);
        sort(_y.begin(), _y.end());
        _y.erase(unique(_y.begin(), _y.end()), _y.end());

        vector<int> tree(_y.size() + 1, 0);
        idx = lower_bound(_y.begin(), _y.end(), land[0].second) - _y.begin() + 1;
        update(tree, idx, 1);
        for (int i = 1; i < n; i++) {
            idx = lower_bound(_y.begin(), _y.end(), land[i].second) - _y.begin() + 1;
            ret += sum(tree, idx); update(tree, idx, 1);
        }
        cout << ret << '\n';
    }

    return 0;
}
*/