//�޸�: 2032KB, �ð�: 0ms
#include <bits/stdc++.h>
using namespace std;

int n, m, t, x, d, k, crl[51][51], sum, cnt;
bool adj[51][51];
double avg;

void rotateAll(int num, int dir, int k) {
    if (dir == 0) rotate(crl[num], crl[num] + m - k, crl[num] + m);
    else rotate(crl[num], crl[num] + k, crl[num] + m);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    cin >> n >> m >> t; cnt = n*m;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < m; j++) { cin >> crl[i][j]; sum += crl[i][j]; }
    }
    while ((t--) > 0) {
        cin >> x >> d >> k;
        //���� ������
        for (int i = x; i <= n; i += x) rotateAll(i, d, k);
        //������ �� ó��
        memset(adj, 0, sizeof(adj));
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < m; j++) {
                if (crl[i][j] == 0) continue;
                //���� ���� �� ���� ����
                if (crl[i][j] == crl[i][(j-1+m) % m]) adj[i][j] = adj[i][(j-1+m) % m] = 1;
                //���� ���� �� ������ ����
                if (crl[i][j] == crl[i][(j+1) % m]) adj[i][j] = adj[i][(j+1) % m] = 1;
                //�Ʒ� ���� ����
                if (i > 1 && crl[i][j] == crl[i-1][j]) adj[i][j] = adj[i-1][j] = 1;
                //�� ���� ����
                if (i < n && crl[i][j] == crl[i+1][j]) adj[i][j] = adj[i+1][j] = 1;
            }
        }
        //������ ���� ���� ������
        if (accumulate(&adj[0][0], &adj[0][0] + 51*51, 0)) {
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < m; j++) {
                    if (adj[i][j]) {
                        sum -= crl[i][j]; cnt--;
                        crl[i][j] = 0;
                    }
                }
            }
        }
        else {
            if (cnt <= 0) continue;
            avg = double(sum) / cnt;
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < m; j++) {
                    if (crl[i][j] == 0) continue;
                    if (crl[i][j] < avg) { crl[i][j]++; sum++; }
                    else if (crl[i][j] > avg) { crl[i][j]--; sum--; }
                }
            }
        }
    }
    cout << sum << '\n';

    return 0;
}