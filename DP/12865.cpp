//�޸�: 2412KB, �ð�: 8ms
//������ �ѹ��� ���� �� �ֱ� ������ �Ϲ����� DP Ǯ��(Top-Down ���)�� �Ұ�
#include <bits/stdc++.h>
using namespace std;

int n, k, w, v, val[100001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> w >> v;
        for (int j = k; j >= w; j--) {
            val[j] = max(val[j], val[j - w] + v);
        }
    }
    cout << val[k] << '\n';

    return 0;
}