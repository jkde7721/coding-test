/*
īŻ�� ��: y=x�� ���� �ʴ�(�۰ų� ����) ����� ��
����: (2n)! / (n! * n! * (n + 1)) �� n�� �ִ밪�� 30�� ��� 60! ��� �ʿ�, but long long ���� �ʰ�
��ȭ��: Cn = Cn-1*C0 + Cn-2*C1 + ... + C0*Cn-1
*/
/*
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n, cnt[31];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cnt[0] = cnt[1] = 1;
    for (int i = 2; i <= 30; i++) {
        for (int j = 0; j < i; j++) {
            cnt[i] += cnt[i-1-j] * cnt[j];
        }
    }
    while (1) {
        cin >> n;
        if (n == 0) break;
        cout << cnt[n] << '\n';
    }

    return 0;
}
*/

//DP ��� Ǯ��
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//cnt �迭: ���� W �� ��, H �� �� ���� ��Ȳ���� ���� ��������� ���ڿ��� ���� ����
ll cnt[31][31], n;

ll go(int w, int h) {
    if (!w && !h) return 1;
    ll& ret = cnt[w][h];
    if (!ret) {
        if (w > 0) ret += go(w - 1, h + 1); //�� ���� ����  
        if (h > 0) ret += go(w, h - 1); //�� ���� ����
    }
    return ret;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    while ((cin >> n) && n) {
        cout << go(n, 0) << '\n';
    }

    return 0;
}