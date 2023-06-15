//�޸�: 3192KB, �ð�: 68ms
#include <bits/stdc++.h>
using namespace std;

int n, m, l = 1, r, mid, num[300000], ret = 1000000000;

int check(int cnt) {
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        tmp += num[i] / cnt;
        if (num[i] % cnt) tmp++;
    }
    return tmp <= n;
}

//������ ���� ����: [1, �־��� ������ �ִ� ����] �� �� ���� �������� ���� Ž���ϸ� �ּڰ��� ������Ʈ �س���
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < m; i++) { cin >> num[i]; r = max(r, num[i]); }
    //�ִ� 30�� ����
    while (l <= r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            ret = min(ret, mid);
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << ret << '\n';

    return 0;
}