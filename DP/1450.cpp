//�޸�: 2408KB, �ð�: 4ms
/*
�ð����⵵ 2^30 �� ����Ž�� �Ұ�
�������⵵ 10^9 �� DP �Ұ�
�� 'meet in the middle' �˰���: N�� Ŭ ��, N/2�� ������� ����Ž�� 2�� (�ð����⵵ 2^15 + 2^15)
*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, c, w[30], ret;
vector<int> v, v2; //�� ��� ������ ���� ������ �� ����

void dfs(int l, int r, vector<int> &v, int sum) {
    if (sum > c) return;
    if (l > r) { v.push_back(sum); return; }
    dfs(l + 1, r, v, sum + w[l]);
    dfs(l + 1, r, v, sum);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> c;
    for (int i = 0; i < n; i++) cin >> w[i];
    dfs(0, n / 2 - 1, v, 0);
    dfs(n / 2, n - 1, v2, 0);
    sort(v2.begin(), v2.end());

    for (int s : v) {
        if (c - s >= 0) ret += upper_bound(v2.begin(), v2.end(), c - s) - v2.begin();
    }
    cout << ret << '\n';
    return 0;
}