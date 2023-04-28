//�޸�: 2412KB, �ð�: 16ms
//���� ���� �߰�: �Ϸ翡 �ִ� 1���� ���� ����
#include <bits/stdc++.h>
using namespace std;

int n, m, mon[100000], l, r, mid, ret = 1000000000;

bool check(int k) {
    int tmp = 0, cnt = 1;
    for (int i = 0; i < n; i++) {
        tmp += mon[i];
        if (tmp > k) { cnt++; tmp = mon[i]; }
    }
    return cnt <= m;
}

//�ּ� ���� �ݾ�=�ִ� ���� �ݾ�, �ִ� ���� �ݾ�=��� ���� �ݾ��� ��
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> mon[i];
        l = max(l, mon[i]);
        r += mon[i];
    }
    //���� �ݾ��� �̺� Ž�� (�ִ� 30�� ����)
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid - 1;
            ret = min(ret, mid);
        }
        else l = mid + 1;
    }
    cout << ret << '\n';

    return 0;
}