//�޸�: 2100KB, �ð�: 4ms
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, m, t[10001], l, r = 30, mid, ret;

//�ش� mnt �ð� �ȿ� ������ ���̰� ���̱ⱸ�� ó�� ���ٸ� ���̱ⱸ ��ȣ ��ȯ
int check(ll mnt) {
    ll tmp = 0;
    for (int i = 1; i <= m; i++) {
        //mnt �ð����� �� �� �¿����� ���
        tmp += ceil((double)mnt / t[i]);
    }
    //������ ���̰� ó�� ���̱ⱸ ������ � ������ ���̱ⱸ�� ������ �𸣱� ������ ��Ž��
    if (tmp >= n) return 0;
    for (int i = 1; i <= m; i++) {
        //�ش� mnt �ð��� ���̱ⱸ�� ��
        if (mnt % t[i] == 0) tmp++;
        if (tmp == n) return i;
    }
    return -1;
}

//������ ���̰� ���̱ⱸ�� Ż ������ �ɸ��� �ð��� �̺� Ž��
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m;
    for (int i = 1; i <= m; i++) { cin >> t[i]; r = min(r, t[i]); }
    r *= (n - 1); //���� �ð��� ���� ª�� ���̱ⱸ�� ��� ���̵��� Ż �������� �ð�
    while (l <= r) {
        mid = (l + r) / 2;
        ret = check(mid);
        if (ret > 0) break; //���̱ⱸ ��ȣ ��ȯ
        else if (ret == 0) r = mid - 1;
        else l = mid + 1;
    }
    cout << ret << '\n';

    return 0;
}