//�޸�: 2412KB, �ð�: 12ms
#include <bits/stdc++.h>
using namespace std;

int n, m, lec[100000], l, r, mid, ret = 1000000000;

bool check(int len) {
    int tmp = 0, num = 0;
    for (int i = 0; i < n; i++) {
        tmp += lec[i];
        if (tmp > len) { num++; tmp = lec[i]; }
    }
    return (num + 1) <= m;
}

//�ּ� ��緹�� ũ��=�ִ� ���� ����, �ִ� ��緹�� ũ��=��� ���� ������ ��
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> lec[i];
        l = max(l, lec[i]);
        r += lec[i];
    }
    //��緹�� ũ�⸦ ���� Ž�� (�ִ� 30�� ����)
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