//�޸�: 2060KB, �ð�: 252ms
/*
�Ҽ��� ��°�ڸ����� ǥ���� double�� ������ 100�� ���� �� int������ Ÿ�� ĳ���� ��
�ùٸ� ���� ������ ���� �� ���� ex. 0.29 * 100 �� 28.999999...�� ǥ��
���� ������ ���� ���� ���ؼ� �� ����
*/
#include <bits/stdc++.h>
using namespace std;

//cal �迭: �ε��� �ݾ����� ������ �� �ִ� ���� ���� Į�θ� �� ����
int n, m, c, p, cal[10001];
double tmp;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while (1) {
        memset(cal, 0, sizeof(cal));
        cin >> n >> tmp; m = tmp * 100 + 0.5; //double �� int �� ����
        //�Ǵ� scanf("%d %d.%d", &n, &m1, &m2)�� �Է� ���� �� m = m1 * 100 + m2�� ���
        if (!n && !m) break;

        for (int i = 0; i < n; i++) {
            cin >> c >> tmp; p = tmp * 100 + 0.5;
            for (int j = p; j <= m; j++) {
                cal[j] = max(cal[j], cal[j - p] + c);
            }
        }
        cout << cal[m] << '\n';
    }

    return 0;
}